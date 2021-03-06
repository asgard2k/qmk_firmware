/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

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
  DVORAK
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     C_S_T(KC_GRV),                MT(MOD_LCTL|MOD_LSFT|MOD_LALT,KC_1), KC_2,    KC_3,    KC_4,            KC_5,                                                 KC_6,               KC_7,                  KC_8,            KC_9,            KC_0,            LCAG_T(KC_BSPC),
     MT(MOD_LCTL|MOD_LALT,KC_TAB), KC_Q,                                KC_W,    KC_E,    LT(_MOUSE,KC_R), KC_T,                                                 KC_Y,               KC_U,                  KC_I,            KC_O,            KC_P,            KC_DEL,
     KC_LSFT,                      KC_A,                                KC_S,    KC_D,    LT(_RAISE,KC_F), KC_G,                                                 KC_H,               KC_J,                  KC_K,            KC_L,            KC_SCLN,         RSFT_T(KC_ENT),
     KC_LCTL,                      KC_Z,                                KC_X,    KC_C,    KC_V,            KC_B,                                                 KC_N,               KC_M,                  RALT_T(KC_COMM), RGUI_T(KC_DOT),  RCTL_T(KC_SLSH), RCTL_T(KC_QUOT),
                                                                        KC_LGUI, KC_LALT,                                                                                                                   KC_RALT,         KC_RGUI,
                                                                                          MO(_LOWER),      LT(_FUNCTIONS,KC_BSPC),                               LT(_RAISE, KC_SPC), MO(_FUNCTIONS),
                                                                                                                                    LSFT(KC_F10),       KC_SPC 
  ),
  
  [_COLEMAK] = LAYOUT_5x6(
       _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
                         _______, _______,                                                             _______, _______,
                                           _______,_______,                          _______,_______,
                                                             _______,       _______
  ),   

  [_DVORAK] = LAYOUT_5x6(
       _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
                         _______, _______,                                                             _______, _______,
                                           _______,_______,                          _______,_______,
                                                             _______,       _______
  ),     
  
  [_LOWER] = LAYOUT_5x6(
       KC_ESC,  KC_F1,       KC_F2,   KC_F3        , KC_F4         , KC_F5,                                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_ESC,
       _______, LALT(KC_F4), _______, LALT(KC_LEFT), LALT(KC_RIGHT), LCTL(LSFT(KC_ESC)),                          _______, _______, _______, KC_LCBR, KC_RCBR, _______,
       _______, _______,     _______, LCTL(KC_PGUP), LCTL(KC_PGDN),  _______,                                     _______, KC_LT  , KC_GT  , KC_LBRC, KC_RBRC, _______,
       _______, _______,     _______, _______,       _______,        _______,                                     KC_LPRN, KC_RPRN, KC_MINS, KC_EQL , KC_BSLS, _______,
                             _______, _______,                                                                                      _______, _______,
                                                     _______,        _______,                                     _______, _______,
                                                                                          _______,       _______
  ),   
  
  [_RAISE] = LAYOUT_5x6(
       KC_ESC , KC_1,          KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,        KC_7,         KC_8,    KC_9,    KC_0,    KC_ESC,
       _______, _______,       _______, KC_CAPS, _______, _______,                          _______,     KC_PGUP,      KC_UP,   KC_PGDN, _______, _______,
       _______, LCTL(KC_BSPC), _______, _______, _______, _______,                          KC_HOME,     KC_LEFT,      KC_DOWN, KC_RGHT, KC_END , _______,
       _______, _______,       _______, _______, _______, _______,                          MO(_ADJUST), LSFT(KC_F10), KC_UNDS, KC_PLUS, KC_PIPE, _______,
                               _______, _______,                                                                        _______, _______,
                                                 _______, KC_BSPC,                          _______,_______,
                                                                    _______,       _______
  ),   

  [_ADJUST] = LAYOUT_5x6(
       _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
       _______, RESET,   _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
                         _______, _______,                                                             _______, _______,
                                           _______,_______,                          _______,_______,
                                                             _______,       _______
  ),     

  [_FUNCTIONS] = LAYOUT_5x6(
       KC_ESC , KC_F1,         KC_F2,   KC_F3  , KC_F4,      KC_F5,                            KC_F6,   KC_F7,        KC_F8,   KC_F9,   KC_F10,  KC_ESC,
       _______, KC_F11,        KC_F12,  _______, _______,    _______,                          _______, _______,      KC_INS,  _______, KC_PSCR, LCA(KC_DEL),
       _______, LCTL(KC_BSPC), _______, _______, _______,    _______,                          _______, _______,      _______, _______, _______, _______,
       _______, _______,       _______, _______, LCTL(KC_V), _______,                          _______, LSFT(KC_F10), _______, _______, _______, _______,
                               _______, _______,                                                                      _______, _______,
                                                 _______,    _______,                          _______, _______,
                                                                 _______,       _______
  ),   
  
  [_MOUSE] = LAYOUT_5x6(
       KC_ESC,  DYN_REC_START1,  DYN_REC_START2,   _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
       _______, DYN_REC_STOP,    DYN_REC_STOP,     _______, _______, _______,                          KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_ACL0, _______,
       _______, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2,  _______, _______, _______,                          KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL1, _______,
       _______, _______,         _______,          _______, _______, _______,                          _______, KC_WH_L, _______, KC_WH_R, KC_ACL2, _______,
                                 _______,          _______,                                                             _______, _______,
                                                            _______, KC_DEL,                           _______,_______,
                                                                              _______,       _______
  ),   


};
