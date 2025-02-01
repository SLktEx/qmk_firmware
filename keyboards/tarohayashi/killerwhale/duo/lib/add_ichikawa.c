#include "quantum.h"
#include "lib/add_ichikawa.h"

bool is_max = false;

bool process_record_ichikawakeycodes(uint16_t keycode, keyrecord_t *record, uint8_t layer){
    switch (keycode) {
        case IK_GUI:
            if(record->event.pressed) {
                register_code(KC_LEFT_GUI);
            } else {
                unregister_code(KC_LEFT_GUI);
            }
            break;
        case IK_END:
            if(record->event.pressed) {
                register_code(KC_LEFT_ALT);
                register_code(KC_F4);
            } else {
                unregister_code(KC_F4);
                unregister_code(KC_LEFT_ALT);
            }
            break;
        case IK_MAX:
            if(record->event.pressed) {
                register_code(KC_LEFT_ALT);
                tap_code(KC_SPC);
                unregister_code(KC_LEFT_ALT);
                wait_ms(50);
                if(is_max){
                    tap_code(KC_R);
                    is_max = false;
                }else {
                    tap_code(KC_X);
                    is_max = true;
                }

            }
            break;
        case IK_MIN:
            if(record->event.pressed) {
                register_code(KC_LEFT_ALT);
                tap_code(KC_SPC);
                unregister_code(KC_LEFT_ALT);
                wait_ms(50);
                tap_code(KC_N);
            }
            break;
    }
    return true;
}
