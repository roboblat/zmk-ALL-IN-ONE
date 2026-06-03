Run west build -s zmk/app -d "/tmp/tmp.Vmop7mqLsK" -b "xiao_ble//zmk" -S "studio-rpc-usb-uart" -- -DZMK_CONFIG=/tmp/zmk-config/config -DSHIELD="ergo_dongle dongle_screen" -DZMK_EXTRA_MODULES='/__w/zmk-ALL-IN-ONE/zmk-ALL-IN-ONE' 
+ west build -s zmk/app -d /tmp/tmp.Vmop7mqLsK -b xiao_ble//zmk -S studio-rpc-usb-uart -- -DZMK_CONFIG=/tmp/zmk-config/config -DSHIELD=ergo_dongle dongle_screen -DZMK_EXTRA_MODULES=/__w/zmk-ALL-IN-ONE/zmk-ALL-IN-ONE
-- west build: generating a build system
Loading Zephyr default modules (Zephyr base).
-- Application: /tmp/zmk-config/zmk/app
-- CMake version: 3.31.6
-- Found Python3: /usr/bin/python3 (found suitable version "3.12.3", minimum required is "3.10") found components: Interpreter
-- Cache files will be written to: /tmp/zmk-config/zephyr/.cache
-- Zephyr version: 4.1.0 (/tmp/zmk-config/zephyr)
-- Found west (found suitable version "1.5.0", minimum required is "0.14.0")
-- Board: xiao_ble, qualifiers: nrf52840/zmk
-- Shield(s): ergo_dongle dongle_screen
Checking /tmp/zmk-config/zmk/app/module
Checking /__w/zmk-ALL-IN-ONE/zmk-ALL-IN-ONE
Checking /tmp/zmk-config/zmk/app
found /tmp/zmk-config/zmk/app
-- ZMK Config directory: /tmp/zmk-config/config
-- ZMK Config Kconfig: /tmp/zmk-config/config/ergo_dongle.conf
-- ZMK Config Kconfig: /tmp/zmk-config/config/ergo.conf
xiao_ble_nrf52840_zmk for _nrf52840_zmk for xiao_ble with version 
-- ZMK Config Kconfig: /tmp/zmk-config/config/ergo_dongle.conf
-- Using keymap file: /__w/zmk-ALL-IN-ONE/zmk-ALL-IN-ONE/boards/shields/ergo_dongle/ergo_dongle.keymap
Checking /tmp/zmk-config/zephyr
-- Snippet(s): studio-rpc-usb-uart
-- ZEPHYR_TOOLCHAIN_VARIANT not set, trying to locate Zephyr SDK
-- Found host-tools: zephyr 0.16.9 (/opt/zephyr-sdk-0.16.9)
-- Found toolchain: zephyr 0.16.9 (/opt/zephyr-sdk-0.16.9)
-- Found Dtc: /opt/zephyr-sdk-0.16.9/sysroots/x86_64-pokysdk-linux/usr/bin/dtc (found suitable version "1.6.0", minimum required is "1.4.6")
-- Found BOARD.dts: /tmp/zmk-config/zmk/app/boards/seeed/xiao_ble/xiao_ble_zmk.dts
-- Found devicetree overlay: /__w/zmk-ALL-IN-ONE/zmk-ALL-IN-ONE/boards/shields/ergo_dongle/ergo_dongle.overlay
-- Found devicetree overlay: /__w/zmk-ALL-IN-ONE/zmk-ALL-IN-ONE/boards/shields/dongle_screen/dongle_screen.overlay
-- Found devicetree overlay: /__w/zmk-ALL-IN-ONE/zmk-ALL-IN-ONE/boards/shields/dongle_screen/boards/xiao_ble_zmk.overlay
-- Found devicetree overlay: /__w/zmk-ALL-IN-ONE/zmk-ALL-IN-ONE/boards/shields/ergo_dongle/ergo_dongle.keymap
-- Found devicetree overlay: /tmp/zmk-config/zmk/app/snippets/studio-rpc-usb-uart/studio-rpc-usb-uart.overlay
devicetree error: /__w/zmk-ALL-IN-ONE/zmk-ALL-IN-ONE/boards/shields/ergo_dongle/ergo_dongle.overlay:29 (column 13): parse error: malformed value
CMake Error at /tmp/zmk-config/zephyr/cmake/modules/dts.cmake:303 (execute_process):
  execute_process failed command indexes:

    1: "Child return code: 1"

Call Stack (most recent call first):
  /tmp/zmk-config/zephyr/cmake/modules/zephyr_default.cmake:134 (include)
  /tmp/zmk-config/zephyr/share/zephyr-package/cmake/ZephyrConfig.cmake:66 (include)
  /tmp/zmk-config/zephyr/share/zephyr-package/cmake/ZephyrConfig.cmake:92 (include_boilerplate)
  CMakeLists.txt:9 (find_package)


-- Configuring incomplete, errors occurred!
FATAL ERROR: command exited with status 1: /usr/local/bin/cmake -DWEST_PYTHON=/usr/bin/python3 -B/tmp/tmp.Vmop7mqLsK -GNinja -DBOARD=xiao_ble//zmk -DZMK_CONFIG=/tmp/zmk-config/config '-DSHIELD=ergo_dongle dongle_screen' -DZMK_EXTRA_MODULES=/__w/zmk-ALL-IN-ONE/zmk-ALL-IN-ONE -DSNIPPET=studio-rpc-usb-uart -S/tmp/zmk-config/zmk/app
Error: Process completed with exit code 1.
