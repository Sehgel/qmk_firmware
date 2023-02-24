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
    SWITCH_TO_QWERTY,
    SWITCH_TO_DVORAK,
    SWITCH_TO_WORKMAN
};

#define QWERTY 0
#define DVORAK 1
#define WORKMAN 2
#define NAVIGATION 3
#define NUMPAD 4
#define SYMBOLS 5
#define SHORTCUTS 6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
                    //QWERTY LAYOUT
                    [QWERTY] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                  MO(SHORTCUTS),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,KC_SCLN,  KC_QUOT,
                    //|--------+--------+--------+--------+--------+--------|       QWERTY       |--------+--------+--------+--------+--------+--------|
                        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                        KC_LALT, MO(NUMPAD), KC_SPC,    KC_ENT, MO(NAVIGATION), MO(SYMBOLS)
                                                        //`--------------------------'  `--------------------------'
                    ),
                    //DVORAK LAYOUT
                    [DVORAK] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TAB,KC_QUOTE,KC_COMMA,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,   KC_L,  KC_BSPC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                  MO(SHORTCUTS),    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,   KC_S, KC_SLASH,
                    //|--------+--------+--------+--------+--------+--------|       DVORAK       |--------+--------+--------+--------+--------+--------|
                        KC_LSFT, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,   KC_Z,  KC_RSFT,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                        KC_LALT, MO(NUMPAD), KC_SPC,    KC_ENT, MO(NAVIGATION), MO(SYMBOLS)
                                                        //`--------------------------'  `--------------------------'
                    ),
                    //WORKMAN LAYOUT
                    [WORKMAN] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TAB,    KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                         KC_J,    KC_F,    KC_U,    KC_P, KC_SCLN, KC_BSPC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                  MO(SHORTCUTS),    KC_A,    KC_S,    KC_H,    KC_T,    KC_G,                         KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,KC_QUOTE,
                    //|--------+--------+--------+--------+--------+--------|       WORKMAN      |--------+--------+--------+--------+--------+--------|
                        KC_LSFT,    KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,                         KC_K,    KC_L,KC_COMMA, KC_DOT,KC_SLASH, KC_RSFT,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                        KC_LALT, MO(NUMPAD), KC_SPC,    KC_ENT, MO(NAVIGATION), MO(SYMBOLS)
                                                        //`--------------------------'  `--------------------------'
                    ),

                    //NAVIGATION LAYER
                    [NAVIGATION] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_INS, KC_HOME,   KC_UP,  KC_END, KC_PGUP, KC_BSPC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_DEL, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN, KC_PSCR,
                    //|--------+--------+--------+--------+--------+--------|     NAVIGATION     |--------+--------+--------+--------+--------+--------|
                        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_INS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                        KC_LALT,  KC_LWIN,   KC_SPC,    KC_ENT,    KC_LALT, XXXXXXX
                                                        //`--------------------------'  `--------------------------'
                    ),

                    //NUMPAD LAYER
                    [NUMPAD] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_ESC, KC_PSLS,    KC_7,    KC_8,    KC_9, KC_BSPC,                        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                        KC_PMNS, KC_PAST,    KC_4,    KC_5,    KC_6, KC_PPLS,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  
                    //|--------+--------+--------+--------+--------+--------|       NUMPAD       |--------+--------+--------+--------+--------+--------|
                           KC_0, KC_PDOT,    KC_1,    KC_2,    KC_3, KC_PENT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                           KC_LWIN,  KC_LALT,  KC_SPC,   KC_ENT,   KC_LALT,  KC_RALT
                                                        //`--------------------------'  `--------------------------'
                    ),

                    //SYMBOLS LAYER
                    [SYMBOLS] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_MINS, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, KC_BSPC,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PIPE,  KC_EQL, KC_LBRC, KC_RBRC, KC_UNDS, KC_BSLS,
                    //|--------+--------+--------+--------+--------+--------|       SYMBOLS      |--------+--------+--------+--------+--------+--------|
  KC_LSFT,OPEN_QUESTION_MARK,SMALL_ENIE,BIG_ENIE,CLOSE_QUESTION_MARK,XXXXXXX,                      KC_CIRC, KC_PPLS, KC_LCBR, KC_RCBR, KC_GRV,   KC_GRV,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                        XXXXXXX ,   KC_LWIN,   KC_SPC,  KC_ENT,   XXXXXXX,   KC_RALT
                                                        //`--------------------------'  `--------------------------'
                    ),

                    //SHORTCUTS LAYER
                    [SHORTCUTS] = LAYOUT_split_3x6_3(
                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                   SWITCH_AUDIO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I, RGB_HUI, RGB_SAI, RGB_VAI,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K, KC_VOLD, KC_MUTE, KC_VOLU,
                    //|--------+--------+--------+--------+--------+--------|      SHORTCUTS     |--------+--------+--------+--------+--------+--------|
                        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, XXXXXXX, SWITCH_TO_QWERTY, SWITCH_TO_DVORAK, SWITCH_TO_WORKMAN,
                    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                            KC_LALT, KC_LWIN,  KC_SPC,     KC_ENT, XXXXXXX, KC_RALT
                                                        //`--------------------------'  `--------------------------'
                    ),

};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    /*
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }*/
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
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
bool oled_task_user(void) {/*
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }*/
    oled_render_logo();
    return false;
}
void suspend_power_down_user(void) {
    oled_off();
}

bool is_alt_engaged = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
   //set_keylog(keycode, record);
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
            case SWITCH_TO_QWERTY:
                set_single_persistent_default_layer(QWERTY);
                return true;
            case SWITCH_TO_DVORAK:
                set_single_persistent_default_layer(DVORAK);
                return true;
            case SWITCH_TO_WORKMAN:
                set_single_persistent_default_layer(WORKMAN);
                return true;
            case MO(6):
                register_code(KC_LCTL);
                return true;
        }
    }
    else{
        switch(keycode){
            case MO(6):
                unregister_code(KC_LCTL);
                return true;
        }
    }
    return true;
}
#endif // OLED_ENABLEk
