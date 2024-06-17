#include <SoftwareSerial.h>

#define SSerialRX        10  //Serial Receive pin
#define SSerialTX        11  //Serial Transmit pin

#define SSerialTxControl 3   //RS485 Direction control

SoftwareSerial RS485Serial(SSerialRX, SSerialTX); // RX, TX

#define RS485Tr         HIGH
#define RS485Re         LOW
#define RS485Speed      4800

void setup() {
    pinMode(SSerialTxControl, OUTPUT);

  // Initialize the serial communication
  Serial.begin(9600);
  Serial.println("Serial test, Master:");  // Can be ignored

  RS485Serial.begin(RS485Speed);

  digitalWrite(SSerialTxControl, RS485Re);  // Init Transceiver
}

void loop() {
  if (Serial.available()) {
    String message = Serial.readStringUntil('\n');
    sendRS485Message(message);
  }
}

void sendRS485Message(String message) {
  digitalWrite(SSerialTxControl, RS485Tr);  // Init Transceiver

  Serial.println(message);          // print to serial 
  RS485Serial.print(message);               // print though rs485

  digitalWrite(SSerialTxControl, RS485Re);  // Init Transceiver
}
