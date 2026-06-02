/*
 * Bongo Cat widget for YADS (color ST7789).
 * WPM-driven: swaps between idle / slow / fast paw frames based on typing speed.
 */

#pragma once

#include <lvgl.h>
#include <zephyr/kernel.h>

struct zmk_widget_bongo_cat
{
    lv_obj_t *obj;
    lv_obj_t *img;   // the cat image; its source is swapped by WPM tier
    int last_tier;   // 0 idle, 1 slow, 2 fast - avoids redundant redraws
    sys_snode_t node;
};

int zmk_widget_bongo_cat_init(struct zmk_widget_bongo_cat *widget, lv_obj_t *parent);
lv_obj_t *zmk_widget_bongo_cat_obj(struct zmk_widget_bongo_cat *widget);
