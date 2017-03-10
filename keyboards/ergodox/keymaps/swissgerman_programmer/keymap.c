#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    VRSN,
    RGB_SLD
};

#define _______ KC_TRNS

/* CH KEYS

    degree      KC_GRAVE
    question    KC_MINUS
    caret       KC_EQUAL
    lessThan    KC_NONUS_BSLASH
    ü           KC_LBRACKET
    exclamation KC_RBRACKET
    ö           KC_SCOLON
    ä           KC_QUOTE
    dollar      KC_NONUS_HASH
    comma       KC_COMMA
    period      KC_DOT
    dash        KC_SLASH

*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   §    |   1  |   2  |   3  |   4  |   5  |  F11 |           |  L3  |   6  |   7  |   8  |   9  |   0  |   '    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |  F10 |           |  L1  |   Z  |   U  |   I  |   O  |   P  |   Ü    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   L1   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------|  F9  |           |RShift|------+------+------+------+------+--------|
 * | LShift |   Y  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  Up  |   -    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L3  | LGui |  L2  | Alt  | Ctrl |                                       |  Esc | Down | Left | Down |Right |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | F5   | F3   |       | PrtSc|Pause |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | F2   |       | F12  |      |      |
 *                                 |Back- |Delete|------|       |------|Enter |Space |
 *                                 |space |      | Ctrl |       | F8   |      |      |
 *                                 `--------------------'       `--------------------'
 */
[0] = KEYMAP(
    // left hand
    KC_GRV  , KC_1    , KC_2   , KC_3    , KC_4     , KC_5    , KC_F11   ,
    KC_TAB  , KC_Q    , KC_W   , KC_E    , KC_R     , KC_T    , KC_F10   ,
    F(1)    , KC_A    , KC_S   , KC_D    , KC_F     , KC_G    ,
    KC_LSFT , KC_Z    , KC_X   , KC_C    , KC_V     , KC_B    , KC_F9    ,
    F(3)    , KC_LGUI , F(2)   , KC_LALT , F(21)    ,
                                                      KC_F5   , KC_F3    ,
                                                                KC_F2    ,
                                           KC_BSPC  , KC_DEL  , KC_LCTL  ,
    // right hand
    F(3)    , KC_6   , KC_7    , KC_8    , KC_9     , KC_0    , KC_MINS  ,
    F(1)    , KC_Y   , KC_U    , KC_I    , KC_O     , KC_P    , KC_LBRC  ,
    KC_H    , KC_J   , KC_K    , KC_L    , KC_SCLN  , KC_QUOT ,
    KC_RSFT , KC_N   , KC_M    , KC_COMM , KC_DOT   , KC_UP   , KC_SLSH  ,
                       F(22)   , F(2)    , KC_LEFT  , KC_DOWN , KC_RIGHT ,
    KC_PSCR , KC_BRK ,
    KC_F12  ,
    KC_F8   , KC_ENT  , KC_SPC
),
/* Keymap 1: Layer 1
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |    ~    |      |   @  |   #  |      |      |      |           |      |      |   \  |      |      |   !  |    ^   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |   €  |      |      |      |           |      |      |   [  |   ]  |      |      |    ¨   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|   |  |   {  |   }  |      |      |    $   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |   <  |   >  |      | PgUp |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      | Home |PgDown| End  |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Space |Enter |------|       |------|Back- |Delete|
 *                                 |      |      |      |       |      |space |      |
 *                                 `--------------------'       `--------------------'
 */
[1] = KEYMAP(
    // left hand
    F(23)   , _______ , F(26)   , F(25)   , _______ , _______ , _______ ,
    _______ , _______ , _______ , F(29)   , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,
                                                      _______ , _______ ,
                                                                _______ ,
                                            KC_SPC  , KC_ENT  , _______ ,
    // right hand
    _______ , _______ , F(16)   , _______ , _______ , F(4)    , KC_EQL  ,
    _______ , _______ , F(11)   , F(12)   , _______ , _______ , KC_RBRC ,
              F(15)   , F(9)    , F(10)   , _______ , F(24)   , KC_NUHS ,
    _______ , _______ , F(13)   , F(14)   , _______ , KC_PGUP , _______ ,
                        _______ , _______ , KC_HOME , KC_PGDN , KC_END  ,
    _______ , _______ ,
    _______ ,
    _______ , KC_BSPC , KC_DEL
),
/* Keymap 2: Layer 2
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F4  |  F5  |  F6  |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F7  |  F8  |  F9  |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F10 |  F11 |  F12 |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[2] = KEYMAP(  // Layer2:
        // left hand
        _______ , KC_F1   , KC_F2   , KC_F3   , _______ , _______ , _______ ,
        _______ , KC_F4   , KC_F5   , KC_F6   , _______ , _______ , _______ ,
        _______ , KC_F7   , KC_F8   , KC_F9   , _______ , _______ ,
        _______ , KC_F10  , KC_F11  , KC_F12  , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ ,
                                                          _______ , _______ ,
                                                                    _______ ,
                                                _______ , _______ , _______ ,
        // right hand
        _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                  _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                            _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ ,
        _______ ,
        _______ , _______ , _______
    ),
/* Keymap 3: Layer 3
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Flash |      |      |      |      |      |      |           |      |      |      |      |      |      |  Flash |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |VolUp |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Mute | Play |TrPrev|VolDwn|TrNext|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[3] = KEYMAP(  // Layer3:
        // left hand
        RESET   , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , F(28)   ,
                                                          _______ , _______ ,
                                                                    _______ ,
                                                _______ , _______ , _______ ,
        // right hand
        _______ , _______ , _______ , _______ , _______ , _______ , RESET   ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                  _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , KC_VOLU , _______ ,
                            KC_MUTE , KC_MPLY , KC_MPRV , KC_VOLD , KC_MNXT ,
        _______ , _______ ,
        _______ ,
        _______ , _______ , F(27)
    ),
};

const uint16_t PROGMEM fn_actions[] =
{
     [1] = ACTION_LAYER_MOMENTARY(1),                      // FN1 - Layer 1
     [2] = ACTION_LAYER_MOMENTARY(2),                      // FN2 - Layer 2
     [3] = ACTION_LAYER_MOMENTARY(3),                      // FN3 - Layer 3

     [4] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRACKET),         // FN4
     [5] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_SLSH),         // FN5
     [6] = ACTION_LAYER_TOGGLE(2),                         // FN6 - Layer 2

     [7] = ACTION_MODS_KEY(MOD_LSFT, KC_8),                // FN7  = (
     [8] = ACTION_MODS_KEY(MOD_LSFT, KC_9),                // FN8  = )
     [9] = ACTION_MODS_KEY(MOD_RALT, KC_QUOTE),            // FN9  = {
    [10] = ACTION_MODS_KEY(MOD_RALT, KC_NONUS_HASH),       // FN10 = }
    [11] = ACTION_MODS_KEY(MOD_RALT, KC_LBRACKET),         // FN11 = [
    [12] = ACTION_MODS_KEY(MOD_RALT, KC_RBRACKET),         // FN12 = ]
    [13] = ACTION_KEY     (KC_NONUS_BSLASH),               // FN13 = <
    [14] = ACTION_MODS_KEY(MOD_LSFT, KC_NONUS_BSLASH),     // FN14 = >
    [15] = ACTION_MODS_KEY(MOD_RALT, KC_7),                // FN15 - |
    [16] = ACTION_MODS_KEY(MOD_RALT, KC_NONUS_BSLASH),     // FN16 = backslash

    [17] = ACTION_MODS_KEY(MOD_LSFT, KC_F5),               // FN17
    [18] = ACTION_MODS_KEY(MOD_LSFT, KC_F9),               // FN18
    [19] = ACTION_MODS_KEY(MOD_LSFT, KC_F10),              // FN19
    [20] = ACTION_MODS_KEY(MOD_LSFT, KC_F11),              // FN20

    [21] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),          // FN21
    [22] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ESC),          // FN22

    [23] = ACTION_MODS_KEY(MOD_RALT, KC_EQUAL),            // FN23 = ~
    //[24] = ACTION_MODS_KEY(MOD_RALT, KC_SCOLON),           // FN24 = ^

    [25] = ACTION_MODS_KEY(MOD_RALT, KC_3),                // FN25 = #
    [26] = ACTION_MODS_KEY(MOD_RALT, KC_2),                // FN26 = @

    [27] = ACTION_MODS_KEY(MOD_LCTL|MOD_LALT, KC_SPC),     // FN27 = Ctrl + Alt + Space
    [28] = ACTION_MODS_KEY(MOD_LCTL, KC_RBRC),             // FN28 = Cltr + diacr.

    [29] = ACTION_MODS_KEY(MOD_RALT, KC_E),                // FN29 = €
};

const macro_t* action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id)
    {
        case 0:
            if (record->event.pressed)
            {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
        break;

        case 1:
            if (record->event.pressed)
            { // For resetting EEPROM
                eeconfig_init();
            }
        break;
    }

    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        // dynamically generate these.
        case EPRM:
          if (record->event.pressed)
          {
              eeconfig_init();
          }

          return false;
        break;

        case VRSN:
          if (record->event.pressed)
          {
              SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
          }

          return false;
        break;

        case RGB_SLD:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE

                rgblight_mode(1);

                #endif
            }
            return false;
        break;
    }

    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_led_all_off();

    switch (layer)
    {
        case 1:
            ergodox_right_led_2_on();
        break;

        case 2:
            ergodox_right_led_3_on();
        break;

        case 3:
            ergodox_right_led_1_on();
        break;
    }

};
