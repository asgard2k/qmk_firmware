#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUNCTIONS
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,			// Special keycode for resetting the RGB
  STR_1,
  STR_2,
  STR_3,
  STR_4,  
  STR_5,    
};


#if MATRIX_ROWS == 10 // HELIX_ROWS == 5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Adjust| Esc  | Alt  | GUI  | EISU |Lower |Space |Space |Raise | KANA | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT( \
	C_S_T(KC_GRV)                , MT(MOD_LCTL|MOD_LSFT|MOD_LALT,KC_1) , KC_2    , KC_3         , KC_4            , KC_5                                       , KC_6              , KC_7           , KC_8            , KC_9           , KC_0           , LCAG_T(KC_ESC) , \
	MT(MOD_LCTL|MOD_LALT,KC_TAB) , KC_Q                                , KC_W    , KC_E         , KC_R            , KC_T                                       , KC_Y              , KC_U           , KC_I            , KC_O           , KC_P           , KC_DEL         , \
	KC_LSFT                      , KC_A                                , KC_S    , KC_D         , LT(_RAISE,KC_F) , KC_G                                       , KC_H              , KC_J           , KC_K            , KC_L           , KC_SCLN        , RSFT_T(KC_ENT), \
	KC_LSFT                      , LT(_FUNCTIONS,KC_Z)                 , KC_X    , KC_C         , KC_V            , KC_B                   , KC_PGUP , KC_HOME , KC_N              , KC_M           , RALT_T(KC_COMM) , RGUI_T(KC_DOT) , RCTL_T(KC_SLSH), KC_QUOT , \
	KC_LCTL                      , KC_LGUI                             , KC_LALT , LSFT(KC_F10) , MO(_LOWER)      , LT(_FUNCTIONS,KC_BSPC) , KC_PGDN , KC_END  , LT(_RAISE,KC_SPC) , MO(_FUNCTIONS) , KC_LEFT        , KC_DOWN         , KC_RIGHT       , KC_UP\
      ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CAPS |  F7  |  F8  |  F9  |  F10 |  F11 |  (   |   )  |  F12 |      |      | Home | End  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
	_______, _______    , _______, _______      , _______       , _______,                               _______, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
	_______, LALT(KC_F4), _______, LALT(KC_LEFT), LALT(KC_RIGHT), LCTL(LSFT(KC_ESC)),                    _______, _______, _______, KC_LCBR, KC_RCBR, _______, \
	_______, _______    , _______, LCTL(KC_PGUP), LCTL(KC_PGDN) , _______,                               _______, KC_LT  , KC_GT  , KC_LBRC, KC_RBRC, _______, \
	_______, _______    , _______, _______      , _______       , _______,            _______, _______,  KC_LPRN, KC_RPRN, KC_MINS, KC_EQL , KC_BSLS, _______, \
	_______, _______    , _______, _______      , _______       , _______,            _______, _______,  _______, _______, _______, _______, _______, _______ \
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CAPS |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 |      |      |PageDn|PageUp|      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
	KC_GRV , KC_1         , _______     , _______      , _______      , _______      ,                         _______     , _______     , _______   , _______, _______, KC_ESC, \
	KC_TAB , _______      , _______     , _______      , _______      , _______      ,                         _______     , KC_PGUP     , KC_UP     , KC_PGDN, _______, _______, \
	_______, LCTL(KC_BSPC), LCTL(KC_DEL), KC_DEL       , _______      , _______      ,                         KC_HOME     , KC_LEFT     , KC_DOWN   , KC_RGHT, KC_END , _______, \
	_______, _______      , _______     , _______      , _______      , _______      , _______      , _______, MO(_ADJUST) , LSFT(KC_F10), KC_UNDS   , KC_PLUS, KC_PIPE, _______, \
	_______, _______      , _______     , _______      , _______      , KC_BSPC      , _______      , _______, KC_SPC      , _______     , _______   , _______, _______, _______ \
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Reset|RGBRST|      |      |      |             |      |      |      |      |      |  Del |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |Aud on|Audoff| Mac  |             | Win  |Qwerty|Colemk|Dvorak|      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT( \
	RGB_TOG, RGB_MODE_FORWARD, RGB_MODE_GRADIENT , RGB_M_K, RGB_M_P, RGB_M_R,                   RGB_M_SW, _______ , _______, _______, _______, _______, \
	RGB_RST, RESET           , RGB_VAI           , RGB_HUI, RGB_SAI, RGB_SPI,                   _______ , _______ , _______, _______, _______, _______, \
	_______, RGB_MOD         , RGB_VAD           , RGB_HUD, RGB_SAD, RGB_SPD,                   _______ , _______ , _______, _______, _______, _______, \
	_______, RGB_RMOD        , _______           , _______, _______, _______, _______, _______, _______ , _______ , _______, _______, _______, _______, \
	_______, _______         , _______           , _______, _______, _______, _______, _______, _______ , _______ , _______, _______, _______, _______ \
      ),
	  
/* FUNCTIONS
 */
  [_FUNCTIONS] = LAYOUT( \
	STR_1  , KC_F1  , KC_F2  , KC_F3  , KC_F4     , KC_F5     ,                   KC_F6  , KC_F7       , KC_F8  , KC_F9   , KC_F10  , _______    , \
	STR_2  , KC_F11 , KC_F12 , _______, _______   , _______   ,                   _______, _______     , KC_INS , _______ , KC_PSCR , LCA(KC_DEL), \
	KC_CAPS, _______, _______, _______, _______   , _______   ,                   _______, _______     , _______, _______ , _______ , _______    , \
	_______, _______, _______, _______, LCTL(KC_V), _______   , _______, _______, _______, LSFT(KC_F10), KC_COMM, KC_DOT  , KC_SLSH , _______, \
	_______, _______, _______, _______, _______   , _______   , _______, _______, _______, _______     , _______, _______ , _______ , _______ \
  ),


};

#elif MATRIX_ROWS == 8 // HELIX_ROWS == 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust| Esc  | Alt  | GUI  | EISU |Lower |Space |Space |Raise | KANA | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT( \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
      ADJUST,  KC_ESC,  KC_LALT, KC_LGUI, EISU,    LOWER,   KC_SPC,  KC_SPC,  RAISE,   KANA,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),


  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |             |  F12 |      |      | Home | End  |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  _______, _______, KC_HOME, KC_END,  _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |             |  F12 |      |      |PageDn|PageUp|      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  _______, _______, KC_PGDN, KC_PGUP, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      | Reset|RGBRST|      |      |      |             |      |      |      |      |      |  Del |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |Aud on|Audoff| Mac  |             | Win  |Qwerty|Colemk|Dvorak|      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT( \
      _______, RESET,    RGBRST, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL, \
      _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,                   AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD \
      )),
	  
/* FUNCTIONS
 */
  [_FUNCTIONS] = LAYOUT( \
      _______, RESET,    RGBRST, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL, \
      _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,                   AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD \
  ),


};

#else
#error "undefined keymaps"
#endif


#ifdef AUDIO_ENABLE

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      //rgblight_mode(RGB_current_mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

//////////////////////////////////////////////////////////////
// My helix doesn't like this for some reason. The left side keeps rebooting (sometimes after pressing some keys)
//////////////////////////////////////////////////////////////
/* void keyboard_post_init_user(void) {
  // Call the post init code.
  
  rgblight_setrgb(RGB_PURPLE);
  //rgblight_set(); // Utility functions do not call rgblight_set() automatically, so they need to be called explicitly.

    
  //default_layer_state = QWERTY;
  // persistent_default_layer_set(1UL<<_QWERTY);
} */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case RGB_RST:
	  #ifdef RGBLIGHT_ENABLE
		if (record->event.pressed) {
		  eeconfig_update_rgblight_default();
		  rgblight_enable();
		  RGB_current_mode = rgblight_config.mode;
		}
	  #endif
	  break;
	case STR_1:
		if (record->event.pressed) 
			SEND_STRING("August13@@");
		break;
	case STR_2:
		if (record->event.pressed) 
			SEND_STRING("taikamng@yahoo.com");
		break;
	case STR_3:
		if (record->event.pressed) 
			SEND_STRING("tai.kam.ng@kla-tencor.com");
		break;	  
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}


#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
}

void shutdown_user()
{
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif


//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void matrix_scan_user(void) {
     iota_gfx_task();  // this is what updates the display continuously
}

void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

//assign the right code to your layers for OLED display
#define L_BASE 0
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

static void render_logo(struct CharacterMatrix *matrix) {

  static const char helix_logo[] PROGMEM ={
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    0};
  matrix_write_P(matrix, helix_logo);
  //matrix_write_P(&matrix, PSTR(" Split keyboard kit"));
}

static void render_rgbled_status(bool full, struct CharacterMatrix *matrix) {
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_ANIMATIONS)
  char buf[30];
  if(rgblight_config.enable) {
      if (full) {
          snprintf(buf, sizeof(buf), " LED %2d: %d,%d,%d ",
                   rgblight_config.mode,
                   rgblight_config.hue/RGBLIGHT_HUE_STEP,
                   rgblight_config.sat/RGBLIGHT_SAT_STEP,
                   rgblight_config.val/RGBLIGHT_VAL_STEP);
      } else {
          snprintf(buf, sizeof(buf), "[%2d] ",rgblight_config.mode);
      }
      matrix_write(matrix, buf);
  }
#endif
}

static void render_layer_status(struct CharacterMatrix *matrix) {
  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  // char buf[10];
  // matrix_write_P(matrix, PSTR("Layer: "));
  //   switch (layer_state) {
  //       case L_BASE:
  //          matrix_write_P(matrix, PSTR("Default"));
  //          break;
  //       case L_RAISE:
  //          matrix_write_P(matrix, PSTR("Raise"));
  //          break;
  //       case L_LOWER:
  //          matrix_write_P(matrix, PSTR("Lower"));
  //          break;
  //       case L_ADJUST:
  //       case L_ADJUST_TRI:
  //          matrix_write_P(matrix, PSTR("Adjust"));
  //          break;
  //       default:
  //          matrix_write_P(matrix, PSTR("Undef-"));
  //          snprintf(buf,sizeof(buf), "%ld", layer_state);
  //          matrix_write(matrix, buf);
  //   }

      char layer_name[17];
      switch (biton32(layer_state)) 
      {
      case _QWERTY:
        snprintf(layer_name, sizeof(layer_name), "QWERTY");
        break;
      case _LOWER:
        snprintf(layer_name, sizeof(layer_name), "LOWER");
        break;
      case _RAISE:
        snprintf(layer_name, sizeof(layer_name), "RAISE");
        break;
      case _ADJUST:
      //case L_ADJUST_TRI:
        snprintf(layer_name, sizeof(layer_name), "ADJUST");
        break;
      case _FUNCTIONS:
        snprintf(layer_name, sizeof(layer_name), "FUNCTIONS");
        break;	
      default:
        snprintf(layer_name, sizeof(layer_name), "Undef-%ld", layer_state);
      }    

    char layer_state_str[24];
    strcpy(layer_state_str, "Layer: ");
    strcat(layer_state_str, layer_name);    

    matrix_write(matrix, layer_state_str);
}

void render_status(struct CharacterMatrix *matrix) {

  // Render to mode icon
  static const char os_logo[][2][3] PROGMEM  ={{{0x95,0x96,0},{0xb5,0xb6,0}},{{0x97,0x98,0},{0xb7,0xb8,0}}};
  if(keymap_config.swap_lalt_lgui==false){
    matrix_write_P(matrix, os_logo[0][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write_P(matrix, os_logo[0][1]);
  }else{
    matrix_write_P(matrix, os_logo[1][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write_P(matrix, os_logo[1][1]);
  }

  matrix_write_P(matrix, PSTR(" "));
  render_layer_status(matrix);
  matrix_write_P(matrix, PSTR("\n"));

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  matrix_write_P(matrix, (led_usb_state & (1<<USB_LED_NUM_LOCK)) ?
                 PSTR("NUM ") : PSTR("    "));
  matrix_write_P(matrix, (led_usb_state & (1<<USB_LED_CAPS_LOCK)) ?
                 PSTR("CAPS ") : PSTR("     "));
  matrix_write_P(matrix, (led_usb_state & (1<<USB_LED_SCROLL_LOCK)) ?
                 PSTR("SCLK ") : PSTR("     "));
  matrix_write_P(matrix, PSTR("\n"));
  render_rgbled_status(true, matrix);
}


void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

#if DEBUG_TO_SCREEN
  if (debug_enable) {
    return;
  }
#endif

  matrix_clear(&matrix);
  if(is_master){
    render_status(&matrix);
  }else{
    render_logo(&matrix);
    render_rgbled_status(false, &matrix);
    render_layer_status(&matrix);
  }
  matrix_update(&display, &matrix);
}

#endif
