bool button_debounce = false;
int button_deb_val = 0;

void debounce_button(char type) {
  switch (type) {
    //add
    case 'a':
      button_debounce = true;
      button_deb_val += 1;
      break;
    //remove
    case 'r':
      button_debounce = false;
      button_deb_val = 0;
      break;
  }
}

bool check_no_hold_debounce() {
  if (button_debounce == true && button_deb_val == 1) {
    return true;
  } else {
    return false;
  }
}

bool check_hold_debounce() {
  if (button_debounce == true && button_deb_val == 1) {
    return true;
  }
  else if (button_debounce == true && button_deb_val > button_deb_count) {
    return false;
  }
  else if (button_debounce == true) {
    return false;
  }
}
