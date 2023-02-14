#ifdef OLED_ENABLE

#include "keymap_mine.h"
#include "shared_state.h"

#define PASS_ARRAY(x) x, sizeof(x)

/*
 * Generated with https://javl.github.io/image2cpp/ (32 x 16 px, scaled to fit, centered both axes, plain bytes, horizontal
 */
static const char PROGMEM gentoo_logo[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x7c, 0x7e, 0xfe, 0xff, 0xff, 0xf7,
	0xe7, 0xee, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x7e, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f,
	0x1f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM debian_logo[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x1c, 0x0e, 0x06, 0xc3, 0x33,
	0x13, 0x13, 0x03, 0x06, 0xfe, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0c, 0x10, 0x20, 0x40, 0x41,
	0x02, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM tux_logo[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x3e, 0x2b,
	0x01, 0x2b, 0xfc, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x26, 0x47, 0x48, 0x68, 0x20,
	0x20, 0x20, 0x2c, 0x47, 0x27, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM apple_logo[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0,
	0xfe, 0xf7, 0xf3, 0x70, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x3f, 0x7f, 0x7f, 0x3f,
	0x3f, 0x3f, 0x7f, 0x7e, 0x3c, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM larry_the_cow_logo[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x70, 0x50, 0x30, 0xdc, 0x1c, 0x10,
	0x10, 0x10, 0x3e, 0xf0, 0x38, 0x08, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x31, 0x41,
	0xe0, 0x70, 0x70, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM brand_of_sacrifice_logo[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x00, 0x04, 0x08,
	0xfe, 0x08, 0x04, 0x00, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x07, 0x0f, 0x1c, 0x38, 0x70, 0xe0, 0xc0,
	0xff, 0xc0, 0xe0, 0x70, 0x38, 0x1c, 0x0f, 0x07, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x70, 0xf8, 0xdc, 0x8e, 0x07, 0x03, 0x01,
	0xff, 0x01, 0x03, 0x07, 0x8e, 0xdc, 0xf8, 0x70, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0e, 0x1c,
	0x3f, 0x1c, 0x0e, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM font_keyboard[11] = {0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0};
static const char PROGMEM font_kb_split[11] = {0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0};
static const char PROGMEM font_kb_empty[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static const char PROGMEM font_state_base[6] = {0x85, 0x86, 0x87, 0x88, 0x89, 0};
static const char PROGMEM font_state_lower[6] = {0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0};
static const char PROGMEM font_state_raise[6] = {0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0};
static const char PROGMEM font_state_adjust[6] = {0xca, 0xcb, 0xcc, 0xcd, 0xce, 0};
static const char PROGMEM font_state_numpad[6] = {0xaa, 0xab, 0xac, 0xad, 0xae, 0};
static const char PROGMEM font_state_config[6] = {0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0};
static const char PROGMEM font_state_empty[6] = {0, 0, 0, 0, 0, 0};

static const char PROGMEM font_lang_german[6] = {0x80, 0x81, 0x82, 0x83, 0x84, 0};
static const char PROGMEM font_lang_english[6] = {0x20, 0x55, 0x53, 0x41, 0x20, 0};

void render_mod_ctrl(void) {
    static const char PROGMEM font_ctrl[3] = {0x93, 0x94, 0};
    oled_write_P(font_ctrl, false);
};

void render_mod_alt(void) {
    static const char PROGMEM font_alt[3] = {0xb3, 0xb4, 0};
    oled_write_P(font_alt, false);
};

void render_mod_shift(void) {
    static const char PROGMEM font_shift[3] = {0xd3, 0xd4, 0};
    oled_write_P(font_shift, false);
};

void render_mod_gui(void) {
    static const char PROGMEM font_gui[3] = {0x95, 0x96, 0};
    oled_write_P(font_gui, false);
};


bool get_state_leds(char* state_leds, char default_value) {
	led_t led_state = host_keyboard_led_state();
	state_leds[0] = led_state.scroll_lock ? 'S' : default_value;
	state_leds[1] = led_state.num_lock    ? 'N' : default_value;
	state_leds[2] = led_state.caps_lock   ? 'C' : default_value;
	return true;
}

int print_font_symbols_at(const char* logo, int start, int height) {
        oled_set_cursor(0, start);
	oled_write_P(logo, false);
	return start + height;
}

int print_raw_at(const char* logo, uint16_t len, int start, int height) {
        oled_set_cursor(0, start);
	oled_write_raw_P(logo, len);
	return start + height;
}

int print_header(int start) {
	if (is_osx) {
		return print_raw_at(PASS_ARRAY(apple_logo), start, 2);
	} else {
		return print_raw_at(PASS_ARRAY(tux_logo), start, 2);
	}
}

int print_language(int start) {
	print_font_symbols_at(is_german ? (char *) font_lang_german : (char *) font_lang_english, start, 1);
	return start + 1;
}

int print_keymap(int start) {
	char* keymap;
	switch (get_highest_layer(default_layer_state)) {
		case _QWERTY:
			keymap = (char*) font_keyboard;
			break;
		case _COLEMAKDH:
			keymap = (char*) font_kb_split;
			break;
		default:
			keymap = (char*) font_kb_empty;
			break;
	}
	return print_font_symbols_at(keymap, start, 2);
}

int print_layer(int start) {
	char* layer;
	switch (get_highest_layer(layer_state)) {
		case _QWERTY:
		case _COLEMAKDH:
			layer = (char*) font_state_base;
			break;
		case _RAISE:
			layer = (char*) font_state_raise;
			break;
		case _LOWER:
			layer = (char*) font_state_lower;
			break;
		case _ADJUST:
			layer = (char*) font_state_adjust;
			break;
		case _NUMPAD:
			layer = (char*) font_state_numpad;
			break;
		case _SWITCH:
			layer = (char*) font_state_config;
			break;
		default:
			layer = (char*) font_state_empty;
			break;
	}
	return print_font_symbols_at(layer, start, 1);
}

int print_state_leds(int start) {
	char BLANK = ' ';
	char state_leds[4] = { BLANK, BLANK, BLANK, 0 };
	get_state_leds(state_leds, BLANK);
	oled_write_P(PSTR(" "), false);
	oled_write_ln(state_leds, false);
	return start + 1;
}

void print_active_modifier(uint8_t modifiers, uint8_t mod_mask, void (*print_function)(void)) {
	if (modifiers & mod_mask) {
		print_function();
	} else {
		oled_write_P(PSTR("  "), false);
	}
}


int print_modifier_state(int start) {
	int offset = start;
	#ifdef NO_ACTION_ONESHOT
		uint8_t modifiers = get_mods();
	#else
		uint8_t modifiers = get_mods() | get_oneshot_mods();
	#endif

	print_active_modifier(modifiers, MOD_MASK_CTRL, render_mod_ctrl);
	oled_write_P(PSTR(" "), false);
	print_active_modifier(modifiers, MOD_MASK_SHIFT, render_mod_shift);

	print_active_modifier(modifiers, MOD_MASK_ALT, render_mod_alt);
	oled_write_P(PSTR(" "), false);
	print_active_modifier(modifiers, MOD_MASK_GUI, render_mod_gui);

	return offset + 2;
}

int print_berserk(int start) {
	return print_raw_at(PASS_ARRAY(brand_of_sacrifice_logo), start, 2);
}

static void print_status_narrow(void) {
	int offset = 0;
	offset = print_header(offset);
	offset = print_keymap(offset);
	offset = print_language(offset);
	offset = print_layer(offset);
	offset = print_state_leds(offset);
	offset = print_modifier_state(offset);
	offset = print_berserk(12);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_270;
}

bool oled_task_user(void) {
	print_status_narrow();
    	return false;
}

#endif
