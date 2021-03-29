#include <DigiPotX9Cxxx.h>

DigiPot pot(X9_INC_PIN,X9_UD_PIN,X9_CS_PIN);
int pot_position = 0;

void pot_jump(int pos) {
  //increase
  if (pos > pot_position) {
    int diff = pos - pot_position;
    for (int i = 0; i < diff; i++) {
      pot.increase(i);
      pot_position += 1;
    }
  }
  //decrease
  if (pos < pot_position) {
    int diff = pos - pot_position;
    int v = 0;
    for (int i = 0; i > diff; i--) {
      pot.decrease(v);
      v += 1;
      pot_position -= 1;
    }
  }
}

//res needs to be value between 0 and 100
void set_resitance(int res) {
  pot_jump(res);
  delay(300);
  pot_jump(0);
}
