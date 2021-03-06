/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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

enum layer_names {
  _QWERTY,
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
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CAP LK | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_QWERTY] = LAYOUT_ortho_5x15( /* QWERTY */
    C_S_T(KC_GRV),                MT(MOD_LCTL|MOD_LSFT|MOD_LALT,KC_1), LT(_DVORAK,KC_2), KC_3,         KC_4,                   KC_5,             KC_6,    KC_6,    KC_6,                       KC_6,               KC_7,    KC_8,    KC_9,   KC_0,            LCAG_T(KC_ESC),
    MT(MOD_LCTL|MOD_LALT,KC_TAB), KC_Q,                                KC_W,             KC_E,         LT(_MOUSE,KC_R),        KC_T,             KC_6,    KC_6,    KC_6,                       KC_Y,               KC_U,    KC_I,    KC_O,   KC_P,            KC_DEL,
    KC_LSFT,                      KC_A,                                KC_S,             KC_D,         LT(_RAISE,KC_F),        KC_G,             KC_PSCR, KC_HOME, KC_END,                     KC_H,               KC_J,    KC_K,    KC_L,   KC_SCLN,         RSFT_T(KC_ENT),
    LSFT_T(KC_DEL),               KC_Z,                                KC_X,             KC_C,         KC_V,                   KC_B,             KC_PGUP, KC_PGUP, KC_PGDN,                    KC_N,               KC_M,    KC_COMM, KC_DOT, RALT_T(KC_SLSH), RCTL_T(KC_QUOT),
    KC_LCTL,                      KC_LGUI,                             KC_LALT,          LSFT(KC_F10), LT(_FUNCTIONS,KC_CAPS), MO(_LOWER),       KC_BSPC, KC_SPC,  LT(_MOUSE,KC_SPC),          LT(_RAISE, KC_SPC), KC_RGUI, KC_LEFT, KC_UP,  KC_DOWN,         KC_RIGHT
  ),

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_COLEMAK] = LAYOUT_ortho_5x15( 
    _______, _______, _______, _______, _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______
  ),
  
  [_DVORAK] = LAYOUT_ortho_5x15( 
    _______, _______, _______, _______, _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______,
    _______, BL_TOGG, BL_STEP, BL_INC,  BL_BRTG, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______,
    _______, BL_ON,   BL_OFF,  BL_DEC,  _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______
  ),
  
  [_LOWER] = LAYOUT_ortho_5x15( 
    KC_ESC,  KC_F1      , KC_F2  , KC_F3        , KC_F4         , KC_F5             ,               _______, _______, _______,               KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, LALT(KC_F4), _______, LALT(KC_LEFT), LALT(KC_RIGHT), LCTL(LSFT(KC_ESC)),               _______, _______, _______,               KC_EXLM, KC_AT  , KC_HASH, KC_LCBR, KC_RCBR, _______,
    _______, _______    , _______, LCTL(KC_PGUP), LCTL(KC_PGDN) , _______           ,               _______, _______, _______,               KC_DLR , KC_LT  , KC_GT  , KC_LBRC, KC_RBRC, _______,
    _______, _______,     _______, _______,       _______,        _______,                          _______, _______, KC_PGUP,               _______, KC_PERC, KC_MINS, KC_EQL , KC_BSLS, _______,
    _______, _______,     _______, _______,       _______,        _______,                          KC_DEL,  _______, KC_SPC,                KC_SPC,  _______, _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT_ortho_5x15( 
    _______, _______, _______, _______,       _______, _______,               _______, _______, _______,               _______,     _______,      _______, _______, _______, _______,
    _______, _______, _______, KC_CAPS,       _______, _______,               _______, _______, _______,               _______,     KC_PGUP,      KC_UP,   KC_PGDN, _______, _______,
    _______, _______, _______, LCTL(KC_BSPC), _______, _______,               _______, _______, _______,               KC_HOME,     KC_LEFT,      KC_DOWN, KC_RGHT, KC_END , _______,
    _______, _______, _______, _______,       _______, _______,               _______, _______, KC_PGUP,               MO(_ADJUST), LSFT(KC_F10), KC_UNDS, KC_PLUS, KC_PIPE, _______,
    _______, _______, _______, _______,       _______, _______,               KC_DEL,  _______, KC_SPC,                KC_SPC,      _______,      _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_ortho_5x15( 
    _______, _______, _______, _______, _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______,
    _______, RESET,   _______, _______, _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______
  ),

  [_FUNCTIONS] = LAYOUT_ortho_5x15( 
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 _______, _______, _______,               KC_F6,   KC_F7,        KC_F8,   KC_F9,   KC_F10,  _______,
    _______, KC_F11,  KC_F12,  _______, _______, _______,               _______, _______, _______,               _______, _______,      KC_INS,  _______, KC_PSCR, LCA(KC_DEL),
    _______, _______, KC_SLCK, _______, _______, _______,               _______, _______, _______,               _______, _______,      _______, _______, KC_PAUS, _______,
    _______, _______, _______, _______, _______, LCTL(KC_V),            _______, _______, _______,               KC_NLCK, LSFT(KC_F10), _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,               _______, _______, _______,               _______, _______,      _______, _______, _______, _______
  ),

  [_MOUSE] = LAYOUT_ortho_5x15( 
    _______, _______, _______, _______, _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______,
    _______, KC_ACL0, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,               _______, _______, _______,               KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_ACL0, _______,
    _______, KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,               _______, _______, _______,               KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL1, _______,
    _______, KC_ACL2, KC_WH_L, _______, KC_WH_R, _______,               _______, _______, KC_PGUP,               _______, KC_WH_L, _______, KC_WH_R, KC_ACL2, _______,
    _______, _______, _______, _______, _______, _______,               _______, _______, _______,               _______, _______, _______, _______, _______, _______
  )   
};
