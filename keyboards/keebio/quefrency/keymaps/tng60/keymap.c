#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUNCTIONS,
    _MOUSE,
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
  MOUSE,
  // Moved these to bottom so the other layers can tap-hold to them 
  COLEMAK,
  DVORAK,
  RGBRST		// Special keycode for resetting the RGB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    C_S_T(KC_GRV),                MT(MOD_LCTL|MOD_LSFT|MOD_LALT,KC_1), LT(_DVORAK,KC_2), KC_3,          KC_4,                   KC_5,    KC_6,                KC_7,               KC_8,                   KC_9,            KC_0,            KC_MINS,          KC_EQL,  KC_DEL,         LCAG_T(KC_ESC),\
    MT(MOD_LCTL|MOD_LALT,KC_TAB), KC_Q,                                KC_W,             KC_E,          LT(_MOUSE,KC_R),        KC_T,                         KC_Y,               KC_U,                   KC_I,            KC_O,            KC_P,             KC_LBRC, KC_RBRC,        KC_BSLS,\
    LSFT_T(KC_CAPS),              KC_A,                                KC_S,             KC_D,          LT(_RAISE,KC_F),        KC_G,                         KC_H,               KC_J,                   KC_K,            KC_L,            KC_SCLN,          KC_QUOT, RSFT_T(KC_ENT),\
    KC_LSFT,                      KC_Z,                                KC_X,             KC_C,          KC_V,                   KC_B,                         KC_N,               KC_M,                   RALT_T(KC_COMM), RGUI_T(KC_DOT),  RCTL_T(KC_SLSH),  KC_RSFT, KC_UP,\
    KC_LCTL,                      KC_LGUI,                             KC_LALT,          KC_Q,    LT(_FUNCTIONS,KC_BSPC),                               LT(_RAISE, KC_SPC), LT(_FUNCTIONS, KC_SPC), KC_RALT,         KC_RGUI,         KC_RCTL,          KC_LEFT, KC_DOWN
  ),
  
  [_COLEMAK] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______, _______, _______
  ),
  
  [_DVORAK] = LAYOUT(
    _______, _______, _______,  _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, RGBRST , _______,  _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, RGB_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI,                      _______, _______, _______, _______, _______, _______, _______, \
    _______, RGB_M_P, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD,                      _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,  _______, _______,                               _______, _______, _______, _______, _______, _______, _______
  ),
  
  [_LOWER] = LAYOUT(
    _______, _______,     _______, _______,       _______,        _______,            _______,             KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______, _______, \
    _______, LALT(KC_F4), _______, LALT(KC_LEFT), LALT(KC_RIGHT), LCTL(LSFT(KC_ESC)),                      _______, KC_AT  , KC_HASH, KC_LCBR, KC_RCBR, _______, _______, _______, \
    _______, _______,     _______, LCTL(KC_PGUP), LCTL(KC_PGDN),  _______,                                 _______, KC_LT  , KC_GT  , KC_LBRC, KC_RBRC, _______, _______, \
    _______, _______,     _______, _______,       _______,        _______,                                 _______, KC_PERC, KC_MINS, KC_EQL , KC_BSLS, _______, _______, \
    _______, _______,     _______, _______,       KC_BSPC,                                                 KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______
  ),
  
  [_RAISE] = LAYOUT(
    _______, _______,       _______, _______,           _______,        _______,           _______,              _______,     _______,      _______, _______, _______, _______, _______, _______, \
    _______, _______,       _______, KC_CAPS,           _______,        _______,                                 _______,     KC_PGUP,      KC_UP,   KC_PGDN, _______, _______, _______, _______, \
    _______, LCTL(KC_BSPC), _______, LCTL(KC_BSPC),     _______,        _______,                                 KC_HOME,     KC_LEFT,      KC_DOWN, KC_RGHT, KC_END , _______, _______, \
    _______, _______,       _______, _______,           _______,        _______,                                 MO(_ADJUST), LSFT(KC_F10), KC_UNDS, KC_PLUS, KC_PIPE, _______, _______, \
    _______, _______,       _______, _______,           KC_BSPC,                                                 KC_SPC,      KC_SPC,       _______, _______, _______, _______, _______
  ),
  
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET,   _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______, _______, _______
  ),
  
  [_FUNCTIONS] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,      KC_F5,   KC_F16,           KC_F7,   KC_F8,        KC_F9,  KC_F10,   KC_F11,  KC_F12,       LCA(KC_DEL), _______, \
    _______, _______, _______, _______, _______,    _______,                   _______, _______,      KC_INS,  _______, KC_PSCR, _______,      _______,     _______, \
    _______, _______, KC_SLCK, _______, _______,    _______,                   _______, _______,      _______, _______, KC_PAUS, _______,      _______, \
    _______, _______, _______, _______, LCTL(KC_V), _______,                   KC_NLCK, LSFT(KC_F10), _______, _______, _______, _______,      DYN_REC_START2, \
    _______, _______, _______, _______, _______,                               _______, _______,      _______, _______, _______, DYN_REC_STOP, DYN_MACRO_PLAY2
  ),
  
  [_MOUSE] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                      KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_ACL0, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                      KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL1, _______, _______, \
    _______, _______, _______, _______, _______, _______,                      _______, KC_WH_L, _______, KC_WH_R, KC_ACL2, _______, _______, \
    _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______, _______, _______
  )   
};

// Need to research more on this. Seems like only master side gets affected.
/* void keyboard_post_init_user(void) {
  // Call the post init code.
  
  rgblight_setrgb(RGB_PURPLE);
  //rgblight_set(); // Utility functions do not call rgblight_set() automatically, so they need to be called explicitly.

    
  //default_layer_state = QWERTY;
  set_single_persistent_default_layer(_QWERTY);
} */

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
