/*
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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | ]      | Y      | U      | I      | O      | P      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | CAP LK | A      | S      | D      | F      | G      | HOME   | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | FN     | LALT   | SPACE  | SPACE  | SPACE  | SPACE  | SPACE  | LEFT   | DOWN   | UP     | RIGHT  | RCTRL  |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_5x14(
        C_S_T(KC_GRV),                 MT(MOD_LCTL|MOD_LSFT|MOD_LALT,KC_1), LT(_DVORAK,KC_2),    KC_3,           KC_4,               KC_5,                              KC_INS,                 KC_PSCR,                       KC_6,                KC_7,       KC_8,            KC_9,            KC_0,            LCAG_T(KC_ESC),
        MT(MOD_LCTL|MOD_LALT,KC_TAB),  KC_Q,                                KC_W,                KC_E,           LT(_MOUSE,KC_R),    KC_T,                              KC_HOME,                KC_PGUP,                       KC_Y,                KC_U,       KC_I,            KC_O,            KC_P,            KC_DEL,
        LSFT_T(KC_CAPS),               KC_A,                                KC_S,                KC_D,           LT(_RAISE,KC_F),    KC_G,                              KC_END,                 KC_PGDN,                       KC_H,                KC_J,       KC_K,            KC_L,            KC_SCLN,         RSFT_T(KC_ENT),
        KC_LSFT,                       KC_Z,                                KC_X,                KC_C,           KC_V,               KC_B,                              KC_END,                 KC_PGDN,                       KC_N,                KC_M,       RALT_T(KC_COMM), RGUI_T(KC_DOT),  RCTL_T(KC_SLSH), RCTL_T(KC_QUOT),
        KC_LCTL,                       KC_LGUI,                             KC_LALT,             MO(_FUNCTIONS), MO(_LOWER),         LT(_FUNCTIONS,KC_BSPC),            LT(_FUNCTIONS,KC_BSPC), LT(_RAISE, KC_SPC),            LT(_RAISE, KC_SPC),  MO(_RAISE), MO(_FUNCTIONS),  KC_RALT,         KC_RGUI,         KC_RCTL
    ),
	
    [_COLEMAK] = LAYOUT_ortho_5x14(
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     _______, _______, _______, _______, _______, _______
    ),
	
    [_DVORAK] = LAYOUT_ortho_5x14(
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI,                     _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, RGB_M_P, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD,                     _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     _______, _______, _______, _______, _______, _______
     ),	

    [_LOWER] = LAYOUT_ortho_5x14(
        KC_ESC,  _______,     _______, _______,       _______,        _______,                     _______, _______,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, LALT(KC_F4), _______, LALT(KC_LEFT), LALT(KC_RIGHT), LCTL(LSFT(KC_ESC)),          _______, _______,                     _______, _______, _______, KC_LCBR, KC_RCBR, _______,
        _______, _______,     _______, LCTL(KC_PGUP), LCTL(KC_PGDN),  _______,                     _______, _______,                     _______, KC_LT,   KC_GT,   KC_LBRC, KC_RBRC, _______,
        _______, _______,     _______, _______,       _______,        _______,                     _______, _______,                     KC_LPRN, KC_RPRN, KC_MINS, KC_EQL , KC_BSLS, _______,
        _______, _______,     _______, _______,       _______,        KC_BSPC,                     KC_BSPC, KC_SPC,                      KC_SPC,  _______, _______, _______, _______, _______

    ),
	
    [_RAISE] = LAYOUT_ortho_5x14(
        _______, _______,       _______, _______,       _______, _______,                     _______, _______,                     _______,     _______,      _______, _______,  _______, _______,
        _______, _______,       _______, KC_CAPS,       _______, _______,                     _______, _______,                     _______,     KC_PGUP,      KC_UP,   KC_PGDN,  _______, _______,
        _______, LCTL(KC_BSPC), _______, LCTL(KC_BSPC), _______, _______,                     _______, _______,                     KC_HOME,     KC_LEFT,      KC_DOWN, KC_RGHT,  KC_END , _______,
        _______, _______,       _______, _______,       _______, _______,                     _______, _______,                     MO(_ADJUST), LSFT(KC_F10), KC_UNDS, KC_PLUS,  KC_PIPE, _______,
        _______, _______,       _______, _______,       _______, KC_BSPC,                     KC_BSPC, KC_SPC,                      KC_SPC,      _______,      _______, _______,  _______, _______
    ),

    [_ADJUST] = LAYOUT_ortho_5x14(
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, RESET,   _______, _______, _______, _______,                     _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     _______, _______, _______, _______, _______, _______
    ),
	
    [_FUNCTIONS] = LAYOUT_ortho_5x14(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,      KC_F,                        DYN_REC_START1,  DYN_REC_START2,                     KC_F6,   KC_F7,        KC_F8,  KC_F9,    KC_F10,  _______,
        _______, KC_F11,  KC_F12,  _______, _______,    _______,                     DYN_REC_STOP,    DYN_REC_STOP,                       _______, _______,      KC_INS, _______,  KC_PSCR, LCA(KC_DEL),
        _______, _______, KC_SLCK, _______, _______,    _______,                     DYN_MACRO_PLAY1, DYN_MACRO_PLAY2,                    _______, _______,      _______, _______, KC_PAUS, _______,
        _______, _______, _______, _______, LCTL(KC_V), _______,                     DYN_MACRO_PLAY1, DYN_MACRO_PLAY2,                    KC_NLCK, LSFT(KC_F10), _______, _______, _______, _______,
        _______, _______, _______, _______, _______,    _______,                     _______,         _______,                                    _______, _______,      _______, _______, _______, _______
    ),
	
	[ _MOUSE] = LAYOUT_ortho_5x14(
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_ACL0, _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL1, _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______,                     _______, KC_WH_L, _______, KC_WH_R, KC_ACL2, _______,
        _______, _______, _______, _______, _______, KC_DEL,                      KC_DEL,  _______,                     _______, _______, _______, _______, _______, _______
    )	 
	 
};
