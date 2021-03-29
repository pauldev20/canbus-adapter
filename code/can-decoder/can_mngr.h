MCP_CAN CAN(CS_PIN);
unsigned char len = 0;
byte buffer[8];

void setup_can() {
  byte canSpeed = CAN_SPEED;
  while (CAN.begin(canSpeed) != CAN_OK) {
    delay(100);
  }
  Serial.println("Connected to CAN");
}

bool can_msg() {
  if (CAN.checkReceive() == CAN_MSGAVAIL) {
    return true;
  }
  else {
    return false;
  }
}

String decode_buffer(char can_buffer[8]) {
  char tmp[3];
  String hexstr = "";
  for (int i = 0; i < len; i++) {
    if (i > 0) {hexstr += ' ';}
    snprintf(tmp, 3, "%02X", can_buffer[i]);
    hexstr += tmp;
  }
  return hexstr;
}
