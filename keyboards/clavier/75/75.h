#ifndef CLAVIER_H
#define CLAVIER_H
#include "quantum.h"

#define RGBLIGHT_ANIMATIONS

void reset_keyboard_kb(void);

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
   k00, k01, k02, k03, k04, k05, \
	k10, k11, k12, k13, k14, k15, \
	k20, k21, k22, k23, k24, k25, \
	k30, k31, k32, k33, k34, k35 \
) \
{ \
	{ k00, k01, k02, k03, k04, k05 }, \
	{ k10, k11, k12, k13, k14, k15 }, \
	{ k20, k21, k22, k23, k24, k25 }, \
	{ k30, k31, k32, k33, k34, k35 } \
}

// Used to create a keymap using only KC_ prefixed keys
#define KC_KEYMAP( \
  k00, k01, k02, k03, k04, k05, \
  k10, k11, k12, k13, k14, k15, \
  k20, k21, k22, k23, k24, k25, \
  k30, k31, k32, k33, k34, k35 \
  ) \
      KEYMAP( \
    KC_##k00, KC_##k01, KC_##k02, KC_##k03, KC_##k04, KC_##k05, \
    KC_##k10, KC_##k11, KC_##k12, KC_##k13, KC_##k14, KC_##k15, \
    KC_##k20, KC_##k21, KC_##k22, KC_##k23, KC_##k24, KC_##k25, \
    KC_##k30, KC_##k31, KC_##k32, KC_##k33, KC_##k34, KC_##k35 \
    )

#define LAYOUT_ortho_4x12 KEYMAP
#define KC_LAYOUT_ortho_4x12 KC_KEYMAP
#define LAYOUT_kc_ortho_4x12 KC_KEYMAP


#endif
