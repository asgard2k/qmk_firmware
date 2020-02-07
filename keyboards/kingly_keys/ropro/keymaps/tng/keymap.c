/* Copyright 2019 Garret G. (TheRoyalSweatshirt)
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

enum layer_names {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTIONS,
  _MOUSE,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
  FUNCTIONS,
  MOUSE
};

#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   *        ,-----------------------------------------------------------------------------------.
   *        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10  | F11 |  F12 |
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
   *        |+------+------+------+------+-----+------+------+------+------+------+------+------|
   *  RotEn | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | PgUp | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * | Lower| Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | PgDn | Del  | Ctrl | GUI  | ALT  |Lower |SPACE |SPACE | End  | Left | Down |  Up  |Right |
   * `------------------------------------------------------------------------------------------'
   */
 [_QWERTY] = LAYOUT( \
              C_S_T(KC_F1),                 LT(_DVORAK,KC_F2), MT(MOD_LCTL|MOD_LSFT|MOD_LALT,KC_F3), KC_F4,                   KC_F5,                  KC_F6,               KC_F7,              KC_F8,            KC_F9,          KC_F10,    KC_F11,          LCAG_T(KC_F12), \
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/			  
              MT(MOD_LCTL|MOD_LALT,KC_GRV), KC_1,              KC_2,                                 KC_3,                    KC_4,                   KC_5,                KC_6,               KC_7,             KC_8,           KC_9,      KC_0,            KC_ESC, \
    XXXXXXX,  KC_TAB,                       KC_Q,              KC_W,                                 KC_E,                    LT(_MOUSE,KC_R),        KC_T,                KC_Y,               KC_U,             KC_I,           KC_O,      KC_P,            KC_DEL, \
    KC_HOME,  KC_LSFT,                      KC_A,              KC_S,                                 KC_D,                    LT(_RAISE,KC_F),        KC_G,                KC_H,               LT(_RAISE,KC_J),  KC_K,           KC_L,      KC_SCLN,         RSFT_T(KC_ENT), \
    KC_PGUP,  LSFT_T(KC_BSPC),              KC_Z,              KC_X,                                 KC_C,                    KC_V,                   KC_B,                KC_N,               KC_M,             KC_COMM,        KC_DOT,    RALT_T(KC_SLSH), RCTL_T(KC_QUOT), \
    KC_PGDN,  KC_LCTRL,                     KC_LGUI,           KC_LALT,                              LSFT(KC_F10),            LT(_FUNCTIONS,KC_CAPS), LOWER,               LT(_RAISE, KC_SPC), KC_RGUI,          KC_LEFT,        KC_UP,     KC_DOWN,         KC_RIGHT \
),

/* COLEMAK
 */
 [_COLEMAK] = LAYOUT( \
             _______, _______, _______ , _______ , _______ , _______    , _______ , _______, _______ , _______ , _______ , _______, \
             _______, _______, _______ , _______ , _______ , _______    , _______ , _______, _______ , _______ , _______ , _______, \
    XXXXXXX, _______, _______, _______ , _______ , _______ , _______    , _______ , _______, _______ , _______ , _______ , _______, \
    _______, _______, _______, _______ , _______ , _______ , _______    , _______ , _______, _______ , _______ , _______ , _______, \
    _______, _______, _______, _______ , _______ , _______ , _______    , _______ , _______, _______ , _______ , _______ , _______, \
    _______, _______, _______, _______ , _______ , _______ , _______    , _______ , _______, _______ , _______ , _______ , _______ \
 ),

/* DVORAK
 */
 [_DVORAK] = LAYOUT( \
             _______, _______, _______ , _______, _______, _______,                   _______ , _______, _______, _______, _______, _______, \
             _______, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    XXXXXXX, _______, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, RGB_TOG, RGB_MOD , RGB_HUI, RGB_SAI, RGB_VAI,                   RGB_TOG, RGB_MOD , RGB_HUI, RGB_SAI, RGB_VAI, _______, \
    _______, _______, RGB_M_P, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD,                   RGB_M_P, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, \
    _______, _______, _______, _______ , _______, _______, _______,                   _______, _______ , _______, _______, _______, _______ \
 ),

/* LOWER
 */
 [_LOWER] = LAYOUT( \
             KC_ESC, _______    , _______, _______,       _______,         _______,                    _______, _______, _______, _______, _______, _______, \
             KC_ESC , _______    , _______, _______,       _______,        _______,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    XXXXXXX, _______, LALT(KC_F4), XXXXXXX, LALT(KC_LEFT), LALT(KC_RIGHT), LCTL(LSFT(KC_ESC)),         KC_EXLM, KC_AT  , KC_HASH, KC_LCBR, KC_RCBR, _______, \
    _______, _______, XXXXXXX    , XXXXXXX, LCTL(KC_PGUP), LCTL(KC_PGDN) , XXXXXXX,                    KC_DLR , KC_LT  , KC_GT  , KC_LBRC, KC_RBRC, _______, \
    _______, KC_DEL,  XXXXXXX    , XXXXXXX, XXXXXXX,       XXXXXXX,        XXXXXXX,                    _______, KC_PERC, KC_MINS, KC_EQL , KC_BSLS, _______, \
    _______, _______, _______    , _______, _______,       _______,        _______ ,                   KC_SPC,  _______, _______, _______, _______, _______ \
 ),

/* RAISE
 */
 [_RAISE] = LAYOUT( \
             KC_ESC,  _______, _______, _______,       _______, _______,        _______,     _______,      _______, _______, _______, _______, \
             KC_ESC , _______, _______, _______,       _______, _______,        _______,     _______,      _______, _______, _______, _______, \
    XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_CAPS      , XXXXXXX, XXXXXXX,        XXXXXXX,     KC_PGUP,      KC_UP,   KC_PGDN, XXXXXXX, _______, \
    _______, _______, XXXXXXX, XXXXXXX, LCTL(KC_BSPC), XXXXXXX, XXXXXXX,        KC_HOME,     KC_LEFT,      KC_DOWN, KC_RGHT, KC_END , _______, \
    _______, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX      , XXXXXXX, XXXXXXX,        MO(_ADJUST), LSFT(KC_F10), KC_UNDS, KC_PLUS, KC_PIPE, _______, \
    _______, _______, _______, _______, _______,       _______, _______,        _______,     _______,      _______, _______, _______, _______ \
 ),

/* ADJUST
 */
 [_ADJUST] = LAYOUT( \
             _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, \
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    XXXXXXX, _______, RESET  , EEP_RST, DEBUG  , XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, QWERTY , XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______ \
 ),
  
/* FUNCTIONS
 */
 [_FUNCTIONS] = LAYOUT( \
             KC_ESC,  _______, _______, _______, _______,    _______,          _______, _______,      _______, _______, _______, _______, \
             KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,          XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,          XXXXXXX, XXXXXXX,      KC_INS , XXXXXXX, KC_PSCR, LCA(KC_DEL), \
    _______, _______, XXXXXXX, KC_SLCK, XXXXXXX, XXXXXXX,    XXXXXXX,          XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, KC_PAUS, _______    , \
    _______, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, LCTL(KC_V), XXXXXXX,          KC_NLCK, LSFT(KC_F10), XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, _______, _______, _______, _______,    _______,          _______, _______,      _______, _______, _______, _______ \
 ),
  
/* MOUSE
 */
 [_MOUSE] = LAYOUT( \
             KC_ESC,  _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, \
             KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    XXXXXXX, _______, KC_ACL0, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,          KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_ACL0, _______, \
    _______, _______, KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,          KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL1, _______, \
    _______, _______, KC_ACL2, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX,          XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R, KC_ACL2, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______ \
 ),

};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_WH_L);
        } else {
            tap_code(KC_WH_R);
        }
    }
}
