int shift_out[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void write_to_register() {
  // latchpin low --> we can write to register without changing the outputs
  digitalWrite(PIN_STORE, LOW);
  for (int i=0; i<8; i++) {
    // set shift pin to "wait"
    digitalWrite(PIN_SHIFT, LOW);
    // writing to data pin
    digitalWrite(PIN_DATA, shift_out[i]);
    // rising slope -> shifting data in the register
    digitalWrite(PIN_SHIFT, HIGH);
  }
  // write whole register to output
  digitalWrite(PIN_STORE, HIGH);
}

void setup_shift() {
  pinMode(PIN_STORE, OUTPUT);
  pinMode(PIN_SHIFT, OUTPUT);
  pinMode(PIN_DATA, OUTPUT);
  write_to_register();
}

//pin can be 1 to 8
void set_out(char state, int pin) {
  switch (state) {
    case 'h':
      shift_out[pin] = 1;
      write_to_register();
      break;
    case 'l':
      shift_out[pin] = 1;
      write_to_register();
      break;
  }
}
