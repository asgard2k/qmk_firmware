/* Copyright 2019 eswai
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include"keymap.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUNCS,
    _S_LOWER,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  // Layer keycodes
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  FUNCS,
  S_LOWER,	
  // Custom keycodes
  RGBRST,
  MACRO_1,
  MACRO_2
};

// Tap dance
enum {
  FUNC
};


#define _____   KC_TRNS
#define XXXXX   KC_NO
#define KFUNC   TD(FUNC)

#define MACRO_VAL_1			"April13@@"
#define MACRO_VAL_2			"16thMarch$"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* Base */
    LT(_RAISE,KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,            MO(_ADJUST), KC_PSCR,        KC_Y,               KC_U,               KC_I,            KC_O,           KC_P,            KC_ESC, \
    LT(_FUNCS,KC_BSPC), KC_A,    KC_S,    KC_D,    KC_F,       KC_G,            KC_PGUP,     KC_HOME,        KC_H,               KC_J,               KC_K,            KC_L,           KC_SCLN,         RSFT_T(KC_ENT), \
    KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,            KC_PGDN,     KC_END,         KC_N,               KC_M,               RALT_T(KC_COMM), RGUI_T(KC_DOT), RCTL_T(KC_SLSH), MT(MOD_RSFT,KC_QUOT), \
    KC_LCTL,            KC_LGUI, KC_LALT, KC_CAPS, KFUNC,      KC_BSPC,         KC_INS,      KC_DEL,         LT(_RAISE,KC_SPC),  LCTL(LSFT(KC_ESC)), KC_LEFT,         KC_DOWN,        KC_RGHT,         KC_UP  \
  ),


  [_RAISE] = LAYOUT( \
     _____,          LALT(KC_F4),  _____,         _____,         _____,  _____,  RGB_TOG,  _____,  KC_ESC,        KC_PGUP,      KC_UP,   KC_PGDN, _______,  KC_DEL,\
     LCTL(KC_BSPC),  _____,        LCTL(KC_DEL),  KC_DEL,        _____,  _____,  _____,    _____,  KC_HOME,       KC_LEFT,      KC_DOWN, KC_RGHT, KC_END,   _____,\
     _____,          _____,        _____,         _____,         _____,  _____,  _____,    _____,  MO(_ADJUST),   LSFT(KC_F10), _____,   _____,   _____,    _____,\
     _____,          _____,        _____,         _____,         _____,  _____,  _____,    _____,  _____,         _____,        _____,   _____,   _____,    _____ \
  ),

  [_LOWER] = LAYOUT( \
     KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   _____,  _____,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_DEL,\
     KC_LSFT,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,   _____,   _____,   KC_LBRC, KC_RBRC,  KC_RSFT,\
     KC_LSFT,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_BSLS,  KC_RSFT,\
     _____,    _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,   _____,   _____,   _____,   _____,    _____ \
  ),

  [_ADJUST] = LAYOUT( \
    _____,  RESET,  _____,  _____,  _____,  _____,  _____,  _____, _____,  _____,  _____,    _____,   RGB_M_P,  RGB_TOG,\
    _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____, _____,  _____,  _____,    _____,   RGB_HUD,  RGB_HUI,\
    _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____, _____,  _____,  _____,    _____,   RGB_SAD,  RGB_SAI,\
    _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____, _____,  _____,  RGB_RMOD, RGB_MOD, RGB_VAD,  RGB_VAI \
  ),

  [_FUNCS] = LAYOUT( \
     LCA(KC_DEL),  KC_F1,    KC_F2,  KC_F3,  KC_F4,  KC_F5,  _____,  _____,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,\
     _____,        MACRO_1,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  KC_F12,\
     _____,        MACRO_2,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  KC_INS,\
     _____,        _____,    _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  KC_PSCR \
  ),

  [_S_LOWER] = LAYOUT( \
     KC_TILD,  KC_EXLM,  KC_AT,  KC_HASH,  KC_DLR,  KC_PERC,  _____,  _____,  KC_CIRC,  KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,\
     _____,    _____,    _____,  _____,    _____,   _____,    _____,  _____,  _____,    _____,    _____,   KC_LCBR, KC_RCBR,  _____,\
     _____,    _____,    _____,  _____,    _____,   _____,    _____,  _____,  _____,    _____,    KC_UNDS, KC_PLUS, KC_PIPE,  _____,\
     _____,    _____,    _____,  _____,    _____,   _____,    _____,  _____,  _____,    _____,    _____,   _____,   _____,    _____ \
  ),

};

qk_tap_dance_action_t tap_dance_actions[] = {
 [FUNC] = ACTION_TAP_DANCE_DOUBLE (LOWER, S_LOWER)
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void update_led(void);

void update_led() {
  // if (layer_state_is(_NUMPAD)) {
    // rgblight_setrgb_at(5, 5, 20, 3);
  // }
  // if (layer_state_is(_NUMPAD) || layer_state_is(_LOWER)) {
    // rgblight_setrgb_at(5, 5, 20, 37);
    // rgblight_setrgb_at(5, 5, 20, 38);
    // rgblight_setrgb_at(5, 5, 20, 39);
    // rgblight_setrgb_at(5, 5, 20, 40);
    // rgblight_setrgb_at(5, 5, 20, 41);
    // rgblight_setrgb_at(5, 5, 20, 42);
    // rgblight_setrgb_at(5, 5, 20, 45);
    // rgblight_setrgb_at(5, 5, 20, 46);
    // rgblight_setrgb_at(5, 5, 20, 47);
  // }
  // if (layer_state_is(_RAISE)) {
    // rgblight_setrgb_at(15, 2, 5, 38);
    // rgblight_setrgb_at(15, 2, 5, 40);
    // rgblight_setrgb_at(15, 2, 5, 41);
    // rgblight_setrgb_at(15, 2, 5, 46);
  // }
  // if (!layer_state_is(_NUMPAD) && !layer_state_is(_LOWER) && !layer_state_is(_RAISE)) {
    // rgblight_setrgb_range(0, 0, 0, 0, 55);
  // }
  // if (is_nicola) {
    // rgblight_setrgb_range(10, 10, 10, 56, 71);
  // } else {
    // rgblight_setrgb_range(0, 0, 0, 56, 71);
  // }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    // case LOWER:
      // if (record->event.pressed) {
        // layer_on(_LOWER);
      // } else {
        // layer_off(_LOWER);
      // }
      // return false;
      // break;
    // case S_LOWER:
      // if (record->event.pressed) {
        // layer_on(_S_LOWER);
      // } else {
        // layer_off(_S_LOWER);
      // }
      // return false;
      // break;
    case RGBRST:
      if (record->event.pressed) {
        eeconfig_update_rgblight_default();
        rgblight_enable();
      }
      return false;
      break;
    case MACRO_1:
      if (record->event.pressed) {
        SEND_STRING(MACRO_VAL_1);
      }
      return false;
      break;    
    case MACRO_2:
      if (record->event.pressed) {
        SEND_STRING(MACRO_VAL_2);
      }
      return false;
      break;    
    default:
      break;
  }

  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
