/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define MOUSE    5
#define WHEEL    6

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};


#include QMK_KEYBOARD_H

#define KC___ KC_TRNS
#define KC_XX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_CTLTB CTL_T(KC_TAB)

/* layers */
#define KC_D_MOUS LT(MOUSE, KC_D)
#define KC_WEEL   MO(WHEEL)

/* aliases */
#define KC_MUP  KC_MS_U
#define KC_MDN  KC_MS_D
#define KC_MLFT KC_MS_L
#define KC_MRGT KC_MS_R
#define KC_WUP  KC_WH_U
#define KC_WDN  KC_WH_D
#define KC_WLFT KC_WH_L
#define KC_WRGT KC_WH_R

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                   KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
   KC_CTLTB,  KC_A,  KC_S,KC_D_MOUS,KC_F, KC_G,                   KC_H,  KC_J,  KC_K,  KC_L,KC_SCLN,KC_QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                   KC_N,  KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LGUI, LOWER,KC_SPC,   KC_ENT, RAISE,KC_RALT \
                              //`--------------------'  `--------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC___,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                   KC_6,  KC_7,  KC_8,  KC_9,  KC_0,KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC___, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_XX,KC_XX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC___, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,                  KC_XX, KC_XX, KC_XX, KC_XX, KC_XX, KC_XX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC___, KC___, KC___,    KC___, KC___, KC___ \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC___, KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,              KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC___, KC_XX, KC_XX, KC_XX, KC_XX, KC_XX,               KC_MINS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE,KC_GRV,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC___, KC_XX, KC_XX, KC_XX, KC_XX, KC_XX,               KC_UNDS,KC_EQL,KC_LBRC,KC_RBRC,KC_BSLS,KC_TILD,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC___, KC___, KC___,    KC___, KC___, KC___ \
                              //`--------------------'  `--------------------'
  ),

   [MOUSE] = LAYOUT( \
   //,-----------------------------------------.                ,-----------------------------------------.
      KC_XX, KC_XX, KC_XX, KC_XX, KC_XX, KC_XX,                  KC_XX, KC_XX, KC_XX, KC_XX, KC_XX, KC_XX,
   //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_XX, KC_XX,KC_WEEL,KC_XX,KC_BTN1,KC_BTN2,                KC_MLFT,KC_MDN,KC_MUP,KC_MRGT, KC_XX, KC_XX,\
   //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_XX, KC_XX, KC_XX, KC_XX, KC_XX, KC_XX,                  KC_XX, KC_XX, KC_XX, KC_XX, KC_XX, KC_XX,
   //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC___, KC___, KC___,    KC___, KC___, KC___ \
                               //`--------------------'  `--------------------'
   ),

   [WHEEL] = LAYOUT( \
   //,-----------------------------------------.                ,-----------------------------------------.
      KC_XX, KC_XX, KC_XX, KC_XX, KC_XX, KC_XX,                  KC_XX, KC_XX, KC_XX, KC_XX, KC_XX, KC_XX,
   //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_XX, KC_XX, KC_XX, KC_XX, KC_XX, KC_XX,                KC_WLFT,KC_WDN,KC_WUP,KC_WRGT, KC_XX, KC_XX,
   //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_XX, KC_XX, KC_XX, KC_XX, KC_XX, KC_XX,                  KC_XX, KC_XX, KC_XX, KC_XX, KC_XX, KC_XX,
   //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC___, KC___, KC___,    KC___, KC___, KC___ \
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      RESET,RGBRST, KC_XX, KC_XX, KC_XX, KC_XX,                  KC_XX, KC_XX, KC_XX, KC_XX, KC_XX, KC_XX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    RGB_TOG,RGB_HUI,RGB_SAI,RGB_VAI,KC_XX,KC_XX,               KC_MUTE,KC_VOLD,KC_VOLU,KC_MPLY,KC_MNXT,KC_MPRV,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,KC_XX,KC_XX,                 KC_XX, KC_XX, KC_XX, KC_XX, KC_XX, KC_XX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC___, KC___, KC___,    KC___, KC___, KC___ \
                              //`--------------------'  `--------------------'
  )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

static bool lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool raise_pressed = false;
static uint16_t raise_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        lower_pressed_time = record->event.time;

        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);

        if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM)) {
          register_code(KC_LANG2); // for macOS
          register_code(KC_MHEN);
          unregister_code(KC_MHEN);
          unregister_code(KC_LANG2);
        }
        lower_pressed = false;
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        raise_pressed_time = record->event.time;

        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);

        if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM)) {
          register_code(KC_LANG1); // for macOS
          register_code(KC_HENK);
          unregister_code(KC_HENK);
          unregister_code(KC_LANG1);
        }
        raise_pressed = false;
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;

    default:
      if (record->event.pressed) {
        // reset the flags
        lower_pressed = false;
        raise_pressed = false;
      }
      break;
  }
  return true;
}
