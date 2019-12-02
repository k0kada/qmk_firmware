#define BLE_NUS_MIN_INTERVAL 30
#define BLE_NUS_MAX_INTERVAL 50
#define BLE_HID_MAX_INTERVAL 60
#define BLE_HID_SLAVE_LATENCY 4

#define PREVENT_STUCK_MODIFIERS /* Auto-restore layer when the layer key is released */
#define MOUSEKEY_DELAY             32
#define MOUSEKEY_INTERVAL          16
#define MOUSEKEY_MOVE_DELTA        3
#define MOUSEKEY_MAX_SPEED         9 /* times faster than MOVE_DELTA */
#define MOUSEKEY_TIME_TO_MAX       10

#define MOUSEKEY_WHEEL_DELAY       48
#define MOUSEKEY_WHEEL_INTERVAL    48
#define MOUSEKEY_WHEEL_DELTA       1
#define MOUSEKEY_WHEEL_MAX_SPEED   1 /* times faster */
#define MOUSEKEY_WHEEL_TIME_TO_MAX 1

// 変換・無変換
/* Prefer "hold" when "down -> up -> down" (recognized immediately as "tap twice" by default) */
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200
/* Prefer "hold" when "SandS Dn -> A Dn -> A Up -> SandS Up" within the TAPPING_TERM */
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_SHIFT_ONLY
/* Prefer "tap" when "SandS Dn -> A Dn -> Sands Up -> A Up" within the TAPPING_TERM */
/* (Like IGNORE_MOD_TAP_INTERRUPT but only ignores SHIFT) */
#define IGNORE_SHIFT_TAP_INTERRUPT
