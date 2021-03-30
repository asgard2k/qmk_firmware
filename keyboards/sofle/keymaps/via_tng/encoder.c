 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

//Setting up what encoder rotation does. If your encoder can be pressed as a button, that function can be set in Via.

#ifdef ENCODER_ENABLE

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
	_FUNCTION
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) 
  { 
    /* First encoder */
    if(IS_LAYER_ON(_LOWER))
	{

	}
    else if(IS_LAYER_ON(_RAISE))
	{
		if (clockwise) 
		  tap_code(KC_MS_WH_UP); 
		else 
		  tap_code(KC_MS_WH_DOWN);   
	}	
    else if(IS_LAYER_ON(_FUNCTION))
	{

	}		
	else
	{
		if (clockwise) 
		  tap_code(KC_PGUP); 		
		else 
		  tap_code(KC_PGDN);   
	}
  } 
  else if (index == 1) 
  { 
    /* Second encoder */  
    if(IS_LAYER_ON(_LOWER))
	{
	}
    else if(IS_LAYER_ON(_RAISE))
	{

	}		
    else if(IS_LAYER_ON(_FUNCTION))
	{
		if (clockwise) 
		  tap_code(KC_VOLD); 
		else 
		  tap_code(KC_VOLU);
	}		
	else
	{
		if (clockwise) 
		  tap_code(KC_MS_WH_LEFT);
		else 
		  tap_code(KC_MS_WH_RIGHT);   

	}
  } 
}

#endif