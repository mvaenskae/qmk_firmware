#include QMK_KEYBOARD_H
#include <split_util.h>
#include <keymap_german.h>
#include "keymap_mine.h"
#include "encoder.c"
#include "oled.c"
#include "shared_state.h"
#include "rgb_light.c"

#include "keymap_osx_english.h"
#include "keymap_osx_german.h"

#define PRESS_KEY(CODE) harmonized_key_press(record, KC_##CODE, DE_##CODE, OSX_EN_##CODE, OSX_DE_##CODE)
#define PRESS_KEY_MISSING(CODE) harmonized_key_press(record, DE_##CODE, DE_##CODE, OSX_EN_##CODE, OSX_DE_##CODE)
#define PRESS_KEY_DIFFERENT(CODE_EN, CODE_DE) harmonized_key_press(record, KC_##CODE_EN, DE_##CODE_DE, OSX_EN_##CODE_EN, OSX_DE_##CODE_DE)


enum custom_keycodes {
    KC_COLEMAKDH = SAFE_RANGE,
    KC_GAME,
    KC_QWERTY,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    MV_LANG,
    MV_KBLY,
    MV_OSX,
    MV_LNDL,
    MV_LNST,
    MV_LNEN,
    MV_WDPV,
    MV_WDNX,
    MV_DEGR,
    MV_Y,
    MV_Z,
    MV_ACUT,
    MV_GRV,
    MV_CIRC,
    MV_TILD,
    MV_PIPE,
    MV_SLSH,
    MV_UNDS,
    MV_LPRN,
    MV_RPRN,
    MV_AT,
    MV_QUES,
    MV_AMPR,
    MV_DQUO,
    MV_QUOT,
    MV_PLUS,
    MV_MINS,
    MV_SCLN,
    MV_LCBR,
    MV_RCBR,
    MV_LABK,
    MV_RABK,
    MV_HASH,
    MV_EXLM,
    MV_DLR,
    MV_EURO,
    MV_BSLS,
    MV_ASTR,
    MV_EQL,
    MV_COLN,
    MV_LBRC,
    MV_RBRC,
    MV_PERC,
    MV_ADIA,
    MV_ODIA,
    MV_UDIA,
    MV_SS
};

volatile bool is_german = true;
volatile bool is_osx = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* LAYER_ID
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *		 |      |      |      |      |       |    |       |      |      |      |      |
 *               '-----------------------------------'    '-----------------------------------'
 */


/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   | `/ß  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |  Q   |  W   |  E   |  R   |  T   |                    |  Y   |  U   |  I   |  O   |  P   | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LSHIFT|  A   |  S   |  D   |  F   |  G   |                    |  H   |  J   |  K   |  L   | ;/ü  |RSHIFT|
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |      |  Z   |  X   |  C   |  V   |  B   | MUTE  |    |       |  N   |  M   |  ,   |  .   | //ö  | '/ä  |
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *		 |LCTRL | LGUI | LALT |LOWER | SPACE |    | ENTER |RAISE | RALT | RGUI |RCTRL |
 *               '-----------------------------------'    '-----------------------------------'
 */
  [_QWERTY] = LAYOUT(
//,-----------------------------------------------------.                          ,-----------------------------------------------------.
   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    LT(_SWITCH, KC_5),                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MV_SS,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   LT(_NUMPAD, KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T,                               MV_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    MV_UDIA, KC_RSFT,
//|--------+--------+--------+--------+--------+--------| ====== .        , ====== |--------+--------+--------+--------+--------+--------|
   XXXXXXX, MV_Z,    KC_X,    KC_C,    KC_V,    KC_D,    KC_MUTE,          KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  MV_ODIA, MV_ADIA,
//|--------+--------+--------+--------+--------+--------| ====== |        | ====== |--------+--------+--------+--------+--------+--------|
                     KC_LCTL, KC_LGUI, KC_LALT, KC_LOWER, KC_ENT,          KC_SPC,  KC_RAISE,KC_RALT, KC_RGUI, KC_RCTL
//                  '--------+--------+--------+--------+--------'        '--------+--------+--------+--------+--------'
),

/* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   | `/ß  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |  Q   |  W   |  E   |  R   |  T   |                    |  Y   |  U   |  I   |  O   |  P   | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LSHIFT|  A   |  S   |  D   |  F   |  G   |                    |  H   |  J   |  K   |  L   | ;/ü  |RSHIFT|
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |      |  Z   |  X   |  C   |  V   |  B   | MUTE  |    |       |  N   |  M   |  ,   |  .   | //ö  | '/ä  |
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *		 |LCTRL | LGUI | LALT |LOWER | SPACE |    | ENTER |RAISE | RALT | RGUI |RCTRL |
 *               '-----------------------------------'    '-----------------------------------'
 */
  [_GAME] = LAYOUT(
//,-----------------------------------------------------.                          ,-----------------------------------------------------.
   _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   KC_TAB,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------| ====== .        , ====== |--------+--------+--------+--------+--------+--------|
   KC_LCTL, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------| ====== |        | ====== |--------+--------+--------+--------+--------+--------|
                     _______, _______, _______, _______, KC_SPC,           KC_ENT,  _______, _______, _______, _______
//                  '--------+--------+--------+--------+--------'        '--------+--------+--------+--------+--------'

),

/* COLEMAK-DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   | `/ß  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |  Q   |  W   |  F   |  P   |  B   |                    |  J   |  L   |  U   |  Y   | ;/ü  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LSHIFT|  A   |  R   |  S   |  T   |  G   |                    |  M   |  N   |  E   |  I   |  O   |RSHIFT|
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |      |  Z   |  X   |  C   |  D   |  V   | MUTE  |    |       |  K   |  H   |  ,   |  .   | //ö  | '/ä  |
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *		 |LCTRL | LGUI | LALT |LOWER | SPACE |    | ENTER |RAISE | RALT | RGUI |RCTRL |
 *               '-----------------------------------'    '-----------------------------------'
 */
[_COLEMAKDH] = LAYOUT(
//,-----------------------------------------------------.                          ,-----------------------------------------------------.
   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    LT(_SWITCH, KC_5),                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MV_SS,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   LT(_NUMPAD, KC_TAB), KC_Q, KC_W, KC_F, KC_P, KC_B,                               KC_J,    KC_L,    KC_U,    MV_Y,    MV_UDIA, KC_BSPC,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   KC_LSFT, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_RSFT,
//|--------+--------+--------+--------+--------+--------| ====== .        , ====== |--------+--------+--------+--------+--------+--------|
   XXXXXXX, MV_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_MUTE,          KC_MPLY, KC_K,    KC_H,    KC_COMM, KC_DOT,  MV_ODIA, MV_ADIA,
//|--------+--------+--------+--------+--------+--------| ====== |        | ====== |--------+--------+--------+--------+--------+--------|
                     KC_LCTL, KC_LGUI, KC_LALT, KC_LOWER, KC_ENT,          KC_SPC,  KC_RAISE,KC_RALT, KC_RGUI, KC_RCTL
//                  '--------+--------+--------+--------+--------'        '--------+--------+--------+--------+--------'
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  °   |  ´   |  `   |  ^   |  ~   |                    |  |   |  /   |  _   |  (   |  )   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  @   |  ?   |  &   |  "   |  '   |                    |  +   |  -   |  ;   |  {   |  }   |  <   |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |  \   |  #   |  !   |  $   |  €   |  %   |       |    |       |  *   |  =   |  :   |  [   |  ]   |  >   |
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *		 |      |      |      |      |       |    |       |      |      |      |      |
 *               '-----------------------------------'    '-----------------------------------'
 */
[_LOWER] = LAYOUT(
//,-----------------------------------------------------.                          ,-----------------------------------------------------.
   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   _______, MV_DEGR, MV_ACUT, MV_GRV,  MV_CIRC, MV_TILD,                            MV_PIPE, MV_SLSH, MV_UNDS, MV_LPRN, MV_RPRN, _______,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   _______, MV_AT,   MV_QUES, MV_AMPR, MV_DQUO, MV_QUOT,                            MV_PLUS, MV_MINS, MV_SCLN, MV_LCBR, MV_RCBR, MV_LABK,
//|--------+--------+--------+--------+--------+--------| ====== .        , ====== |--------+--------+--------+--------+--------+--------|
   MV_BSLS, MV_HASH, MV_EXLM, MV_DLR,  MV_EURO, MV_PERC, _______,          _______, MV_ASTR, MV_EQL,  MV_COLN, MV_LBRC, MV_RBRC, MV_RABK,
//|--------+--------+--------+--------+--------+--------| ====== |        | ====== |--------+--------+--------+--------+--------+--------|
                     _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
//                  '--------+--------+--------+--------+--------'        '--------+--------+--------+--------+--------'
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |SCRLCK|PAUSE |      |SYSRQ |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | LCD^ | LCDv | FIND |      |                    | STLN | PWRD | NWRD | ENKL |DELLN | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |AGAIN | PSCN | MENU |INSERT| CAPS |                    | LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |      | UNDO | CUT  | COPY |PASTE |      |       |    |       | END  | PGDN | PGUP | HOME |      |      |
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *		 |      |      |      |      |       |    |       |      |      |      |      |
 *               '-----------------------------------'    '-----------------------------------'
 */
[_RAISE] = LAYOUT(
//,-----------------------------------------------------.                          ,-----------------------------------------------------.
   _______, XXXXXXX, KC_SCRL, KC_PAUS, XXXXXXX, KC_SYRQ,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   _______, XXXXXXX, KC_BRID, KC_BRIU, KC_FIND, XXXXXXX,                            MV_LNST, MV_WDPV, MV_WDNX, MV_LNEN, MV_LNDL, KC_DEL,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   _______, KC_AGIN, KC_PSCR, KC_APP,  KC_INS,  KC_CAPS,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------| ====== .        , ====== |--------+--------+--------+--------+--------+--------|
   _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX, _______,          _______, KC_END,  KC_PGDN, KC_PGUP, KC_HOME, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------| ====== |        | ====== |--------+--------+--------+--------+--------+--------|
                     _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
//                  '--------+--------+--------+--------+--------'        '--------+--------+--------+--------+--------'
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | NKRO |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |LN_TG |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |RGB_TG| HUE^ | SAT^ |LGHT^ |KB_TG |                    |      | VOLD | MUTE | VOLU |      |      |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |      |RGB_NX|      |      |      |OSX_TG|       |    |       |      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *		 |      |      |      |      |       |    |       |      |      |      |      |
 *               '-----------------------------------'    '-----------------------------------'
 */
[_ADJUST] = LAYOUT(
//,-----------------------------------------------------.                          ,-----------------------------------------------------.
   _______, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MV_OSX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, MV_KBLY,                            XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------| ====== .        , ====== |--------+--------+--------+--------+--------+--------|
   _______, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, MV_LANG, _______,          _______, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------| ====== |        | ====== |--------+--------+--------+--------+--------+--------|
                     _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
//                  '--------+--------+--------+--------+--------'        '--------+--------+--------+--------+--------'
),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |NumLck|   /  |   *  |   -  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |   4  |   5  |   4  |   =  |      |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |      |   1  |   2  |   3  |      |      |
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *		 |      |      |      |      |       |    |       |      |   0  |      |   ,  |
 *               '-----------------------------------'    '-----------------------------------'
 */
[_NUMPAD] = LAYOUT(
//,-----------------------------------------------------.                          ,-----------------------------------------------------.
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_BSPC,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PEQL, XXXXXXX,
//|--------+--------+--------+--------+--------+--------| ====== .        , ====== |--------+--------+--------+--------+--------+--------|
   _______, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          _______, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------| ====== |        | ====== |--------+--------+--------+--------+--------+--------|
                     _______, _______, _______, _______, _______,          XXXXXXX, XXXXXXX, KC_P0,   XXXXXXX, KC_PDOT
//                  '--------+--------+--------+--------+--------'        '--------+--------+--------+--------+--------'
),

/* SWITCH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |UNLOCK|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QK_BOT|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QK_RST|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |SLEEP |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *		 |      |      |      |      |       |    |       |      |      |      |      |
 *               '-----------------------------------'    '-----------------------------------'
 */
// layer switcher
[_SWITCH] = LAYOUT(
//,-----------------------------------------------------.                          ,-----------------------------------------------------.
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   QK_RBT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GAME,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COLEMAKDH,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------| ====== .        , ====== |--------+--------+--------+--------+--------+--------|
   KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SH_TG,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------| ====== |        | ====== |--------+--------+--------+--------+--------+--------|
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
//                  '--------+--------+--------+--------+--------'        '--------+--------+--------+--------+--------'
),
};

bool handle_action(keyrecord_t *record, uint16_t action_code) {
	if (record -> event.pressed) {
		register_code16(action_code);
	} else {
		unregister_code16(action_code);
	}
	return false;
}

bool harmonized_key_press(keyrecord_t *record, uint16_t keycode_en, uint16_t keycode_de, uint16_t keycode_en_osx, uint16_t keycode_de_osx) {
	if (is_german) {
		if (is_osx) {
			return handle_action(record, keycode_de_osx);
		} else {
			return handle_action(record, keycode_de);
		}
	} else {
		if (is_osx) {
			return handle_action(record, keycode_en_osx);
		} else {
			return handle_action(record, keycode_en);
		}
	}
}

bool handle_action_os_independent(keyrecord_t *record, uint16_t default_action, uint16_t osx_action) {
	if (is_osx) {
		return handle_action(record, osx_action);
	} else {
		return handle_action(record, default_action);
	}
}

bool change_default_layer(keyrecord_t *record, uint16_t next_layer) {
	if (record -> event.pressed) {
		set_single_persistent_default_layer(next_layer);
	}
	return false;
}

bool toggle_layer(keyrecord_t *record, uint16_t temp_layer) {
	if (record -> event.pressed) {
		layer_on(temp_layer);
	} else {
		layer_off(temp_layer);
	}
	update_tri_layer(_LOWER, _RAISE, _ADJUST);
	return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
		return change_default_layer(record, _QWERTY);
	case KC_GAME:
		return change_default_layer(record, _GAME);
        case KC_COLEMAKDH:
		return change_default_layer(record, _COLEMAKDH);
        case KC_LOWER:
		return toggle_layer(record, _LOWER);
        case KC_RAISE:
		return toggle_layer(record, _RAISE);
        case KC_ADJUST:
		return toggle_layer(record, _ADJUST);
	case MV_OSX:
		if (record -> event.pressed) {
			is_osx ^= 1;
			keymap_config.swap_lctl_lgui ^= 1;
			keymap_config.swap_rctl_rgui ^= 1;
		}
		return false;
	case MV_KBLY:
		if (get_highest_layer(default_layer_state) == _COLEMAKDH) {
			return change_default_layer(record, _QWERTY);
		} else {
			return change_default_layer(record, _COLEMAKDH);
		}
	case MV_LANG:
		if (record -> event.pressed) {
			is_german ^= 1;
		}
		return false;
	case MV_WDPV:
		return handle_action_os_independent(record, C(KC_LEFT), A(KC_LEFT));
        case MV_WDNX:
		return handle_action_os_independent(record, C(KC_RIGHT), A(KC_RIGHT));
        case MV_LNST:
		return handle_action_os_independent(record, KC_HOME, G(KC_LEFT));
        case MV_LNEN:
		return handle_action_os_independent(record, KC_END, G(KC_RIGHT));
        case MV_LNDL:
		if (is_osx) {
			handle_action(record, C(KC_A));
			return handle_action(record, C(KC_K));
		} else {
			return handle_action(record, C(KC_BSPC));
		}
        case KC_COPY:
		return handle_action_os_independent(record, C(KC_C), G(KC_C));
        case KC_PASTE:
		return handle_action_os_independent(record, C(KC_V), G(KC_V));
        case KC_CUT:
		return handle_action_os_independent(record, C(KC_X), G(KC_X));
        case KC_UNDO:
		if (is_german) {
			return handle_action_os_independent(record, C(DE_Z), G(DE_Z));
		} else {
			return handle_action_os_independent(record, C(KC_Z), G(KC_Z));
		}
        case KC_AGIN:
		if (is_german) {
			return handle_action_os_independent(record, C(DE_Y), G(DE_Y));
		} else {
			return handle_action_os_independent(record, C(KC_Y), G(KC_Y));
		}
        case KC_FIND:
		return handle_action_os_independent(record, C(KC_F), G(KC_F));
	case MV_Y:
		return PRESS_KEY(Y);
	case MV_Z:
		return PRESS_KEY(Z);
	case MV_DEGR:
		return PRESS_KEY_MISSING(DEG);
	case MV_ACUT:
		return PRESS_KEY_MISSING(ACUT);
	case MV_GRV:
		return PRESS_KEY(GRV);
	case MV_CIRC:
		return PRESS_KEY(CIRC);
	case MV_TILD:
		return PRESS_KEY(TILD);
	case MV_PIPE:
		return PRESS_KEY(PIPE);
	case MV_SLSH:
		return PRESS_KEY(SLSH);
	case MV_UNDS:
		return PRESS_KEY(UNDS);
	case MV_LPRN:
		return PRESS_KEY(LPRN);
	case MV_RPRN:
		return PRESS_KEY(RPRN);
	case MV_AT:
		return PRESS_KEY(AT);
	case MV_QUES:
		return PRESS_KEY(QUES);
	case MV_AMPR:
		return PRESS_KEY(AMPR);
	case MV_DQUO:
		return PRESS_KEY(DQUO);
	case MV_QUOT:
		return PRESS_KEY(QUOT);
	case MV_PLUS:
		return PRESS_KEY(PLUS);
	case MV_MINS:
		return PRESS_KEY(MINS);
	case MV_SCLN:
		return PRESS_KEY(SCLN);
	case MV_LCBR:
		return PRESS_KEY(LCBR);
	case MV_RCBR:
		return PRESS_KEY(RCBR);
	case MV_LABK:
		return PRESS_KEY(LABK);
	case MV_RABK:
		return PRESS_KEY(RABK);
	case MV_HASH:
		return PRESS_KEY(HASH);
	case MV_EXLM:
		return PRESS_KEY(EXLM);
	case MV_DLR:
		return PRESS_KEY(DLR);
	case MV_EURO:
		return PRESS_KEY_MISSING(EURO);
	case MV_BSLS:
		return PRESS_KEY(BSLS);
	case MV_ASTR:
		return PRESS_KEY(ASTR);
	case MV_EQL:
		return PRESS_KEY(EQL);
	case MV_COLN:
		return PRESS_KEY(COLN);
	case MV_LBRC:
		return PRESS_KEY(LBRC);
	case MV_RBRC:
		return PRESS_KEY(RBRC);
	case MV_PERC:
		return PRESS_KEY(PERC);
	case MV_ADIA:
		return PRESS_KEY_DIFFERENT(QUOT, ADIA);
	case MV_ODIA:
		return PRESS_KEY_DIFFERENT(SLSH, ODIA);
	case MV_UDIA:
		return PRESS_KEY_DIFFERENT(SCLN, UDIA);
	case MV_SS:
		return PRESS_KEY_DIFFERENT(GRV, SS);
    }
    return true;
}
