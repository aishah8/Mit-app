LED Control Project Using ESP32 via Bluetooth
This project allows you to control an LED using an ESP32 device via Bluetooth through a custom mobile application. 
1. ESP32 Setup:
First, I connected the ESP32 to the computer via USB. Then, I enabled Bluetooth using the BluetoothSerial library to ensure the device could connect to the mobile device via Bluetooth.

2. Writing Code in Arduino IDE:
   I wrote code in Arduino IDE to control the LED using Bluetooth. I assigned the LED to pin 2 to be able to turn it on and off based on commands sent from the mobile phone. I used the BluetoothSerial library to ensure the ESP32 could connect to the device via Bluetooth.

   - Bluetooth Initialization: I made sure Bluetooth was enabled and started correctly using SerialBT.begin("fixaj"), setting the Bluetooth name to "fixaj".
   
   - Connection Verification: I added commands to flash the LED when connected or disconnected, using the flashLED() function to blink the LED multiple times.
   
   - LED Control: I specified the commands received via Bluetooth, such as:
     - '1' to turn on the LED.
     - '2' to turn off the LED.

3. Sending Commands from the Mobile App:
   I used MIT App Inventor to design an app to control the ESP32. In the app, I added a single button to control the LED, so when pressed, it toggles the LED on and off.
