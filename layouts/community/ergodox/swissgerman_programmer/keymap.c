#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

extern inline void ergodox_led_all_off(void);

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    VRSN,       // print version
    RGB_SLD,
    CIRC,       // ^
    GRV_TLD,    // ` or ~
    BRK_Z       // Break followed by Z
};

enum unicode_names {
    SMILE
};

const uint32_t PROGMEM unicode_map[] = {
    [SMILE] = 0x1F642
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

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
 * |   ` ~  |   1  |   2  |   3  |   4  |   5  |  F11 |           | LGui |   6  |   7  |   8  |   9  |   0  |   '    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |  F10 |           |  L1  |   Z  |   U  |   I  |   O  |   P  |   Ü    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   L1   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------|  F9  |           |RShift|------+------+------+------+------+--------|
 * | LShift |   Y  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  Up  |   -    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L3  |  i3  |  L2  | Alt  | Ctrl |                                       |  Esc |  L1  | Left | Down |Right |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | F5   | F3   |       | PrtSc|Pause |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | F2   |       | F12  |      |      |
 *                                 |Back- |Delete|------|       |------|Enter |Space |
 *                                 |space |      | Ctrl |       | F8   |      |      |
 *                                 `--------------------'       `--------------------'
 */
[0] = LAYOUT_ergodox(
    // left hand
    GRV_TLD , KC_1        , KC_2   , KC_3    , KC_4           , KC_5   , KC_F11  ,
    KC_TAB  , KC_Q        , KC_W   , KC_E    , KC_R           , KC_T   , KC_F10  ,
    MO(1)   , KC_A        , KC_S   , KC_D    , KC_F           , KC_G   ,
    KC_LSFT , KC_Z        , KC_X   , KC_C    , KC_V           , KC_B   , KC_F9   ,
    MO(3)   , LCA(KC_LGUI), MO(2)  , KC_LALT , LCTL_T(KC_ESC) ,
                                                                KC_F5  , KC_F3   ,
                                                                         KC_F2   ,
                                                     KC_BSPC  , KC_DEL , KC_LCTL ,
    // right hand
    KC_LGUI , KC_6   , KC_7    , KC_8    , KC_9     , KC_0    , KC_MINS  ,
    _______ , KC_Y   , KC_U    , KC_I    , KC_O     , KC_P    , KC_LBRC  ,
              KC_H   , KC_J    , KC_K    , KC_L     , KC_SCLN , KC_QUOT  ,
    KC_RSFT , KC_N   , KC_M    , KC_COMM , KC_DOT   , KC_UP   , KC_SLSH  ,
              RCTL_T(KC_ESC)   , MO(1)   , KC_LEFT  , KC_DOWN , KC_RIGHT ,
    KC_PSCR , KC_BRK ,
    C(S(KC_O)),
    C(S(KC_M)), KC_ENT  , KC_SPC
),
/* Keymap 1: Layer 1
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |    §    |      |   @  |   #  |      |      |Flash |           |Flash |      |   \  |      |      |   !  |    `   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   =  |   €  |      |      |      |           |      |      |   [  |   ]  |      |      |    ¨   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   +  |   -  |   *  |   /  |   %  |------|           |------|   |  |   {  |   }  |   &  |   ^  |    $   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |   -  |   <  |   >  |   :  | PgUp |        |
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
[1] = LAYOUT_ergodox(
    // left hand
    KC_GRV  , RALT(KC_1), RALT(KC_2)   , RALT(KC_3)   , _______  , _______   , RESET   ,
    _______ , S(KC_RBRC), S(KC_0)      , RALT(KC_E)   , _______  , _______   , _______ ,
    _______ , S(KC_1)   , KC_SLSH      , S(KC_3)      , S(KC_7)  , S(KC_5)   ,
    _______ , _______   , _______      , _______      , _______  , _______   , _______ ,
    _______ , _______   , _______      , _______      , _______  ,
                                                                   _______   , _______ ,
                                                                               _______ ,
                                                        KC_SPC   , KC_ENT    , _______ ,
    // right hand
    RESET   , _______   , RALT(KC_NUBS), _______      , _______  , S(KC_RBRC), KC_EQUAL,
    _______ , _______   , RALT(KC_LBRC), RALT(KC_RBRC), _______  , _______   , KC_RBRC ,
              RALT(KC_7), RALT(KC_QUOT), RALT(KC_NUHS), S(KC_6)  , CIRC      , KC_NUHS ,
    _______ , KC_SLSH   , KC_NUBS      , S(KC_NUBS)   , S(KC_DOT), KC_PGUP   , _______ ,
                          _______      , _______      , KC_HOME  , KC_PGDN   , KC_END  ,
    _______ , _______ ,
    C(S(KC_P)),
    _______ , _______ , _______
),
/* Keymap 2: Layer 2
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Version|  F1  |  F2  |  F3  |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F4  |  F5  |  F6  |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F7  |  F8  |  F9  |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F10 |  F11 |  F12 |      |      |      |           |      |      |      |      |  MB1 | MCUp |  MB2   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |MCLeft|MCDown|MCRght|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |TrPrev|TrNext|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |VolUp |      |      |
 *                                 |      |      |------|       |------| Mute | Play |
 *                                 |      |      |      |       |VolDwn|      | Pause|
 *                                 `--------------------'       `--------------------'
 */
[2] = LAYOUT_ergodox(  // Layer2:
        // left hand
        VRSN    , KC_F1   , KC_F2   , KC_F3   , _______ , _______ , _______ ,
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
        _______ , _______ , _______ , _______ , KC_BTN1 , KC_MS_U , KC_BTN2 ,
                            _______ , _______ , KC_MS_L , KC_MS_D , KC_MS_R ,
        KC_MPRV , KC_MNXT ,
        KC_VOLU ,
        KC_VOLD , KC_MUTE , KC_MPLY
    ),
/* Keymap 3: Layer 3
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BL TOG | BL 1 | BL 2 | BL 3 | BL 4 | BL 5 |      |           |      | BL 6 | BL 7 | BL 8 | BL 9 |      |BL TOGG |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | Win+E|      |      |      |           |      |      |      |      |      |      | BL ↑   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      | BL ↓   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |Brk,Z |      |      |Win+↑ |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |Ctrl+¨|                                       |      |      |Win+← |Win+↓ |Win+→ |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Ctrl+ |
 *                                 |      |      |------|       |------|      | Alt+ |
 *                                 |      |      |      |       |      |      |Space |
 *                                 `--------------------'       `--------------------'
 */
[3] = LAYOUT_ergodox(  // Layer3:
        // left hand
        _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , G(KC_E) , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , C(KC_RBRC),
                                                          _______ , _______ ,
                                                                    _______ ,
                                                _______ , _______ , _______ ,
        // right hand
        UC_M_WC , _______ , _______ , _______ , _______    , _______    , BL_TOGG ,
        _______ , _______ , _______ , _______ , _______    , _______    , BL_INC  ,
                  _______ , _______ , _______ , _______    , _______    , BL_DEC  ,
        _______ , _______ , BRK_Z   , _______ , _______    , G(KC_UP)   , _______ ,
                            _______ , _______ , G(KC_LEFT) , G(KC_DOWN) , G(KC_RIGHT) ,
        _______ , _______ ,
        _______ ,
        _______ , _______ , LCA(KC_SPC)
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        // dynamically generate these.
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
        break;

        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
        break;

        case RGB_SLD:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE

                rgblight_mode(1);

                #endif
            }
        break;

        case CIRC:
            if (record->event.pressed) {
                SEND_STRING("= "); // ^
            }
        break;

        case GRV_TLD:
            if (record->event.pressed) {
                if (get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_RALT) "=" SS_UP(X_RALT) " ");
                } else {
                    SEND_STRING(SS_DOWN(X_LSHIFT) "=" SS_UP(X_LSHIFT) " ");
                }
            }
        break;

        case BRK_Z:
            if (record->event.pressed) {
                tap_code(KC_BRK);
                SEND_STRING("Y");
            }
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
