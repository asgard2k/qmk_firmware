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
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTIONS,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  FUNCTIONS,
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
                           KC_F1,                        KC_F2,                              KC_F3,                                 KC_F4,                   KC_F5,                  KC_F6,                  KC_F7,              KC_F8,              KC_F9,           KC_F10,         KC_F11,          LCAG_T(KC_F12), \
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/           
                           C_S_T(KC_GRV) ,               MT(MOD_LCTL|MOD_LSFT|MOD_LALT,KC_1), KC_2,                                 KC_3,                    KC_4,                   KC_5,                   KC_6,               KC_7,               KC_8,            KC_9,           KC_0,            KC_ESC, \
    KC_BSPC,               MT(MOD_LCTL|MOD_LALT,KC_TAB), KC_Q,                                KC_W,                                 KC_E,                    KC_R,                   KC_T,                   KC_Y,               KC_U,               KC_I,            KC_O,           KC_P,            KC_DEL, \
    KC_ESC,                KC_LSFT,                      KC_A,                                KC_S,                                 KC_D,                    LT(_RAISE,KC_F),        KC_G,                   KC_H,               KC_J,               KC_K,            KC_L,           KC_SCLN,         RSFT_T(KC_ENT), \
    LSFT_T(KC_PGUP),       KC_LSFT,                      KC_Z,                                KC_X,                                 KC_C,                    KC_V,                   KC_B,                   KC_N,               KC_M,               RALT_T(KC_COMM), RGUI_T(KC_DOT), RCTL_T(KC_SLSH), KC_QUOT, \
    LCTL_T(KC_PGDN),       KC_LCTRL,                     KC_LGUI,                             KC_LALT,                              MO(_LOWER),              LT(_FUNCTIONS,KC_BSPC), XXXXXXX,                XXXXXXX,            LT(_RAISE, KC_SPC), KC_LEFT,         KC_DOWN,        KC_RIGHT,        KC_UP \
),

/* LOWER
 */
 [_LOWER] = LAYOUT( \
             _______, _______    , _______, _______,       _______,        _______,                    _______, _______, _______, _______, _______, _______, \
             _______, _______    , _______, _______,       _______,        _______,                    _______, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    XXXXXXX, _______, LALT(KC_F4), _______, LALT(KC_LEFT), LALT(KC_RIGHT), LCTL(LSFT(KC_ESC)),         _______, _______, _______, KC_LCBR, KC_RCBR, _______, \
    _______, KC_CAPS, _______    , _______, LCTL(KC_PGUP), LCTL(KC_PGDN) , _______,                    _______, KC_LT  , KC_GT  , KC_LBRC, KC_RBRC, _______, \
    _______, _______, _______    , _______, _______,       _______,        _______,                    KC_LPRN, KC_RPRN, KC_MINS, KC_EQL , KC_BSLS, _______, \
    _______, _______, _______    , _______, _______,       _______,        _______,                    KC_SPC,  _______, _______, _______, _______, _______ \
 ),

/* RAISE
 */
 [_RAISE] = LAYOUT( \
             _______, _______,       _______,      _______, _______, _______,        _______,       _______,       _______, _______, _______, _______, \
             KC_GRV,  KC_1,          _______,      _______, _______, _______,        LCTL(KC_PGUP), LCTL(KC_PGDN), _______, _______, _______, _______, \
    XXXXXXX, KC_TAB,  _______,       _______,      _______, _______, _______,        KC_ESC,        KC_PGUP,       KC_UP,   KC_PGDN, _______, _______, \
    _______, _______, LCTL(KC_BSPC), LCTL(KC_DEL), KC_DEL,  _______, _______,        KC_HOME,       KC_LEFT,       KC_DOWN, KC_RGHT, KC_END , _______, \
    _______, _______, _______,       _______,      _______, _______, _______,        MO(_ADJUST),   LSFT(KC_F10),  KC_UNDS, KC_PLUS, KC_PIPE, _______, \
    _______, _______, _______,       _______,      _______, KC_BSPC, _______,        _______,       KC_SPC,       _______, _______, _______, _______ \
 ),

/* ADJUST
 */
 [_ADJUST] = LAYOUT( \
             _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, \
             _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, \
    XXXXXXX, _______, RESET  , _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______ \
 ),
  
/* FUNCTIONS
 */
 [_FUNCTIONS] = LAYOUT( \
             _______, _______, _______, _______, _______,    _______,          _______, _______,      _______, _______, _______, _______, \
             _______, _______, _______, _______, _______,    _______,          _______, _______,      _______, _______, _______, _______, \
    KC_ENT,  _______, _______, _______, _______, _______,    _______,          _______, _______,      KC_INS , _______, KC_PSCR, LCA(KC_DEL), \
    _______, KC_CAPS, _______, _______, _______, _______,    _______,          _______, _______,      _______, _______, _______, _______    , \
    _______, _______, _______, _______, _______, LCTL(KC_V), _______,          _______, _______,      _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,    _______,          _______, _______,      _______, _______, _______, _______ \
 ),

};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) 
    {
      if(IS_LAYER_ON(_RAISE)) 
      { 
        if (clockwise) 
        {
            tap_code(KC_DOWN);
        } 
        else 
        {
            tap_code(KC_UP);
        }
      } 
      else if(IS_LAYER_ON(_FUNCTIONS)) 
      { 
        if (clockwise) 
        {
            tap_code(KC_PGDN);
        } 
        else 
        {
            tap_code(KC_PGUP);
        }  
      } 
      else 
      { 
        if (clockwise)
        {
          tap_code(KC_WH_D);
        } 
        else
        {
          // Move wheel up
          tap_code(KC_WH_U);
        }
      }     
    }
}
