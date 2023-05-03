#include <HardwareSerial.h>

HardwareSerial bluetoothSerial(1); // Use second hardware serial (UART1)

void setup() {
  // Start serial communication with computer for debugging
  Serial.begin(115200);
  // Start communication with HC-06 at the default baud rate (usually 9600)
  bluetoothSerial.begin(9600, SERIAL_8N1, 16, 17); // RX=16, TX=17
  
  Serial.println("Configuring HC-06 Bluetooth module...");
  delay(1000);
  
  // Send command to change baud rate to 115200
  bluetoothSerial.write("AT+BAUD8");
  delay(500);

  // Check for response from HC-06
  while (bluetoothSerial.available()) {
    char receivedChar = (char)bluetoothSerial.read();
    Serial.print(receivedChar);
  }
  
  Serial.println("Configuration complete.");
}

void loop() {
  // Nothing to do in the loop.
}
