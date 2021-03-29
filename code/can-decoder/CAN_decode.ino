#include <SPI.h>
#include "mcp_can.h"
#include "constants.h"
#include "debouncing.h"
#include "can_mngr.h"
#include "digi_pot.h"
#include "shift_register.h"

void setup() {
  Serial.begin(SERIAL_SPEED);
  setup_can();
}

void loop() {
  if (can_msg()) {
    CAN.readMsgBuf(&len, buffer);
    
    if (CAN.getCanId() == steering_buttons_id) {
      String can_msg = decode_buffer(buffer);

      if (can_msg == voldown_button) {
        Serial.println("Button -");
        debounce_button('a');
        if (check_hold_debounce()) {
          Serial.println("Button press or hold?");
          set_resitance(10);
        }
      }
      else if (can_msg == volup_button) {
        Serial.println("Button +");
        debounce_button('a');
        if (check_hold_debounce()) {
          Serial.println("Button press or hold?");
          set_resitance(20);
        }
      }
      else if (can_msg == answer_button) {
        Serial.println("Button Anruf abnehmen");
        debounce_button('a');
        if (check_no_hold_debounce()) {
          Serial.println("Button pressed");
          set_resitance(30);
        }
      }
      else if (can_msg == decline_button) {
        Serial.println("Button Anruf ablehnen");
        debounce_button('a');
        if (check_no_hold_debounce()) {
          Serial.println("Button pressed");
          set_resitance(40);
        }
      }
      else if (can_msg == button_off) {
        Serial.println("Button Off");
        debounce_button('r');
      }
      else {
        Serial.println("Error!");
      }
      Serial.println("");
    }

    
    if (CAN.getCanId() == shifter_id) {
      String can_msg = decode_buffer(buffer);

      if (can_msg == reverse_gear) {
        Serial.println("Reversing");
        debounce_button('a');
        if (check_no_hold_debounce()) {
          Serial.println("Shifter in reverse position");
        }
      }
      else if (can_msg == park_gear) {
        Serial.println("Parking");
        debounce_button('r');
      }
      else {
        Serial.println("Error!");
      }
      Serial.println("");
    }


    if (CAN.getCanId() == light_id) {
      String can_msg = decode_buffer(buffer);

      if (can_msg == hedlights) {
        Serial.println("Lights on");
        debounce_button('a');
        if (check_no_hold_debounce()) {
          Serial.println("Shifter in reverse position");
        }
      }
      else if (can_msg == park_gear) {
        Serial.println("Lights off");
        debounce_button('r');
      }
      else {
        Serial.println("Error!");
      }
      Serial.println("");
    }
  }
}
