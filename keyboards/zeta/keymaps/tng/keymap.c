#include "zeta.h"
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUNCTIONS,
    _MOUSE,
    _NUMBERS,
    _NUMBERS_LHALF, 
    // Moved these to bottom so the other layers can tap-hold to them 
    _COLEMAK,
    _DVORAK,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  FUNCTIONS,
  NUMBERS
};


// Fillers to make layering more clear
#define XXXXXXX KC_NO
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,          KC_Q,    KC_W,    KC_E,                    KC_R,              KC_T,                               KC_Y,              KC_U,                    KC_I,                           KC_O,           KC_P,            KC_ESC, \
  KC_LSFT,         KC_A,    KC_S,    KC_D,                    LT(_RAISE,KC_F),   KC_G,                               KC_H,              KC_J,                    KC_K,                           KC_L,           KC_SCLN,         RSFT_T(KC_ENT), \
  KC_LSFT,         KC_Z,    KC_X,    KC_C,                    KC_V,              KC_B,                               KC_N,              KC_M,                    RALT_T(KC_COMM),                RGUI_T(KC_DOT), RCTL_T(KC_SLSH), KC_QUOT, \
  KC_LCTL,         KC_LGUI, KC_LALT, MO(_NUMBERS),            MO(_LOWER),        LT(_FUNCTIONS,KC_BSPC),             LT(_RAISE,KC_SPC), MO(_FUNCTIONS),          MO(_NUMBERS),                   KC_RALT,        KC_RGUI,         KC_RCTL \
),
              
[_LOWER] =  LAYOUT_ortho_4x12( \
  KC_ESC,  LALT(KC_F4), _______, LALT(KC_LEFT), LALT(KC_RIGHT), LCTL(LSFT(KC_ESC)),                 _______, _______, _______, KC_LCBR, KC_RCBR, _______, \
  _______, _______,     _______, LCTL(KC_PGUP), LCTL(KC_PGDN),  _______,                            _______, KC_LT  , KC_GT  , KC_LBRC, KC_RBRC, _______, \
  _______, _______,     _______, _______,       _______,        _______,                            KC_LPRN, KC_RPRN, KC_MINS, KC_EQL , KC_BSLS, _______, \
  _______, _______,     _______, _______,       _______,        _______,                            KC_SPC,  KC_SPC,  _______,  _______, _______, _______ \
),

[_RAISE] =  LAYOUT_ortho_4x12( \
  KC_GRV,  _______,       _______,      _______,       _______, _______,                 _______,     KC_PGUP,      KC_UP,   KC_PGDN, _______, KC_DEL, \
  KC_CAPS, LCTL(KC_BSPC), LCTL(KC_DEL), _______,       _______, _______,                 KC_HOME,     KC_LEFT,      KC_DOWN, KC_RGHT, KC_END , _______, \
  _______, _______,       _______,      _______,       _______, _______,                 MO(_ADJUST), LSFT(KC_F10), KC_UNDS, KC_PLUS, KC_PIPE, _______, \
  _______, _______,       _______,      _______,       _______, KC_BSPC,                 KC_SPC,      _______,      _______, _______, _______, _______ \
),

[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______ \
),

[_FUNCTIONS] =  LAYOUT_ortho_4x12( \
  KC_TAB,  KC_F1,         KC_F2,   KC_F3,   KC_F4,      KC_F5,                   KC_F6,   KC_F7,        KC_F8,   KC_F9,   KC_F10,     LCA(KC_DEL), \
  _______, KC_F11,        KC_F12,  _______, _______,    _______,                 _______, _______,      _______, _______, KC_PSCR,    _______, \
  _______, _______,       _______, _______, LCTL(KC_V), _______,                 _______, LSFT(KC_F10), _______, _______, _______,    _______, \
  _______, _______,       _______, _______, _______,    _______,                 _______, _______,      _______, _______, _______,    _______ \
),

[_NUMBERS] =  LAYOUT_ortho_4x12( \
  KC_GRV,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                  KC_6,    KC_7,    KC_8,    KC_9   , KC_0,    _______, \
  _______,       _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, \
  _______,       _______, _______, KC_LSFT, _______, _______,               _______, _______, KC_RSFT, _______, _______, _______, \
  _______,       _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______ \
)

};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;

     case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;

  }
  return true;
}

void matrix_scan_user(void) {
        return;
};
