#include "quantum.h"
#include "lib/add_ichikawa.h"

bool process_record_ichikawakeycodes(uint16_t keycode, keyrecord_t *record, uint8_t layer){
    switch (keycode) {
        case IK_GUI:
            if(record->event.pressed) {
                register_code(KC_LEFT_GUI);
            } else {
                unregister_code(KC_LEFT_GUI);
            }
            break;
    }
    return true;
}
