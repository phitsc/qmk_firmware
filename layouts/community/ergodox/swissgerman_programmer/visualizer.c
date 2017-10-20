/*
Copyright 2017 Fred Sundvik

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

#include <string.h>
#include "simple_visualizer.h"

#define IS_MOD_ACTIVE(mods_state, kc)  (mods_state & MOD_BIT(kc))
#define IS_EITHER_MOD_ACTIVE(mods_state, kc1, kc2)  (mods_state & (MOD_BIT(kc1) | MOD_BIT(kc2)))

// This function should be implemented by the keymap visualizer
// Don't change anything else than state->target_lcd_color and state->layer_text as that's the only thing
// that the simple_visualizer assumes that you are updating
// Also make sure that the buffer passed to state->layer_text remains valid until the previous animation is
// stopped. This can be done by either double buffering it or by using constant strings
static void get_visualizer_layer_and_color(visualizer_state_t* state) {
    static char status[20];

    if (state->status.layer & 0x8) {
        strcpy(status, "      Macro     ");
        state->target_lcd_color = LCD_COLOR(164, 0xFF, 0xFF);
    }
    else if (state->status.layer & 0x4) {
        strcpy(status, "      Function  ");
        state->target_lcd_color = LCD_COLOR(124, 0xFF, 0xFF);
    }
    else if (state->status.layer & 0x2) {
        strcpy(status, "      Symbol    ");
        state->target_lcd_color = LCD_COLOR(84, 0xFF, 0xFF);
    }
    else {
        strcpy(status, "                ");
        state->target_lcd_color = LCD_COLOR(0, 0, 0);
    }


    if (IS_MOD_ACTIVE(state->status.mods, KC_LGUI)) {
    }

    if (IS_MOD_ACTIVE(state->status.mods, KC_LALT)) {
      status[1] = 'A';
    }

    if (IS_EITHER_MOD_ACTIVE(state->status.mods, KC_LSHIFT, KC_RSHIFT)) {
      status[0] = 'S';
    }

    if (IS_EITHER_MOD_ACTIVE(state->status.mods, KC_LCTL, KC_RCTL)) {
      status[2] = 'C';
    }

    if (IS_MOD_ACTIVE(state->status.mods, KC_RALT)) {
    }

    state->layer_text = status;

}
