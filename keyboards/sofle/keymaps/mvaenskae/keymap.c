#include QMK_KEYBOARD_H
#include <split_util.h>
#include <keymap_german.h>
#include "keymap_mine.h"
#include "encoder.c"
#include "oled.c"
#include "shared_state.h"
#include "rgb_light.c"

enum custom_keycodes {
    KC_COLEMAKDH = SAFE_RANGE,
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
    MV_GRAV,
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
    MV_SCOL,
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

volatile bool is_german = false;
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
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    LT(_SWITCH, KC_5),                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MV_SS,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   LT(_NUMPAD, KC_TAB), KC_Q, KC_W, KC_F, KC_P, KC_B,                               KC_J,    KC_L,    KC_U,    MV_Y,    MV_UDIA, KC_BSPC,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   KC_LSFT, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_RSFT,
//|--------+--------+--------+--------+--------+--------| ====== .        , ====== |--------+--------+--------+--------+--------+--------|
   XXXXXXX, MV_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_MUTE,          XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,  MV_ODIA, MV_ADIA,
//|--------+--------+--------+--------+--------+--------| ====== |        | ====== |--------+--------+--------+--------+--------+--------|
                     KC_LCTL, KC_LGUI, KC_LALT, KC_LOWER, KC_ENT,          KC_SPC,  KC_RAISE,KC_RALT, KC_RGUI, KC_RCTL
//                  '--------+--------+--------+--------+--------'        '--------+--------+--------+--------+--------'
),

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
   _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               MV_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    MV_UDIA, _______,
//|--------+--------+--------+--------+--------+--------| ====== .        , ====== |--------+--------+--------+--------+--------+--------|
   XXXXXXX, MV_Z,    KC_X,    KC_C,    KC_V,    KC_D,    _______,          _______, KC_N,    KC_M,    _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------| ====== |        | ====== |--------+--------+--------+--------+--------+--------|
                     _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
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
   _______, MV_DEGR, MV_ACUT, MV_GRAV, MV_CIRC, MV_TILD,                            MV_PIPE, MV_SLSH, MV_UNDS, MV_LPRN, MV_RPRN, _______,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   _______, MV_AT,   MV_QUES, MV_AMPR, MV_DQUO, MV_QUOT,                            MV_PLUS, MV_MINS, MV_SCOL, MV_LCBR, MV_RCBR, MV_LABK,
//|--------+--------+--------+--------+--------+--------| ====== .        , ====== |--------+--------+--------+--------+--------+--------|
   MV_BSLS, MV_HASH, MV_EXLM, MV_DLR,  MV_EURO, MV_PERC, XXXXXXX,          XXXXXXX, MV_ASTR, MV_EQL,  MV_COLN, MV_LBRC, MV_RBRC, MV_RABK,
//|--------+--------+--------+--------+--------+--------| ====== |        | ====== |--------+--------+--------+--------+--------+--------|
                     _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
//                  '--------+--------+--------+--------+--------'        '--------+--------+--------+--------+--------'
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |SCRLCK|PAUSE |      |SYSRQ |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | LCD^ | LCDv | FIND |      |                    | PWRD | END  | HOME | NWRD |      | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |AGAIN | PSCN | MENU |INSERT| CAPS |                    | LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |      | UNDO | CUT  | COPY |PASTE |      |       |    |       |ST_LN | PGUP | PGDN |EN_LN |DEL_LN|      |
 * `-----------------------------------------|-------|    |-------|-----------------------------------------'
 *		 |      |      |      |      |       |    |       |      |      |      |      |
 *               '-----------------------------------'    '-----------------------------------'
 */
[_RAISE] = LAYOUT(
//,-----------------------------------------------------.                          ,-----------------------------------------------------.
   _______, XXXXXXX, KC_SCRL, KC_PAUS, XXXXXXX, KC_SYRQ,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   _______, XXXXXXX, KC_BRID, KC_BRIU, KC_FIND, XXXXXXX,                            MV_WDPV, KC_END,  KC_HOME, MV_WDNX, XXXXXXX, KC_DEL,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   _______, KC_AGIN, KC_PSCR, KC_APP,  KC_INS,  KC_CAPS,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------| ====== .        , ====== |--------+--------+--------+--------+--------+--------|
   _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX, XXXXXXX,          XXXXXXX, MV_LNST, KC_PGDN, KC_PGUP, MV_LNEN, MV_LNDL, _______,
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
   _______, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, MV_LANG,  XXXXXXX,         XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, _______,
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
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PEQL, XXXXXXX,
//|--------+--------+--------+--------+--------+--------| ====== .        , ====== |--------+--------+--------+--------+--------+--------|
   _______, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,         XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   XXXXXXX, XXXXXXX,
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
   QK_RBT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
   EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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

bool harmonized_key_press(keyrecord_t *record, uint16_t keycode_en, uint16_t keycode_de) {
	if (is_german) {
		return handle_action(record, keycode_de);
	} else {
		return handle_action(record, keycode_en);
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
		if (record -> event.pressed) {
			if (get_highest_layer(default_layer_state) == _COLEMAKDH) {
				set_single_persistent_default_layer(_QWERTY);
			} else {
				set_single_persistent_default_layer(_COLEMAKDH);
			}
		}
		return false;
	case MV_LANG:
		if (record -> event.pressed) {
			is_german ^= 1;
		}
		return false;
	case MV_WDPV:
		return handle_action_os_independent(record, LCTL(KC_LEFT), LALT(KC_LEFT));
        case MV_WDNX:
		return handle_action_os_independent(record, LCTL(KC_RIGHT), LALT(KC_RIGHT));
        case MV_LNST:
		return handle_action_os_independent(record, KC_HOME, LCTL(KC_LEFT));
        case MV_LNEN:
		return handle_action_os_independent(record, KC_END, LCTL(KC_RIGHT));
        case MV_LNDL:
		return handle_action(record, LCTL(KC_BSPC));
        case KC_COPY:
		return handle_action(record, LCTL(KC_C));
        case KC_PASTE:
		return handle_action(record, LCTL(KC_V));
        case KC_CUT:
		return handle_action(record, LCTL(KC_X));
        case KC_UNDO:
		return handle_action(record, LCTL(MV_Z));
	case MV_Y:
	    	return harmonized_key_press(record, KC_Y, DE_Y);
	case MV_Z:
		return harmonized_key_press(record, KC_Z, DE_Z);
	case MV_DEGR:
		return harmonized_key_press(record, DE_DEG, DE_DEG);
	case MV_ACUT:
		return harmonized_key_press(record, DE_ACUT, DE_ACUT);
	case MV_GRAV:
		return harmonized_key_press(record, KC_GRV, DE_GRV);
	case MV_CIRC:
		return harmonized_key_press(record, KC_CIRC, DE_CIRC);
	case MV_TILD:
		return harmonized_key_press(record, KC_TILD, DE_TILD);
	case MV_PIPE:
		return harmonized_key_press(record, KC_PIPE, DE_PIPE);
	case MV_SLSH:
		return harmonized_key_press(record, KC_SLSH, DE_SLSH);
	case MV_UNDS:
		return harmonized_key_press(record, KC_UNDS, DE_UNDS);
	case MV_LPRN:
		return harmonized_key_press(record, KC_LPRN, DE_LPRN);
	case MV_RPRN:
		return harmonized_key_press(record, KC_RPRN, DE_RPRN);
	case MV_AT:
		return harmonized_key_press(record, KC_AT, DE_AT);
	case MV_QUES:
		return harmonized_key_press(record, KC_QUES, DE_QUES);
	case MV_AMPR:
		return harmonized_key_press(record, KC_AMPR, DE_AMPR);
	case MV_DQUO:
		return harmonized_key_press(record, KC_DQUO, DE_DQUO);
	case MV_QUOT:
		return harmonized_key_press(record, KC_QUOT, DE_QUOT);
	case MV_PLUS:
		return harmonized_key_press(record, KC_PLUS, DE_PLUS);
	case MV_MINS:
		return harmonized_key_press(record, KC_MINS, DE_MINS);
	case MV_SCOL:
		return harmonized_key_press(record, KC_SCLN, DE_SCLN);
	case MV_LCBR:
		return harmonized_key_press(record, KC_LCBR, DE_LCBR);
	case MV_RCBR:
		return harmonized_key_press(record, KC_RCBR, DE_RCBR);
	case MV_LABK:
		return harmonized_key_press(record, KC_LABK, DE_LABK);
	case MV_RABK:
		return harmonized_key_press(record, KC_RABK, DE_RABK);
	case MV_HASH:
		return harmonized_key_press(record, KC_HASH, DE_HASH);
	case MV_EXLM:
		return harmonized_key_press(record, KC_EXLM, DE_EXLM);
	case MV_DLR:
		return harmonized_key_press(record, KC_DLR, DE_DLR);
	case MV_EURO:
		return harmonized_key_press(record, DE_EURO, DE_EURO);
	case MV_BSLS:
		return harmonized_key_press(record, KC_BSLS, DE_BSLS);
	case MV_ASTR:
		return harmonized_key_press(record, KC_ASTR, DE_ASTR);
	case MV_EQL:
		return harmonized_key_press(record, KC_EQL, DE_EQL);
	case MV_COLN:
		return harmonized_key_press(record, KC_COLN, DE_COLN);
	case MV_LBRC:
		return harmonized_key_press(record, KC_LBRC, DE_LBRC);
	case MV_RBRC:
		return harmonized_key_press(record, KC_RBRC, DE_RBRC);
	case MV_PERC:
		return harmonized_key_press(record, KC_PERC, DE_PERC);
	case MV_ADIA:
		return harmonized_key_press(record, KC_QUOT, DE_ADIA);
	case MV_ODIA:
		return harmonized_key_press(record, KC_SLSH, DE_ODIA);
	case MV_UDIA:
		return harmonized_key_press(record, KC_SCLN, DE_UDIA);
	case MV_SS:
		return harmonized_key_press(record, KC_GRV, DE_SS);
    }
    return true;
}
