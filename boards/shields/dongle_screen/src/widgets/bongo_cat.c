/*
 * Bongo Cat widget for YADS - WPM-driven animation.
 * Modeled on YADS' wpm_status.c: subscribes to zmk_wpm_state_changed and, on
 * each update, selects one of three frames by WPM tier:
 *   tier 0 (idle): wpm < SLOW_LIMIT          -> paws up
 *   tier 1 (slow): SLOW_LIMIT <= wpm < FAST  -> one paw down
 *   tier 2 (fast): wpm >= FAST_LIMIT         -> both paws down
 *
 * The actual frame bitmaps live in bongo_frames.c (generated from PNGs via
 * LVGL's image converter) and are declared extern below.
 */

#include <zephyr/kernel.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include <zmk/event_manager.h>
#include <zmk/events/wpm_state_changed.h>

#include "bongo_cat.h"

/* WPM tier thresholds. Override via Kconfig if desired. */
#ifndef CONFIG_DONGLE_SCREEN_BONGO_SLOW_LIMIT
#define CONFIG_DONGLE_SCREEN_BONGO_SLOW_LIMIT 30
#endif
#ifndef CONFIG_DONGLE_SCREEN_BONGO_FAST_LIMIT
#define CONFIG_DONGLE_SCREEN_BONGO_FAST_LIMIT 60
#endif

/* Frame bitmaps, defined in bongo_frames.c (converted from your PNGs). */
extern const lv_img_dsc_t bongo_idle;
extern const lv_img_dsc_t bongo_slow;
extern const lv_img_dsc_t bongo_fast;

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

struct bongo_state
{
    int wpm;
};

static int wpm_to_tier(int wpm)
{
    if (wpm >= CONFIG_DONGLE_SCREEN_BONGO_FAST_LIMIT)
        return 2;
    if (wpm >= CONFIG_DONGLE_SCREEN_BONGO_SLOW_LIMIT)
        return 1;
    return 0;
}

static struct bongo_state get_state(const zmk_event_t *_eh)
{
    const struct zmk_wpm_state_changed *ev = as_zmk_wpm_state_changed(_eh);
    return (struct bongo_state){.wpm = ev ? ev->state : 0};
}

static void set_frame(struct zmk_widget_bongo_cat *widget, struct bongo_state state)
{
    int tier = wpm_to_tier(state.wpm);
    if (tier == widget->last_tier)
    {
        return; // no change, skip redraw
    }
    widget->last_tier = tier;

    const lv_img_dsc_t *src = &bongo_idle;
    if (tier == 1)
        src = &bongo_slow;
    else if (tier == 2)
        src = &bongo_fast;

    lv_img_set_src(widget->img, src);
    LOG_DBG("Bongo tier %d (wpm=%d)", tier, state.wpm);
}

static void bongo_update_cb(struct bongo_state state)
{
    struct zmk_widget_bongo_cat *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node)
    {
        set_frame(widget, state);
    }
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_bongo_cat, struct bongo_state,
                            bongo_update_cb, get_state)
ZMK_SUBSCRIPTION(widget_bongo_cat, zmk_wpm_state_changed);

int zmk_widget_bongo_cat_init(struct zmk_widget_bongo_cat *widget, lv_obj_t *parent)
{
    widget->obj = lv_obj_create(parent);
    /* Transparent container, no border, sized to the frames (150x100). */
    lv_obj_set_size(widget->obj, 150, 100);
    lv_obj_set_style_bg_opa(widget->obj, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_border_width(widget->obj, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(widget->obj, 0, LV_PART_MAIN);

    widget->img = lv_img_create(widget->obj);
    lv_obj_align(widget->img, LV_ALIGN_CENTER, 0, 0);
    lv_img_set_src(widget->img, &bongo_idle);
    widget->last_tier = 0;

    sys_slist_append(&widgets, &widget->node);
    widget_bongo_cat_init();
    return 0;
}

lv_obj_t *zmk_widget_bongo_cat_obj(struct zmk_widget_bongo_cat *widget)
{
    return widget->obj;
}
