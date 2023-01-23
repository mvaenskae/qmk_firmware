#ifdef ENCODER_ENABLE

#include "keymap.h"

void either(bool is_clockwise, uint16_t clockwise, uint16_t counter_clockwise) {
	if (is_clockwise) {
	    tap_code(clockwise);
	} else {
	    tap_code(counter_clockwise);
	}
}

void scroll_audio_volume(bool clockwise) {
	either(clockwise, KC_VOLD, KC_VOLU);
}

void scroll_page(bool clockwise) {
	either(clockwise, KC_PGDN, KC_PGUP);
}

void scroll_line(bool clockwise) {
	either(clockwise, KC_DOWN, KC_UP);
}

void scroll_mouse_wheel(bool clockwise) {
	either(clockwise, KC_WH_D, KC_WH_U);
}

void rotate_keymaps(void) {
	switch (get_highest_layer(default_layer_state)) {
		case _QWERTY:
			set_single_persistent_default_layer(_COLEMAKDH);
			break;
		case _COLEMAKDH:
			set_single_persistent_default_layer(_QWERTY);
			break;
		default:
			break;
	}
}


void encoder_update_left_single(bool clockwise) {
	switch (get_highest_layer(layer_state)) {
		case _QWERTY:
		case _COLEMAKDH:
			rotate_keymaps();
			break;
		default:
			scroll_audio_volume(clockwise);
	}
}

void encoder_update_left_dual(bool clockwise) {
	switch (get_highest_layer(layer_state)) {
		case _QWERTY:
		case _COLEMAKDH:
			rotate_keymaps();
			break;
		default:
			scroll_audio_volume(clockwise);
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
		case _COLEMAKDH:
			scroll_page(clockwise);
			break;
		case _RAISE:
		case _LOWER:
			scroll_line(clockwise);
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
