/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define SSD1306OLED

#define USE_SERIAL_PD2

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 27
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#define CATERINA_BOOTLOADER     /* Use caterina bootloader to make RESET keycode available */
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

/* Prefer "hold" when "down -> up -> down" (recognized immediately as "tap twice" by default) */
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

/* Prefer "hold" when "SandS Dn -> A Dn -> A Up -> SandS Up" within the TAPPING_TERM */
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_SHIFT_ONLY

/* Prefer "tap" when "SandS Dn -> A Dn -> Sands Up -> A Up" within the TAPPING_TERM */
/* (Like IGNORE_MOD_TAP_INTERRUPT but only ignores SHIFT) */
#define IGNORE_SHIFT_TAP_INTERRUPT
