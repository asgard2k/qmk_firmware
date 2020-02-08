#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif


extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

enum preonic_layers {
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

/* //Tap Dance Declarations
enum {
  TD_SCLN_CAPS = 0,
  TD_COMM_CTRLBACKSPACE
};

//Tap Dance Definitions.
// To use: Put something like TD(TD_COMM_CTRLBACKSPACE) in the keymaps for the key you want to tap-dance.
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_SCLN_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_CAPS),
  [TD_COMM_CTRLBACKSPACE]  = ACTION_TAP_DANCE_DOUBLE(KC_COMM, LCTL(KC_BSPC))
// Other declarations would go here, separated by commas, if you have them
}; */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
	C_S_T(KC_GRV)                , MT(MOD_LCTL|MOD_LSFT|MOD_LALT,KC_1) , LT(_DVORAK,KC_2)      , KC_3     , KC_4                  , KC_5                                                        , KC_6               , KC_7           , KC_8                    , KC_9           , KC_0           , LCAG_T(KC_ESC) , \
	MT(MOD_LCTL|MOD_LALT,KC_TAB) , KC_Q                                , KC_W                  , KC_E     , LT(_MOUSE,KC_R)       , KC_T                                                        , KC_Y               , KC_U           , KC_I                    , KC_O           , KC_P           , KC_DEL         , \
	KC_LSFT                      , KC_A                                , KC_S                  , KC_D     , LT(_RAISE,KC_F)       , KC_G                                                        , KC_H               , LT(_RAISE,KC_J), KC_K                    , KC_L           , KC_SCLN        , RSFT_T(KC_ENT), \
	KC_LCTL                      , LGUI_T(KC_Z)                        , KC_X                  , KC_C     , KC_V                  , KC_B      , LGUI_T(KC_PGUP)       , LT(_FUNCTIONS,KC_PGDN)  , KC_N               , KC_M           , KC_COMM                 , KC_DOT         , KC_SLSH        , RCTL_T(KC_QUOT) , \
	                                                                                             KC_LALT  , LT(_FUNCTIONS,KC_CAPS), MO(_LOWER), KC_BSPC               , LT(_MOUSE,KC_SPC)       , LT(_RAISE, KC_SPC) , KC_RGUI        , KC_RALT\
),

/* COLEMAK
 */
 [_COLEMAK] = LAYOUT( \
	_______, _______, _______, _______, _______, _______                  , _______, _______, _______, _______, _______, _______, \
	_______, _______, _______, _______, _______, _______                  , _______, _______, _______, _______, _______, _______, \
	_______, _______, _______, _______, _______, _______                  , _______, _______, _______, _______, _______, _______, \
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
							   _______, _______, _______, _______, _______, _______, _______, _______\
),

/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| RBG T| MODE+| HUE+ | SAT+ | VAL+ |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | MODE-| HUE- | SAT- | VAL- |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_DVORAK] = LAYOUT( \
	_______, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, _______, \
	_______, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, _______, \
	_______, RGB_TOG, RGB_MOD , RGB_HUI, RGB_SAI, RGB_VAI,                   RGB_TOG, RGB_MOD , RGB_HUI, RGB_SAI, RGB_VAI, _______, \
	_______, RGB_M_P, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, XXXXXXX, RGB_M_P, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, \
	                            _______, _______, _______, _______, _______, _______, _______ , _______ \
),


/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
	KC_ESC , KC_F1      , KC_F2  , KC_F3        , KC_F4         , KC_F5              ,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
	_______, LALT(KC_F4), XXXXXXX, LALT(KC_LEFT), LALT(KC_RIGHT), LCTL(LSFT(KC_ESC)) ,                    KC_EXLM, KC_AT  , KC_HASH, KC_LCBR, KC_RCBR, _______, 
	_______, XXXXXXX    , XXXXXXX, LCTL(KC_PGUP), LCTL(KC_PGDN) , XXXXXXX            ,                    KC_DLR , KC_LT  , KC_GT  , KC_LBRC, KC_RBRC, _______, \
	_______, XXXXXXX    , XXXXXXX, XXXXXXX      , XXXXXXX       , XXXXXXX            , XXXXXXX, KC_PGUP,  _______, KC_PERC, KC_MINS, KC_EQL , KC_BSLS, _______, \
	                               _______      , _______       , _______            , KC_DEL , KC_SPC,   KC_SPC,  _______, _______ \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
	_______, KC_1         , KC_2   , KC_3         , KC_4         , KC_5         ,                         KC_6        , KC_7        , KC_8      , KC_9   , KC_0   , _______, \
	_______, XXXXXXX      , XXXXXXX, KC_CAPS      , XXXXXXX      , XXXXXXX      ,                         XXXXXXX     , KC_PGUP     , KC_UP     , KC_PGDN, XXXXXXX, _______, \
	_______, XXXXXXX      , XXXXXXX, LCTL(KC_BSPC), XXXXXXX      , XXXXXXX      ,                         KC_HOME     , KC_LEFT     , KC_DOWN   , KC_RGHT, KC_END , _______, \
	_______, XXXXXXX      , XXXXXXX, XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , KC_PGUP, MO(_ADJUST) , LSFT(KC_F10), KC_UNDS   , KC_PLUS, KC_PIPE, _______, \
	                                 _______      , _______      , _______      , KC_DEL       , _______, _______     , _______     , _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
	_______, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
	_______, RESET  , EEP_RST , DEBUG  , XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
	_______, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, QWERTY , XXXXXXX, XXXXXXX, XXXXXXX, _______, \
	_______, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
	                            _______, _______, _______, _______, _______, _______, _______, _______ \
  ),
/* FUNCTIONS
 */
  [_FUNCTIONS] = LAYOUT( \
	KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4     , KC_F5     ,                   KC_F6  , KC_F7       , KC_F8  , KC_F9   , KC_F10 , _______    , \
	_______, KC_F11 , KC_F12 , XXXXXXX, XXXXXXX   , XXXXXXX   ,                   XXXXXXX, XXXXXXX     , KC_INS , XXXXXXX , KC_PSCR, LCA(KC_DEL), \
	_______, XXXXXXX, KC_SLCK, XXXXXXX, XXXXXXX   , XXXXXXX   ,                   XXXXXXX, XXXXXXX     , XXXXXXX, XXXXXXX , KC_PAUS, _______    , \
	_______, XXXXXXX, XXXXXXX, XXXXXXX, LCTL(KC_V), XXXXXXX   , XXXXXXX, XXXXXXX, KC_NLCK, LSFT(KC_F10), XXXXXXX, XXXXXXX , XXXXXXX, _______, \
	                           _______, _______   , _______   , _______, _______, _______, _______     , _______ \
  ),
  /* MOUSE
 */
  [_MOUSE] = LAYOUT( \
	_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
	_______, KC_ACL0, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,                         KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_ACL0, _______, \
	_______, KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                         KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL1, _______, \
	_______, KC_ACL2, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX, XXXXXXX,       KC_PGUP, XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R, KC_ACL2, _______, \
	                           _______, _______, _______, _______,       _______, _______, _______, _______ \
),
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void keyboard_post_init_user(void) {
  // Call the post init code.
  
  rgblight_setrgb(RGB_GREEN);
  //rgblight_set(); // Utility functions do not call rgblight_set() automatically, so they need to be called explicitly.

    
  //default_layer_state = QWERTY;
  set_single_persistent_default_layer(_QWERTY);
}

void matrix_init_user(void) {
	//reset_keyboard();
	
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
		
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
	
	// Host Keyboard LED Status
	matrix_write_P(matrix, (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) ?
				 PSTR("NUMLOCK") : PSTR("       "));
	matrix_write_P(matrix, (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) ?
				 PSTR("CAPS") : PSTR("    "));
	matrix_write_P(matrix, (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) ?
				 PSTR("SCLK") : PSTR("    "));
	matrix_write_P(matrix, PSTR("\n"));
  
    matrix_write_ln(matrix, read_keylog());
    matrix_write(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
	case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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
