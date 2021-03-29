// MCP2515 setup
const int CS_PIN = 10;
const long SERIAL_SPEED = 115200;
const byte CAN_SPEED = CAN_83K3BPS;


// CAN ID`s (values as int decimal)
const int steering_buttons_id = 816;

const int shifter_id = 3;

const int light_id = 1890;


// Button HEX (values as string)
const String volup_button = "10 00"; // +
const String voldown_button = "20 00"; // -
const String answer_button = "80 00"; // answer call
const String decline_button = "40 00"; // dcline call
const String button_off = "00 00"; // button off

const String park_gear = "00 18 60 00 00";// parking shifter position
const String reverse_gear = "00 97 60 01 00"; // reverse shifter position

const String hedlights = "80 80 00 00 00 00 00 00"; // lights


// X9C pins
#define X9_CS_PIN 3
#define X9_UD_PIN 4
#define X9_INC_PIN 5


// Shift register pins
#define PIN_SHIFT 8   // connected to SHCP
#define PIN_STORE 9   // connected to STCP
#define PIN_DATA  10  // connected to DS


// debounce settings
const int button_deb_count = 2;
