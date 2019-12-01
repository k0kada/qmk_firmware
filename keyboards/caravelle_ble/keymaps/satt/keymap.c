/*
Copyright 2019 Sekigon

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

#include QMK_KEYBOARD_H
#include "keymap_jis2us.h"
#include "action_pseudo_lut.h"
#include "keymap_jp.h"
#include "app_ble_func.h"
#include <stdio.h>

enum custom_keycodes {
    AD_WO_L = SAFE_RANGE, /* Start advertising without whitelist  */
    BLE_DIS,              /* Disable BLE HID sending              */
    BLE_EN,               /* Enable BLE HID sending               */
    USB_DIS,              /* Disable USB HID sending              */
    USB_EN,               /* Enable USB HID sending               */
    DELBNDS,              /* Delete all bonding                   */
    ADV_ID0,              /* Start advertising to PeerID 0        */
    ADV_ID1,              /* Start advertising to PeerID 1        */
    ADV_ID2,              /* Start advertising to PeerID 2        */
    ADV_ID3,              /* Start advertising to PeerID 3        */
    ADV_ID4,              /* Start advertising to PeerID 4        */
    BATT_LV,              /* Display battery level in milli volts */
    DEL_ID0,              /* Delete bonding of PeerID 0           */
    DEL_ID1,              /* Delete bonding of PeerID 1           */
    DEL_ID2,              /* Delete bonding of PeerID 2           */
    DEL_ID3,              /* Delete bonding of PeerID 3           */
    DEL_ID4,              /* Delete bonding of PeerID 4           */
    ENT_DFU,              /* Start bootloader                     */
    ENT_SLP,              /* Deep sleep mode                      */
    JIS2US,               /* JIS2US keycode                       */
    LOWER,                /* Layer  keycode                       */
    RAISE,                /* Layer  keycode                       */
    P_LOWER,              /* Layer  keycode                       */
    P_RAISE,              /* Layer  keycode                       */
};


extern keymap_config_t keymap_config;

enum {
  _QWERTY,
  _LOWER,
  _RAISE,
  _PSEUDO_US,
  _PSEUDO_US_LOWER,
  _PSEUDO_US_RAISE,
  _ADJUST,
  _MOUSE,
  _WHEEL
};

// Layer related keycodes
#define QWERTY DF(_QWERTY)
#define PSEU_US DF(_PSEUDO_US) // 擬似US?
#define ADJUST  MO(_ADJUST)
#define MOUSE DF(_MOUSE)
#define WHEEL DE(_WHEEL)

// Special keycodes
#define SPC_CTL CTL_T(KC_SPC)
#define ENT_SFT SFT_T(KC_ENT)
#define TB_CTSF C_S_T(KC_TAB) // Left Control and Shift when held, kc when tapped
#define IMON_AL ALT_T(KC_F13) // 長押しで Alt 、タップで kc
#define IMOF_AL ALT_T(KC_F14)
#define CTALDEL LCA(KC_DEL)
#define ESC_ADJ LT(_ADJUST, KC_ESC)
#define KC_D_MOUS LT(_MOUSE, KC_D)
#define KC_WHEEL  MO(_WHEEL)

/* aliases */
#define KC_MUP  KC_MS_U
#define KC_MDN  KC_MS_D
#define KC_MLFT KC_MS_L
#define KC_MRGT KC_MS_R
#define KC_WUP  KC_WH_U
#define KC_WDN  KC_WH_D
#define KC_WLFT KC_WH_L
#define KC_WRGT KC_WH_R

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC___ KC_TRNS
#define KC_XX KC_NO

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
    ESC_ADJ, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    TB_CTSF, KC_A,    KC_S,    KC_D_MOUS, KC_F,  KC_G,    KC_LPRN,        KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,        KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
 //                            長押しAlt,F13                                              長押しSFT, ENT   長押しALT,F1
                               IMOF_AL, KC_LGUI, LOWER,   KC_SPC,        KC_ENT,   RAISE,   IMON_AL, KC_LGUI \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  ),

  [_LOWER] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,         _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_XX,   KC_XX,   \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,         KC_TILD, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               _______, _______, _______, _______,        _______, _______, _______, _______ \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  ),

  [_RAISE] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
     KC___,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC___,   \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
     KC___,  KC_XX,   KC_XX,   KC_XX,   KC_XX,    KC_XX,  KC___,          KC___,   KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV,  \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
     KC___,  KC_XX,   KC_XX,   KC_XX,   KC_XX,    KC_XX,  KC___,          KC___,   KC_UNDS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
                               _______, _______, _______, _______,        _______, _______, _______, _______ \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  ),

   [_MOUSE] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
      KC_XX, KC_XX,   KC_XX,   KC_XX,   KC_XX,   KC_XX,                            KC_XX,   KC_XX,   KC_XX,   KC_XX,   KC_XX,   KC_XX,   \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
      KC_XX, KC_XX,   KC_WHEEL, KC_XX,  KC_BTN1, KC_BTN2, KC_XX,          KC_HOME, KC_MLFT, KC_MDN,  KC_MUP,  KC_MRGT, KC_XX,   KC_XX,   \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
      KC_XX, KC_XX,   KC_XX,   KC_XX,   KC_XX,   KC_XX,   KC_XX,          KC_END,  KC_XX,   KC_XX,    KC_XX,  KC_XX,   KC_XX,   KC_XX,   \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
                               KC___,   KC___,   KC___,   KC___,          KC___,   KC___,   KC___,    KC___  \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
   ),

   [_WHEEL] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
      KC_XX, KC_XX,   KC_XX,   KC_XX,   KC_XX,   KC_XX,                            KC_XX,   KC_XX,   KC_XX,   KC_XX,   KC_XX,   KC_XX,   \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
      KC_XX, KC_XX,   KC_XX,   KC_XX,   KC_XX,   KC_XX,   KC_XX,          KC_HOME, KC_WLFT, KC_WDN,  KC_WUP,  KC_WRGT, KC_XX,   KC_XX,   \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
      KC_XX, KC_XX,   KC_XX,   KC_XX,   KC_XX,   KC_XX,   KC_XX,          KC_END,  KC_XX,   KC_XX,    KC_XX,  KC_XX,   KC_XX,   KC_XX,   \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
                               KC___,   KC___,   KC___,   KC___,          KC___,   KC___,   KC___,    KC___  \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
   ),

  [_PSEUDO_US] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
    ESC_ADJ, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    TB_CTSF, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    JP_LPRN,        JP_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    JIS2US,  KC_BSPC, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
 //                                                       JISをUSに切替
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    JIS2US,         JIS2US,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, JIS2US,  \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               KC_LGUI, IMOF_AL, P_LOWER, SPC_CTL,        ENT_SFT, P_RAISE, IMON_AL, KC_LGUI \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  ),

  [_PSEUDO_US_LOWER] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
    _______, JP_EXLM, JP_AT,   JP_HASH, JP_DLR,  JP_PERC,                          JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, _______, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          JP_GRV,  JP_BSLS, JP_MINS, JP_EQL,  JP_LBRC, JP_RBRC, _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,         JP_TILD, JP_PIPE, JP_UNDS, JP_PLUS, JP_LCBR, JP_RCBR, _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               _______, _______, _______, _______,        _______, _______, _______, _______ \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  ),

  [_PSEUDO_US_RAISE] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
 //                                                       JISで変換
    _______, _______, _______, _______, _______, _______, JP_ZHTG,        XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______,        KC_HOME, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               _______, _______, _______, _______,        _______, _______, _______, _______ \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  ),

  [_ADJUST] = LAYOUT ( \
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
    _______, AD_WO_L, ADV_ID1, ADV_ID2, ADV_ID3, ADV_ID4,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    _______, DELBNDS, DEL_ID1, DEL_ID2, DEL_ID3, DEL_ID4, QWERTY,         XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, KC_MPRV, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, BATT_LV, ENT_SLP, ENT_DFU, RESET,   CTALDEL, PSEU_US,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               _______, _______, _______, _______,        _______, _______, _______, _______ \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  )
};

// 変換・無変換
static bool lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool raise_pressed = false;
static uint16_t raise_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  char str[16];
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        lower_pressed_time = record->event.time;

        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM)) {
          register_code(KC_LANG2); // for macOS
          register_code(KC_MHEN);
          unregister_code(KC_MHEN);
          unregister_code(KC_LANG2);
        }
        lower_pressed = false;
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        raise_pressed_time = record->event.time;

        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM)) {
          register_code(KC_LANG1); // for macOS
          register_code(KC_HENK);
          unregister_code(KC_HENK);
          unregister_code(KC_LANG1);
        }
        raise_pressed = false;
      }
      return false;
      break;
    case P_LOWER:
      if (record->event.pressed) {
        layer_on(_PSEUDO_US_LOWER);
        update_tri_layer(_PSEUDO_US_LOWER, _PSEUDO_US_RAISE, _ADJUST);
      } else {
        layer_off(_PSEUDO_US_LOWER);
        update_tri_layer(_PSEUDO_US_LOWER, _PSEUDO_US_RAISE, _ADJUST);
      }
      return false;
      break;
    case P_RAISE:
      if (record->event.pressed) {
        layer_on(_PSEUDO_US_RAISE);
        update_tri_layer(_PSEUDO_US_LOWER, _PSEUDO_US_RAISE, _ADJUST);
      } else {
        layer_off(_PSEUDO_US_RAISE);
        update_tri_layer(_PSEUDO_US_LOWER, _PSEUDO_US_RAISE, _ADJUST);
      }
      return false;
      break;
    case JIS2US:
      action_pseudo_lut(record, _QWERTY, keymap_jis2us);
      return false;
      break;

    default:
      if (record->event.pressed) {
        // reset the flags
        lower_pressed = false;
        raise_pressed = false;
      }
      break;
  }
  if (record->event.pressed) {
    switch (keycode) {
    case DELBNDS:
      delete_bonds();
      return false;
    case AD_WO_L:
      restart_advertising_wo_whitelist();
      return false;
    case USB_EN:
      set_usb_enabled(true);
      return false;
      break;
    case USB_DIS:
      set_usb_enabled(false);
      return false;
      break;
    case BLE_EN:
      set_ble_enabled(true);
      return false;
      break;
    case BLE_DIS:
      set_ble_enabled(false);
      return false;
      break;
    case ADV_ID0:
      restart_advertising_id(0);
      return false;
    case ADV_ID1:
      restart_advertising_id(1);
      return false;
    case ADV_ID2:
      restart_advertising_id(2);
      return false;
    case ADV_ID3:
      restart_advertising_id(3);
      return false;
    case ADV_ID4:
      restart_advertising_id(4);
      return false;
    case DEL_ID0:
      delete_bond_id(0);
      return false;
    case DEL_ID1:
      delete_bond_id(1);
      return false;
    case DEL_ID2:
      delete_bond_id(2);
      return false;
    case DEL_ID3:
      delete_bond_id(3);
      return false;
    case BATT_LV:
      sprintf(str, "%4dmV", get_vcc());
      send_string(str);
      return false;
    case ENT_DFU:
      bootloader_jump();
      return false;
    }
  }
  else if (!record->event.pressed) {
    switch (keycode) {
    case ENT_SLP:
      sleep_mode_enter();
      return false;
    }

  }
  return true;
}
;
