#include QMK_KEYBOARD_H
#include "version.h"

enum preonic_layers {
  _QWERTY
};

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    VRSN,       // print version
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

/* Basic layer
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  |  Ü   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Fn1  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn3  |CtlGui|  Fn2 | Alt  |CtlEsc|Backsp|Enter |Space |  Fn1 | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[0] = LAYOUT_ortho_5x12(
  GRV_TLD, KC_1        , KC_2  , KC_3,    KC_4          , KC_5   , KC_6  , KC_7  , KC_8   , KC_9   , KC_0   , KC_MINS,
  KC_TAB , KC_Q        , KC_W  , KC_E,    KC_R          , KC_T   , KC_Y  , KC_U  , KC_I   , KC_O   , KC_P   , KC_LBRC,
  MO(1)  , KC_A        , KC_S  , KC_D,    KC_F          , KC_G   , KC_H  , KC_J  , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z        , KC_X  , KC_C,    KC_V          , KC_B   , KC_N  , KC_M  , KC_COMM, KC_DOT , KC_UP  , KC_SLSH,
  MO(3)  , LCA(KC_LGUI), MO(2) , KC_LALT, LCTL_T(KC_ESC), KC_BSPC, KC_ENT, KC_SPC, MO(1)  , KC_LEFT, KC_DOWN, KC_RGHT
),

/* Basic layer
 * ,-----------------------------------------------------------------------------------.
 * |   §  |      |   @  |   #  |      |      |      |   \  |      |      |   !  |   ^  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   !  |   =  |   €  |      |      |      |   [  |   ]  |      |      |  ¨   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   +  |   -  |   *  |   /  |      |   |  |   {  |   }  |   &  |   ^  |  $   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      | PgUp |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Reset|      |      |      |      | DEL  |      |      |      | Home |PgDwn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[1] = LAYOUT_ortho_5x12(
  KC_GRV , RALT(KC_1), RALT(KC_2), RALT(KC_3), _______, _______, _______   , RALT(KC_NUBS), _______      , _______  , S(KC_RBRC), KC_EQUAL,
  _______, S(KC_RBRC), S(KC_0)   , RALT(KC_E), _______, _______, _______   , RALT(KC_LBRC), RALT(KC_RBRC), _______  , _______   , KC_RBRC ,
  _______, S(KC_1)   , KC_SLSH   , S(KC_3)   , S(KC_7), _______, RALT(KC_7), RALT(KC_QUOT), RALT(KC_NUHS), S(KC_6)  , CIRC      , KC_NUHS ,
  _______, _______   , _______   , _______   , S(KC_5), _______, KC_SLSH   , KC_NUBS      , S(KC_NUBS)   , S(KC_DOT), KC_PGUP   , _______ ,
  RESET  , _______   , _______   , _______   , _______, KC_DEL , _______   , _______      , _______      , KC_HOME  , KC_PGDN   , KC_END
),

[2] = LAYOUT_ortho_5x12(
  VRSN   , KC_F1  , KC_F2  , KC_F3  , _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F4  , KC_F5  , KC_F6  , _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F7  , KC_F8  , KC_F9  , _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F10 , KC_F11 , KC_F12 , _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
),

[3] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, G(KC_E), _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, G(KC_L), _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,G(KC_UP), _______,
  _______, _______, _______, _______,C(KC_RBRC), _______, _______,LCA(KC_SPC),_______,G(KC_LEFT),G(KC_DOWN),G(KC_RIGHT)
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        case VRSN:
            if (record->event.pressed) {
               SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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

