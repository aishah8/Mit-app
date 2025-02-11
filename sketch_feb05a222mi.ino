#include "BluetoothSerial.h"

#ifdef ARDUINO_ARCH_ESP32
  BluetoothSerial SerialBT;
#endif

const int ledPin = 2;  

unsigned long previousMillis = 0;
const long interval = 1000; 
bool ledState = LOW;
bool isConnected = false;

void setup() {
  pinMode(ledPin, OUTPUT);  
  Serial.begin(115200);  

 
  if (SerialBT.begin("fixaj")) {
    Serial.println("Bluetooth started successfully!");
  } else {
    Serial.println("Bluetooth initialization failed.");
  }

  delay(2000);  
  Serial.println("Ready");
}

void flashLED(int times, int delayTime) {
  for (int i = 0; i < times; i++) {
    digitalWrite(ledPin, HIGH);
    delay(delayTime);
    digitalWrite(ledPin, LOW);
    if (i < times - 1) {
      delay(delayTime);
    }
  }
}

void loop() {
 
  if (SerialBT.connected()) {
    if (!isConnected) {
      isConnected = true;
      flashLED(3, 100);  
      Serial.println("Bluetooth Connected");
    }
  } else {
    if (isConnected) {
      isConnected = false;
      flashLED(3, 100);  
      Serial.println("Bluetooth Disconnected");
    }
  }


  if (SerialBT.available()) {
    char receivedChar = SerialBT.read();
    Serial.print("Received: ");  
    Serial.println(receivedChar);

   
    if (receivedChar == '1') {
      digitalWrite(ledPin, HIGH); 
      Serial.println("LED ON");
    } else if (receivedChar == '2') {
      digitalWrite(ledPin, LOW);  
      Serial.println("LED OFF");
    }
  }
}
