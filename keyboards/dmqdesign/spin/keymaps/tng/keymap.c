/* Copyright 2019-2020 DMQ Design
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

enum layer_number {
    _QWERTY = 0,
    _RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(/* Base */
                KC_P7, KC_P8, KC_P9, 				KC_TRNS,
                KC_P4, KC_P5, KC_P6, 				KC_TRNS,
                KC_P1, KC_P2, KC_P3, 				KC_TRNS,
                KC_P0, KC_PDOT, LT(_RAISE,KC_PENT)
                ),
				
    [_RAISE] = LAYOUT(/* Raise */
                KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_PSLS, KC_PAST, KC_TRNS, KC_TRNS,
                KC_PMNS, KC_PPLS, KC_TRNS
                ),				
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) 
  { 
    /* First encoder */
    if(IS_LAYER_ON(_RAISE))
	{
		if (clockwise) 
		  rgblight_increase_hue(); //Cycle through the RGB hue
		else 
		  rgblight_decrease_hue();
	}
	else
	{
		if (clockwise) 
		  tap_code(KC_MS_WH_LEFT); //Example of using tap_code which lets you use keycodes outside of the keymap
		else 
		  tap_code(KC_MS_WH_RIGHT);   
	}
  } 
  else if (index == 1) 
  { 
    /* Second encoder */  
    if(IS_LAYER_ON(_RAISE))
	{
		if (clockwise) 
			rgblight_increase_val(); //Change brightness on the RGB LEDs
		else 
			rgblight_decrease_val();
	}
	else
	{
		if (clockwise) 
		  tap_code(KC_PGUP); //Example of using tap_code which lets you use keycodes outside of the keymap
		else 
		  tap_code(KC_PGDN);   
	}
  } 
  else if (index == 2) 
  { 
    /* Third encoder */  
    if(IS_LAYER_ON(_RAISE))
	{
		if (clockwise) 
		  tap_code(KC_VOLU); //Example of using tap_code which lets you use keycodes outside of the keymap
		else 
		  tap_code(KC_VOLD); 
	}
	else
	{
		if (clockwise) 
		  tap_code(KC_MS_WH_UP); //Example of using tap_code which lets you use keycodes outside of the keymap
		else 
		  tap_code(KC_MS_WH_DOWN);   
	}
  }
}