/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

enum{
    QWERTY = SAFE_RANGE,
    OPEN_QUESTION_MARK,
    SMALL_ENIE,
    BIG_ENIE,
    CLOSE_QUESTION_MARK,
    SWITCH_AUDIO,
    TO_QWERTY,
    TO_DVORAK,
    TO_WORKMAN,
    TO_COLEMAK_DH,
    TO_BEAKL43,
    UC_TO_WINC,
    UC_TO_LINUX,
    UC_TO_MAC,
    CTL_MOD,
    SHIFT_CRTL_ALT_MOD,
    EMOJI_KEY
};

#define QWERTY 0
#define DVORAK 1
#define WORKMAN 2
#define COLEMAK_DH 3
#define BEAKL43 4
#define NAVIGATION 5
#define NUMPAD 6
#define SYMBOLS 7
#define SHORTCUTS 8
#define ALT 9
#define NUMPAD2 10
#define GAMEPLAY_NUMPAD 11

enum unicode_names {
    L_QUESTION,
    L_ENIE,
    U_ENIE,
    R_QUESTION,
    L_EXCLAMATION,
};

#define ENIE XP(L_ENIE, U_ENIE)

const uint32_t unicode_map[] PROGMEM = {
    [L_QUESTION]  = L'¿',
    [L_ENIE] = L'ñ',
    [U_ENIE] = L'Ñ',
    [R_QUESTION]  = L'?',
    [L_EXCLAMATION]  = L'¡'
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
                    //QWERTY LAYOUT
                    [QWERTY] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_RCTL,
                    //|--------+--------+--------+--------+--------+--------|       QWERTY       |--------+--------+--------+--------+--------+--------|
                        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,KC_QUOTE, KC_RSFT,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                          KC_LALT, MO(GAMEPLAY_NUMPAD), KC_SPC,    KC_ENT, MO(NAVIGATION), MO(SYMBOLS)
                                                        //`--------------------------'  `--------------------------'
                    ),

                    //DVORAK LAYOUT
                    [DVORAK] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TAB,KC_QUOTE,KC_COMMA,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_BSPC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                  MO(SHORTCUTS),    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,MO(SHORTCUTS),
                    //|--------+--------+--------+--------+--------+--------|       DVORAK       |--------+--------+--------+--------+--------+--------|
                        KC_LSFT, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_RSFT,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                          KC_LALT, MO(NUMPAD), KC_SPC,    KC_ENT, MO(NAVIGATION), MO(SYMBOLS)
                                                        //`--------------------------'  `--------------------------'
                    ),

                    //WORKMAN LAYOUT
                    [WORKMAN] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TAB,    KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                         KC_J,    KC_F,    KC_U,    KC_P,KC_QUOTE, KC_BSPC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                        KC_LCTL,    KC_A,    KC_S,    KC_H,    KC_T,    KC_G,                         KC_Y,    KC_N,    KC_E,    KC_O,    KC_I, KC_RCTL,
                    //|--------+--------+--------+--------+--------+--------|       WORKMAN      |--------+--------+--------+--------+--------+--------|
                        KC_LSFT,    KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,                         KC_K,    KC_L,KC_COMMA,  KC_DOT, KC_SCLN, KC_RSFT,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                           KC_LALT, MO(NUMPAD), KC_SPC,    KC_ENT, MO(NAVIGATION), MO(SYMBOLS)
                                                        //`--------------------------'  `--------------------------'
                    ),

                    //COLEMAK_DH LAYOUT
                    [COLEMAK_DH] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,  KC_DOT, KC_BSPC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                        KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_RCTL,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_SCLN,KC_QUOTE,KC_COMMA, KC_RSFT,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                           KC_LALT, MO(NUMPAD), KC_SPC,    KC_ENT, MO(NAVIGATION), MO(SYMBOLS)
                                                        //`--------------------------'  `--------------------------'
                    ),

                    //BEAKL27 LAYOUT
                    [BEAKL43] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TAB,    KC_Q,    KC_H,    KC_O,    KC_U,KC_COMMA,                         KC_G,    KC_L,    KC_R,    KC_F,    KC_B, KC_BSPC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                  MO(SHORTCUTS),    KC_J,    KC_I,    KC_E,    KC_A,    KC_Y,                         KC_D,    KC_T,    KC_S,    KC_N,    KC_P, KC_RCTL,
                    //|--------+--------+--------+--------+--------+--------|       BEAKL43      |--------+--------+--------+--------+--------+--------|
                        KC_LSFT,    KC_X,    KC_K, KC_SCLN, KC_QUOTE, KC_DOT,                         KC_V,    KC_M,    KC_C,    KC_W,    KC_Z, KC_RSFT,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                          KC_LALT, MO(NUMPAD), KC_SPC,  KC_ENT, MO(NAVIGATION), MO(SYMBOLS)
                                                        //`--------------------------'  `--------------------------'
                    ),

                    //NAVIGATION LAYER
                    [NAVIGATION] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TAB,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_INS, KC_HOME,   KC_UP,  KC_END, KC_PGUP, KC_BSPC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                        KC_LCTL,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                       KC_DEL, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN, KC_LWIN,
                    //|--------+--------+--------+--------+--------+--------|     NAVIGATION     |--------+--------+--------+--------+--------+--------|
                        KC_LSFT,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                       KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_APP,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                KC_LALT,  SHIFT_CRTL_ALT_MOD,  KC_SPC,     KC_ENT, KC_LALT,  KC_F21
                                                        //`--------------------------'  `--------------------------'
                    ),

                    //NUMPAD LAYER
                    //PPLS = +
                    //PMNS = -
                    //PAST = *
                    //PSLS = /
                    //
                    [NUMPAD] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_ESC,  KC_DEL,   KC_P7,   KC_P8,   KC_P9, KC_BSPC,                      KC_PSCR, RGB_HUI, RGB_SAI, RGB_VAI, KC_MNXT, UNICODE_MODE_WINC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                          KC_P0, KC_PSLS,   KC_P4,   KC_P5,   KC_P6, KC_PAST,                      KC_MPLY, KC_VOLD, KC_MUTE, KC_VOLU, KC_MPRV, UNICODE_MODE_LNX,
                    //|--------+--------+--------+--------+--------+--------|       NUMPAD       |--------+--------+--------+--------+--------+--------|
                         KC_DOT, KC_PMNS,   KC_P1,   KC_P2,   KC_P3, KC_PPLS,         TO_QWERTY, TO_DVORAK,TO_WORKMAN,TO_COLEMAK_DH,TO_BEAKL43, UNICODE_MODE_MAC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                             KC_SPC,KC_LALT, KC_ENT,      KC_ENT, KC_LSFT, MO(NUMPAD2)
                                                        //`--------------------------'  `--------------------------'
                    ),

                    //NUMPAD2 LAYER
                    [NUMPAD2] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                        XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    //|--------+--------+--------+--------+--------+--------|       NUMPAD2      |--------+--------+--------+--------+--------+--------|
                        KC_LSFT, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                            KC_LALT, KC_RALT,  KC_SPC,   KC_ENT,   KC_LALT, KC_RALT
                                                        //`--------------------------'  `--------------------------'
                    ),

                    //GAMEPLAY LAYER TODO: Change the Fs from the left side.
                    [GAMEPLAY_NUMPAD] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                        KC_PMNS,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
                    //|--------+--------+--------+--------+--------+--------|  GAMEPLAY NUMPAD   |--------+--------+--------+--------+--------+--------|
                        KC_LSFT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_ENT,           TO_QWERTY, TO_DVORAK,TO_WORKMAN,TO_COLEMAK_DH,TO_BEAKL43, XXXXXXX,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                            KC_LALT, KC_RALT,  KC_SPC,   KC_ENT,   KC_LALT, KC_RALT
                                                        //`--------------------------'  `--------------------------'
                    ),

                    //SYMBOLS LAYER TODO: Minus in right side is duplicated, find a replacement
                    [SYMBOLS] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
               X(L_EXCLAMATION), KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_MINS, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, KC_BSPC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                        KC_TILD, KC_BSLS, KC_LABK, KC_RABK, KC_PSLS, KC_UNDS,                     KC_MINUS,  KC_EQL, KC_LBRC, KC_RBRC, KC_PPLS, KC_CIRC,
                    //|--------+--------+--------+--------+--------+--------|       SYMBOLS      |--------+--------+--------+--------+--------+--------|
               KC_LSFT, X(L_EXCLAMATION),X(L_QUESTION),ENIE,KC_QUES, KC_EXLM,                       KC_GRV, KC_PIPE, KC_LCBR, KC_RCBR,EMOJI_KEY, KC_RSFT,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                        XXXXXXX ,   XXXXXXX,   KC_SPC,  KC_ENT,   XXXXXXX,   KC_RALT
                                                        //`--------------------------'  `--------------------------'
                    ),

                    //SHORTCUTS LAYER
                    [SHORTCUTS] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_RCTL,
                    //|--------+--------+--------+--------+--------+--------|     SHORTCUTS      |--------+--------+--------+--------+--------+--------|
                        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,KC_QUOTE, KC_RSFT,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                       KC_LALT, SWITCH_AUDIO,  KC_SPC,     KC_ENT, XXXXXXX, KC_RALT
                                                        //`--------------------------'  `--------------------------'
                    ),

                    //ALT LAYER
                    [ALT] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_B,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_RCTL,
                    //|--------+--------+--------+--------+--------+--------|    ALT SHORTCUTS   |--------+--------+--------+--------+--------+--------|
                        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_V,                         KC_N,    KC_M, KC_COMM,  KC_DOT,KC_QUOTE, KC_RSFT,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                           KC_LALT,SWITCH_AUDIO,KC_SPC,  KC_ENT,   XXXXXXX, KC_LWIN
                                                        //`--------------------------'  `--------------------------'
                    )

};


uint32_t layer_state_set_user(uint32_t state) {
  switch(biton32(state)) {
    case NUMPAD:
        // turn on numlock, if it isn't already on.
        if (!(host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))) {
        register_code(KC_NUMLOCK);
        unregister_code(KC_NUMLOCK);
        }
        break;
  }
  return state;
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (true) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_type_layer(void) {
    //oled_write_P(PSTR("Mode: \n"), false);
    switch(get_highest_layer(default_layer_state)){
        case QWERTY:
            oled_write_ln_P(PSTR("Qwerty"),false);
            break;
        case DVORAK:
            oled_write_ln_P(PSTR("Dvorak"),false);
            break;
        case WORKMAN:
            oled_write_ln_P(PSTR("Workman"),false);
            break;
        case COLEMAK_DH:
            oled_write_ln_P(PSTR("Colemak-DH"),false);
            break;
        case BEAKL43:
            oled_write_ln_P(PSTR("Beakl43"),false);
            break;
    }
}
void oled_render_input_layer(void) {
    //oled_write_ln_P(PSTR("\n"),false);
    switch (get_unicode_input_mode()) {
        case UC_LNX:
            oled_write_ln_P(PSTR("Linux"),false);
            break;
        case UC_OSX:
            oled_write_ln_P(PSTR("MacOS"),false);
            break;
        case UC_WINC:
            oled_write_ln_P(PSTR("Windows"),false);
            break;
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
    0};
    oled_write_P(crkbd_logo, false);
}
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_input_layer();
    } else {
        oled_render_type_layer();
    }
    return true;
}
void suspend_power_down_user(void) {
    oled_off();
}

bool ctl_interrupted = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        ctl_interrupted = true;
        switch(keycode){
            case OPEN_QUESTION_MARK:
                register_code(KC_LALT);
                tap_code(KC_P1);
                tap_code(KC_P6);
                tap_code(KC_P8);
                unregister_code(KC_LALT);
                return true;
            case SMALL_ENIE:
                register_code(KC_LALT);
                tap_code(KC_P1);
                tap_code(KC_P6);
                tap_code(KC_P4);
                unregister_code(KC_LALT);
                return true;
            case BIG_ENIE:
                register_code(KC_LALT);
                tap_code(KC_P1);
                tap_code(KC_P6);
                tap_code(KC_P5);
                unregister_code(KC_LALT);
                return true;
            case CLOSE_QUESTION_MARK:
                register_code(KC_LALT);
                tap_code(KC_P6);
                tap_code(KC_P3);
                unregister_code(KC_LALT);
                return true;
            case SWITCH_AUDIO:
                register_code(KC_LALT);
                tap_code(KC_F1);
                unregister_code(KC_LALT);
                return true;
            case TO_QWERTY:
                set_single_persistent_default_layer(QWERTY);
                return true;
            case TO_DVORAK:
                set_single_persistent_default_layer(DVORAK);
                return true;
            case TO_WORKMAN:
                set_single_persistent_default_layer(WORKMAN);
                return true;
            case TO_COLEMAK_DH:
                set_single_persistent_default_layer(COLEMAK_DH);
                return true;
            case TO_BEAKL43:
                set_single_persistent_default_layer(BEAKL43);
                return true;
            case SHIFT_CRTL_ALT_MOD:
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
            case MO(SHORTCUTS):
                register_code(KC_LCTL);
                return true;
            case EMOJI_KEY:
                register_code(KC_LWIN);
                tap_code(KC_DOT);
                unregister_code(KC_LWIN);
                return true;
        }
    }
    else {
        switch(keycode){
            case SHIFT_CRTL_ALT_MOD:
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                return true;
            case MO(SHORTCUTS):
                unregister_code(KC_LCTL);
                return true;
        }
    }
    return true;
}
#endif // OLED_ENABLEk
