/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
//#include "muse.h"


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
    SCAM,
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
#define NUMPAD2 10
#define GAMEPLAY_NUMPAD 11
#define FUNCTIONS 12

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

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[QWERTY] = LAYOUT_planck_grid(
	//---------------------------------------------------------------------------------------------------------------------------------------
	KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R               ,KC_T  ,/*------------------*/KC_Y  ,KC_U          ,KC_I         ,KC_O       ,KC_P    ,KC_BSPC,
	//---------------------------------------------------------------------------------------------------------------------------------------
	KC_LCTL,KC_A   ,KC_S   ,KC_D   ,KC_F               ,KC_G  ,/*------------------*/KC_H  ,KC_J          ,KC_K         ,KC_L       ,KC_SCLN ,KC_RCTL,
	//---------------------------------------------------------------------------------------------------------------------------------------
	KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V               ,KC_B  ,/*------------------*/KC_N  ,KC_M          ,KC_COMM      ,KC_DOT     ,KC_QUOTE,KC_RSFT,
	//---------------------------------------------------------------------------------------------------------------------------------------
	XXXXXXX,XXXXXXX,KC_LWIN,KC_LALT,MO(GAMEPLAY_NUMPAD),KC_SPC,/*------------------*/KC_ENT,MO(NAVIGATION),MO(SYMBOLS),MO(FUNCTIONS),XXXXXXX ,XXXXXXX
	//---------------------------------------------------------------------------------------------------------------------------------------
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[DVORAK] = LAYOUT_planck_grid(
	//----------------------------------------------------------------------------------------------------------------------------------------------------
	KC_TAB       ,KC_QUOTE,KC_COMMA,KC_DOT ,KC_P      ,KC_Y  ,/*------------------*/KC_F  ,KC_G          ,KC_C         ,KC_R       ,KC_L   ,KC_BSPC      ,
	//----------------------------------------------------------------------------------------------------------------------------------------------------
	MO(SHORTCUTS),KC_A    ,KC_O    ,KC_E   ,KC_U      ,KC_I  ,/*------------------*/KC_D  ,KC_H          ,KC_T         ,KC_N       ,KC_S   ,MO(SHORTCUTS),
	//----------------------------------------------------------------------------------------------------------------------------------------------------
	KC_LSFT      ,KC_SCLN ,KC_Q    ,KC_J   ,KC_K      ,KC_X  ,/*------------------*/KC_B  ,KC_M          ,KC_W         ,KC_V       ,KC_Z   ,KC_RSFT      ,
	//----------------------------------------------------------------------------------------------------------------------------------------------------
	XXXXXXX      ,XXXXXXX ,KC_LWIN ,KC_LALT,MO(NUMPAD),KC_SPC,/*------------------*/KC_ENT,MO(NAVIGATION),MO(SYMBOLS),MO(FUNCTIONS),XXXXXXX,XXXXXXX      
	//----------------------------------------------------------------------------------------------------------------------------------------------------      
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[WORKMAN] = LAYOUT_planck_grid(
	//---------------------------------------------------------------------------------------------------------------------------------------
	KC_TAB ,KC_Q   ,KC_D   ,KC_R   ,KC_W      ,KC_B  ,/*------------------*/KC_J  ,KC_F          ,KC_U         ,KC_P       ,KC_QUOTE,KC_BSPC,
	//---------------------------------------------------------------------------------------------------------------------------------------
	KC_LCTL,KC_A   ,KC_S   ,KC_H   ,KC_T      ,KC_G  ,/*------------------*/KC_Y  ,KC_N          ,KC_E         ,KC_O       ,KC_I    ,KC_RCTL,
	//---------------------------------------------------------------------------------------------------------------------------------------
	KC_LSFT,KC_Z   ,KC_X   ,KC_M   ,KC_C      ,KC_V  ,/*------------------*/KC_K  ,KC_L          ,KC_COMMA     ,KC_DOT     ,KC_SCLN ,KC_RSFT,
	//---------------------------------------------------------------------------------------------------------------------------------------
	XXXXXXX,XXXXXXX,KC_LWIN,KC_LALT,MO(NUMPAD),KC_SPC,/*------------------*/KC_ENT,MO(NAVIGATION),MO(SYMBOLS),MO(FUNCTIONS),XXXXXXX ,XXXXXXX
	//---------------------------------------------------------------------------------------------------------------------------------------
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[COLEMAK_DH]=LAYOUT_planck_grid(
	//---------------------------------------------------------------------------------------------------------------------------------------
	KC_TAB ,KC_Q   ,KC_W   ,KC_F   ,KC_P      ,KC_B  ,/*------------------*/KC_J  ,KC_L          ,KC_U         ,KC_Y       ,KC_DOT  ,KC_BSPC,
	//---------------------------------------------------------------------------------------------------------------------------------------
	KC_LCTL,KC_A   ,KC_R   ,KC_S   ,KC_T      ,KC_G  ,/*------------------*/KC_M  ,KC_N          ,KC_E         ,KC_I       ,KC_O    ,KC_RCTL,
	//---------------------------------------------------------------------------------------------------------------------------------------
	KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_D      ,KC_V  ,/*------------------*/KC_K  ,KC_H          ,KC_SCLN      ,KC_QUOTE   ,KC_COMMA,KC_RSFT,
	//---------------------------------------------------------------------------------------------------------------------------------------
	XXXXXXX,XXXXXXX,KC_LWIN,KC_LALT,MO(NUMPAD),KC_SPC,/*------------------*/KC_ENT,MO(NAVIGATION),MO(SYMBOLS),MO(FUNCTIONS),XXXXXXX ,XXXXXXX
	//---------------------------------------------------------------------------------------------------------------------------------------
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[BEAKL43]=LAYOUT_planck_grid(
	//---------------------------------------------------------------------------------------------------------------------------------------------------
	KC_TAB       ,KC_Q   ,KC_H   ,KC_O   ,KC_U      ,KC_P  ,/*------------------*/KC_G  ,KC_L          ,KC_R         ,KC_F       ,KC_B         ,KC_BSPC ,
	//---------------------------------------------------------------------------------------------------------------------------------------------------
	MO(SHORTCUTS),KC_J   ,KC_I   ,KC_E   ,KC_A      ,KC_Y  ,/*------------------*/KC_D  ,KC_T          ,KC_S         ,KC_N       ,MO(SHORTCUTS),KC_QUOTE,
	//---------------------------------------------------------------------------------------------------------------------------------------------------
	KC_LSFT      ,KC_X   ,KC_K   ,KC_DOT ,KC_COMMA  ,KC_SCLN,/*------------------*/KC_V ,KC_M          ,KC_C         ,KC_W       ,KC_Z         ,KC_RSFT ,
	//---------------------------------------------------------------------------------------------------------------------------------------------------
	XXXXXXX      ,XXXXXXX,KC_LWIN,KC_LALT,MO(NUMPAD),KC_SPC,/*------------------*/KC_ENT,MO(NAVIGATION),MO(SYMBOLS),MO(FUNCTIONS),XXXXXXX      ,XXXXXXX 
	//---------------------------------------------------------------------------------------------------------------------------------------------------
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[NAVIGATION]=LAYOUT_planck_grid(
  //--------------------------------------------------------------------------------------------------------------------
  KC_TAB ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,/*------------------*/KC_INS,KC_HOME,KC_UP  ,KC_END  ,KC_PGUP,KC_BSPC,
  //--------------------------------------------------------------------------------------------------------------------
  KC_LCTL,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,/*------------------*/KC_DEL,KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDN,XXXXXXX,
  //--------------------------------------------------------------------------------------------------------------------
  KC_LSFT,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,/*------------------*/KC_F16,KC_F17 ,KC_F18 ,KC_F19  ,KC_F20 ,KC_F21 ,
  //--------------------------------------------------------------------------------------------------------------------
  XXXXXXX,XXXXXXX,KC_LWIN,KC_LALT,KC_F24,KC_SPC ,/*------------------*/KC_ENT,XXXXXXX,XXXXXXX,XXXXXXX ,XXXXXXX,XXXXXXX
  //--------------------------------------------------------------------------------------------------------------------
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[SYMBOLS]=LAYOUT_planck_grid(
	//--------------------------------------------------------------------------------------------------------------------------------------
	XXXXXXX,KC_EXLM         ,KC_AT        ,KC_HASH,KC_DLR ,KC_PERC,/*------------------*/KC_PIPE,KC_AMPR  ,KC_LPRN,KC_RPRN,KC_ASTR ,KC_BSPC,
	//--------------------------------------------------------------------------------------------------------------------------------------
	KC_LCTL,KC_BSLS         ,KC_LABK      ,KC_RABK,KC_PSLS,KC_ASTR,/*------------------*/KC_CIRC,KC_EQL   ,KC_LBRC,KC_RBRC,KC_UNDS ,KC_TILD,
	//--------------------------------------------------------------------------------------------------------------------------------------
	KC_LSFT,X(L_EXCLAMATION),X(L_QUESTION),KC_QUES,KC_EXLM,   ENIE,/*------------------*/KC_GRV ,KC_COLON ,KC_LCBR,KC_RCBR,KC_MINUS,KC_RSFT,
	//--------------------------------------------------------------------------------------------------------------------------------------
	XXXXXXX,XXXXXXX         ,      XXXXXXX,KC_LALT,XXXXXXX,KC_SPC ,/*------------------*/KC_ENT ,EMOJI_KEY,XXXXXXX ,XXXXXXX,XXXXXXX ,XXXXXXX
	//--------------------------------------------------------------------------------------------------------------------------------------
),

[NUMPAD]=LAYOUT_planck_grid(
	//----------------------------------------------------------------------------------------------------------------------------------------------
	KC_ESC ,KC_DEL ,KC_P7  ,KC_P8 ,KC_P9  ,KC_BSPC,/*------------------*/XXXXXXX  ,XXXXXXX  ,XXXXXXX    ,XXXXXXX      ,XXXXXXX   ,UNICODE_MODE_WINC,
	//----------------------------------------------------------------------------------------------------------------------------------------------
	KC_P0  ,KC_PSLS,KC_P4  ,KC_P5 ,KC_P6  ,KC_PAST,/*------------------*/XXXXXXX  ,XXXXXXX  ,XXXXXXX    ,XXXXXXX      ,XXXXXXX   ,UNICODE_MODE_LNX ,
	//----------------------------------------------------------------------------------------------------------------------------------------------
	KC_DOT ,KC_PMNS,KC_P1  ,KC_P2 ,KC_P3  ,KC_PPLS,/*------------------*/TO_QWERTY,TO_DVORAK,TO_WORKMAN ,TO_COLEMAK_DH,TO_BEAKL43,UNICODE_MODE_MAC ,
	//----------------------------------------------------------------------------------------------------------------------------------------------
	XXXXXXX,XXXXXXX,KC_LWIN,KC_ENT,XXXXXXX,KC_SPC ,/*------------------*/KC_ENT   ,KC_LSFT  ,MO(NUMPAD2),XXXXXXX      ,XXXXXXX   ,XXXXXXX          
	//---------------------------------------------------------------------------------------------------------------------------------------------- 
),

[NUMPAD2]=LAYOUT_planck_grid(
	//--------------------------------------------------------------------------------------------------------------------
	XXXXXXX,XXXXXXX,KC_7   ,KC_8   ,KC_9   ,XXXXXXX,/*------------------*/XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
	//--------------------------------------------------------------------------------------------------------------------
	KC_LCTL,XXXXXXX,KC_4   ,KC_5   ,KC_6   ,XXXXXXX,/*------------------*/XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
	//--------------------------------------------------------------------------------------------------------------------
	KC_LSFT,XXXXXXX,KC_1   ,KC_2   ,KC_3   ,XXXXXXX,/*------------------*/XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_RSFT,
	//--------------------------------------------------------------------------------------------------------------------
	XXXXXXX,XXXXXXX,KC_LWIN,KC_LALT,KC_RALT,KC_SPC ,/*------------------*/KC_ENT ,KC_LALT,KC_RALT,XXXXXXX,XXXXXXX,XXXXXXX
	//--------------------------------------------------------------------------------------------------------------------
),

[GAMEPLAY_NUMPAD]=LAYOUT_planck_grid(
	//------------------------------------------------------------------------------------------------------------------------------------
	KC_ESC ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,/*------------------*/KC_F1    ,KC_F2    ,KC_F3     ,KC_F4        ,KC_F5     ,KC_F6  ,
	//------------------------------------------------------------------------------------------------------------------------------------
	KC_LCTL,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,/*------------------*/KC_F7    ,KC_F8    ,KC_F9     ,KC_F10       ,KC_F11    ,KC_F12 ,
	//------------------------------------------------------------------------------------------------------------------------------------
	KC_LSFT,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,/*------------------*/TO_QWERTY,TO_DVORAK,TO_WORKMAN,TO_COLEMAK_DH,TO_BEAKL43,XXXXXXX,
	//------------------------------------------------------------------------------------------------------------------------------------
	XXXXXXX,XXXXXXX,KC_LWIN,KC_LALT,KC_RALT,KC_SPC ,/*------------------*/KC_ENT   ,KC_LALT  ,KC_RALT   ,XXXXXXX      ,XXXXXXX   ,XXXXXXX
	//------------------------------------------------------------------------------------------------------------------------------------
),

[SHORTCUTS]=LAYOUT_planck_grid(
	//------------------------------------------------------------------------------------------------------------------------
	KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R        ,KC_T  ,/*------------------*/KC_Y  ,KC_U   ,KC_I   ,KC_O   ,KC_P    ,KC_BSPC,
	//------------------------------------------------------------------------------------------------------------------------
	KC_LCTL,KC_A   ,KC_S   ,KC_D   ,KC_F        ,KC_G  ,/*------------------*/KC_H  ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN ,KC_RCTL,
	//------------------------------------------------------------------------------------------------------------------------
	KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V        ,KC_B  ,/*------------------*/KC_N  ,KC_M   ,KC_COMM,KC_DOT ,KC_QUOTE,KC_RSFT,
	//------------------------------------------------------------------------------------------------------------------------
	XXXXXXX,XXXXXXX,KC_LWIN,KC_LALT,SWITCH_AUDIO,KC_SPC,/*------------------*/KC_ENT,XXXXXXX,KC_RALT,XXXXXXX,XXXXXXX ,XXXXXXX
	//------------------------------------------------------------------------------------------------------------------------
),

[FUNCTIONS]=LAYOUT_planck_grid(
	//--------------------------------------------------------------------------------------------------------------------
	KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,/*------------------*/KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
	//--------------------------------------------------------------------------------------------------------------------
	KC_F13 ,KC_F14 ,KC_F15 ,KC_F16 ,KC_F17 ,KC_F18 ,/*------------------*/KC_F19 ,KC_F20 ,KC_F21 ,KC_F22 ,KC_F23 ,KC_F24 ,
	//--------------------------------------------------------------------------------------------------------------------
	KC_MUTE,KC_VOLD,KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLU,/*------------------*/XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_APP ,
	//--------------------------------------------------------------------------------------------------------------------
	XXXXXXX,XXXXXXX,KC_LWIN,KC_LALT,XXXXXXX,KC_SPC ,/*------------------*/KC_ENT ,KC_LALT,KC_PSCR,XXXXXXX,XXXXXXX,XXXXXXX
	//--------------------------------------------------------------------------------------------------------------------
),


};
uint32_t layer_state_set_user(uint32_t state) {
  switch(biton32(state)) {
    case NUMPAD:
    case NUMPAD2:
    case GAMEPLAY_NUMPAD:
        // turn on numlock, if it isn't already on.
        if (!(host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))) {
            register_code(KC_NUMLOCK);
            unregister_code(KC_NUMLOCK);
        }
        break;
  }
  return state;
};
/*
#ifdef AUDIO_ENABLE
float plover_song[][2]     = SONG(PLOVER_SOUND);
float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
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
            case SCAM:
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
            case SCAM:
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
/*
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
    }
  } else {
    if (clockwise) {
      muse_tempo+=1;
    } else {
      muse_tempo-=1;
  }
}
} else {
  if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
      tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
    tap_code(KC_MS_WH_UP);
    #else
    tap_code(KC_PGUP);
    #endif
  }
}
return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0: {
      #ifdef AUDIO_ENABLE
      static bool play_sound = false;
      #endif
      if (active) {
        #ifdef AUDIO_ENABLE
        if (play_sound) { PLAY_SONG(plover_song); }
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
      if (play_sound) { PLAY_SONG(plover_gb_song); }
      #endif
      layer_off(_ADJUST);
    }
    #ifdef AUDIO_ENABLE
    play_sound = true;
    #endif
    break;
  }
  case 1:
  if (active) {
    muse_mode = true;
  } else {
    muse_mode = false;
}
}
return true;
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
  if (muse_mode) {
    if (muse_counter == 0) {
      uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
      if (muse_note != last_muse_note) {
        stop_note(compute_freq_for_midi_note(last_muse_note));
        play_note(compute_freq_for_midi_note(muse_note), 0xF);
        last_muse_note = muse_note;
      }
    }
    muse_counter = (muse_counter + 1) % muse_tempo;
  } else {
    if (muse_counter) {
      stop_all_notes();
      muse_counter = 0;
    }
  }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
    return false;
    default:
    return true;
  }
}

*/