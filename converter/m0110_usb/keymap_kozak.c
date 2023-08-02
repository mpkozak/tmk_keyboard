/*
Copyright 2014 Jun Wako <wakojun@gmail.com>

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
#include <stdint.h>
#include "keycode.h"
#include "keymap_common.h"


const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default:
     * M0110                                                       M0120
     * ,---------------------------------------------------------. ,---------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backs| |Nlk|  -|  +|  *|
     * |---------------------------------------------------------| |---------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \| |  7|  8|  9|  /|
     * |---------------------------------------------------------| |---------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return| |  4|  5|  6|  ,|
     * |---------------------------------------------------------| |---------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift   | |  1|  2|  3|   |
     * `---------------------------------------------------------' |-----------|Ent|
     *      |Opt|Mac |         Space               |Mac |Opt|      |      0|  .|   |
     *      `-----------------------------------------------'      `---------------'
     *  M0110A
     * ,---------------------------------------------------------. ,---------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Bcksp| |Nlk|  =|  /|  *|
     * |---------------------------------------------------------| |---------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|   | |  7|  8|  9|  -|
     * |-----------------------------------------------------'   | |---------------|
     * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return| |  4|  5|  6|  +|
     * |---------------------------------------------------------| |---------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shft|Up | |  1|  2|  3|   |
     * |---------------------------------------------------------' |-----------|Ent|
     * |Opt  |Mac    |           Space           |  \|Lft|Rgt|Dn | |      0|  .|   |
     * `---------------------------------------------------------' `---------------'
     */
    [0] = KEYMAP(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,    LCTL,PEQL,PSLS,PAST,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,         P7,  P8,  P9,  PMNS,
    LCAP,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,     P4,  P5,  P6,  PPLS,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          UP,      P1,  P2,  P3,  PENT,
    LALT,LGUI,               FN0,                LCTL,BSLS,LEFT,RGHT,DOWN,    P0,       PDOT
    ),
    [1] = KEYMAP(
    GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, FN1,     LCTL,PEQL,PSLS,PAST,
    TRNS,FN8, FN9, FN2, NO,  FN15,NO,  NO,  UP,  FN8, FN9, F14, F15,          P7,  P8,  P9,  PMNS,
    TRNS,FN10,FN11,F11, FN3, NO,  NO,  LEFT,DOWN,RGHT,FN10,FN11,     TRNS,    P4,  P5,  P6,  PPLS,
    TRNS,FN5, FN6, FN7, FN4, FN13,FN14,FN12,VOLD,VOLU,MUTE,          PGUP,    P1,  P2,  P3,  PENT,
    LCTL,TRNS,               TRNS,               TRNS,BTLD,HOME,END, PGDN,    P0,       PDOT
    ),
};

/*
 * Fn action definition
 */
const action_t fn_actions[] PROGMEM = {
    [0] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),
    [1] = ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI, KC_Q),                   // lock screen
    [2] = ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI, KC_SPACE),               // character picker
    [3] = ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI, KC_F),                   // fullscreen toggle
    [4] = ACTION_MODS_KEY(MOD_LSFT | MOD_LALT | MOD_LGUI, KC_V),        // paste plaintext
    [5] = ACTION_MODS_KEY(MOD_LGUI, KC_MINS),                           // zoom out
    [6] = ACTION_MODS_KEY(MOD_LGUI, KC_EQL),                            // zoom in
    [7] = ACTION_MODS_KEY(MOD_LGUI, KC_0),                              // zoom actual
    [8] = ACTION_MODS_KEY(MOD_LSFT | MOD_LGUI, KC_LBRC),                // move left tab
    [9] = ACTION_MODS_KEY(MOD_LSFT | MOD_LGUI, KC_RBRC),                // move right tab
    [10] = ACTION_MODS_KEY(MOD_LCTL, KC_LEFT),                          // move left space
    [11] = ACTION_MODS_KEY(MOD_LCTL, KC_RGHT),                          // move right space
    [12] = ACTION_MODS_KEY(MOD_LCTL, KC_UP),                            // mission control
    [13] = ACTION_MODS_KEY(MOD_LGUI, KC_LBRC),                          // browser back
    [14] = ACTION_MODS_KEY(MOD_LGUI, KC_RBRC),                          // browser forward
    [15] = ACTION_MODS_KEY(MOD_LALT | MOD_LGUI, KC_ESC),                // force quit
};
