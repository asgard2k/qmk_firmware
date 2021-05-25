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
    _LOWER,
    _RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(/* Base */
                KC_P7, KC_P8,   KC_P9, 				KC_NLCK,
                KC_P4, KC_P5,   KC_P6, 				LCTL(KC_BSPC),
                KC_P1, KC_P2,   KC_P3, 				KC_BSPC,
                KC_P0, KC_PDOT, LT(_LOWER,KC_ENT)
                ),
				
    [_LOWER] = LAYOUT(/* Lower */
                KC_BSPC, KC_UP,      KC_DEL,  RGB_TOG,
                KC_LEFT, KC_DOWN,    KC_RGHT, RESET,
                KC_SLSH, KC_ASTR,    KC_TRNS, KC_TRNS,
                KC_MINS, KC_PLUS,    KC_TRNS
                ),				

    [_RAISE] = LAYOUT(/* Raise */
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS
                ),				
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) 
  { 
    /* First encoder */
    if(IS_LAYER_ON(_LOWER))
	{
		if (clockwise) 
		  rgblight_increase_hue(); 
		else 
		  rgblight_decrease_hue();
	}
    else if(IS_LAYER_ON(_RAISE))
	{
		if (clockwise) 
		   rgblight_step();
		else 
		   rgblight_step_reverse();
	}	
	else
	{
		if (clockwise) 
		  tap_code(KC_MS_WH_RIGHT);   
		else 
		  tap_code(KC_MS_WH_LEFT);
	}
  } 
  else if (index == 1) 
  { 
    /* Second encoder */  
    if(IS_LAYER_ON(_LOWER))
	{
		if (clockwise) 
			rgblight_increase_val(); 
		else 
			rgblight_decrease_val();
	}
    else if(IS_LAYER_ON(_RAISE))
	{
		if (clockwise) 
		  rgblight_increase_sat(); 
		else 
		  rgblight_decrease_sat();
	}		
	else
	{
		if (clockwise) 
		  tap_code(KC_MS_WH_DOWN);   
		else 
		  tap_code(KC_MS_WH_UP); 
	}
  } 
  else if (index == 2) 
  { 
    /* Third encoder */  
    if(IS_LAYER_ON(_LOWER))
	{
		if (clockwise) 
		  tap_code(KC_VOLU);
		else 
		  tap_code(KC_VOLD); 
	}
	else
	{
		if (clockwise) 
		  tap_code(KC_PGDN);   
		else 
		  tap_code(KC_PGUP); 
	}
  }
}