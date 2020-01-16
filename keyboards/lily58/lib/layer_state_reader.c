
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8
#define L_ADJUST_TRI 14

// same as in tng's keymap.c
enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTIONS,
  _MOUSE
};

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (biton32(layer_state)) 
  {
  case _QWERTY:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY");
    break;
  case _COLEMAK:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: COLEMAK");
    break;
  case _DVORAK:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: DVORAK");
    break;	
  case _LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: LOWER");
    break;
  case _RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: RAISE");
    break;
  case _ADJUST:
  //case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: ADJUST");
    break;
  case _FUNCTIONS:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: FUNCTIONS");
    break;	
case _MOUSE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: MOUSE");
    break;	
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}

/*
const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
*/