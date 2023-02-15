#ifdef ENCODER_ENABLE

#include "keymap_mine.h"

void either(bool is_ccw, uint16_t ccw, uint16_t cw) {
	if (is_ccw) {
	    tap_code16(ccw);
	} else {
	    tap_code16(cw);
	}
}

void change_layer(bool is_ccw, uint16_t ccw, uint16_t cw) {
	if (is_ccw) {
	    set_single_persistent_default_layer(ccw);
	} else {
	    set_single_persistent_default_layer(cw);
	}
}

void scroll_audio_volume(bool clockwise) {
	either(clockwise, KC_VOLD, KC_VOLU);
}

void scroll_page(bool clockwise) {
	either(clockwise, KC_PGUP, KC_PGDN);
}

void scroll_line(bool clockwise) {
	either(clockwise, KC_UP, KC_DOWN);
}

void scroll_mouse_wheel(bool clockwise) {
	either(clockwise, KC_WH_U, KC_WH_D);
}

void scroll_tab(bool clockwise) {
	either(clockwise, S(C(KC_TAB)), C(KC_TAB));
}

void scroll_word(bool clockwise) {
		either(clockwise, C(KC_LEFT), C(KC_RGHT));
}

void rotate_keymap(bool clockwise) {
	switch (get_highest_layer(default_layer_state)) {
		case _QWERTY:
			change_layer(clockwise, _COLEMAKDH, _GAME);
			break;
		case _GAME:
			change_layer(clockwise, _QWERTY, _COLEMAKDH);
			break;
		case _COLEMAKDH:
			change_layer(clockwise, _GAME, _QWERTY);
			break;
		default:
			break;
	}
}

void encoder_update_left_single(bool clockwise) {
	switch (get_highest_layer(layer_state)) {
		case _QWERTY:
		case _GAME:
		case _COLEMAKDH:
			scroll_audio_volume(clockwise);
			break;
		case _RAISE:
		case _LOWER:
			scroll_tab(clockwise);
			break;
		default:
			rotate_keymap(clockwise);
			break;
	}
}

void encoder_update_left_dual(bool clockwise) {
	switch (get_highest_layer(layer_state)) {
		case _QWERTY:
		case _GAME:
		case _COLEMAKDH:
			scroll_audio_volume(clockwise);
			break;
		case _RAISE:
		case _LOWER:
			scroll_tab(clockwise);
			break;
		default:
			rotate_keymap(clockwise);
			break;
	}
}

void encoder_update_left(bool clockwise) {
	if (is_transport_connected()) {
		encoder_update_left_dual(clockwise);
	} else {
		encoder_update_left_single(clockwise);
	}
}

void encoder_update_right(bool clockwise) {
	switch (get_highest_layer(layer_state)) {
		case _QWERTY:
		case _GAME:
		case _COLEMAKDH:
			scroll_page(clockwise);
			break;
		case _RAISE:
		case _LOWER:
			scroll_word(clockwise);
			break;
		default:
			scroll_mouse_wheel(clockwise);
			break;
	}
}

bool encoder_update_user(uint8_t index, bool clockwise) {
	if (index == 0) {
		encoder_update_left(clockwise);
	} else if (index == 1) {
		encoder_update_right(clockwise);
	}
	return true;
}

#endif
