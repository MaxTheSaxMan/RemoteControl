//IR_USE_CODES_1
//Max Woodhead, June 2025

/* 
1. You will need to use your own codes matching the buttons on your remote control.
These codes can be found by running the sketch IR_GET_CODES

2. Make sure that you use the 0x prefix to indicate that they are hexadecimal numbers.

3. You can assign any number of button codes in the loop and any suitable code for the button presses.

4.You might want to experiment with the delay.

5. Note that delay is blocking code and if it appears anywhere in the loop all processing will stop during the delay.
You will need to use the millis function to overcome this limitation.
*/

//Include the IRremote library and specify the receive pin
#include <IRremote.h>
#define receivePin 2

void setup() {
  
// Initialise the receiver
  IrReceiver.begin(receivePin);

//Start serial monitor
  Serial.begin(9600);
  delay(1000);
}
void loop() {
  if (IrReceiver.decode()) { // Look for data to decode

  //Check which button has been pressed and print this information
    switch (IrReceiver.decodedIRData.decodedRawData) {
      case 0xBA100AA0:  //Button 1
        Serial.println("Button 1");
        break;
      case 0xBB110AA0:
        Serial.println("Button 2");
        break;
      case 0xB8120AA0:  //Button 3
        Serial.println("Button 3");
        break;
      case 0xB9130AA0:  //Button 4
        Serial.println("Button 4");
        break;
      case 0xBE140AA0:  //Button 5
        Serial.println("Button 5");
        break;
      case 0xBF150AA0:  //Button 6
        Serial.println("Button 6");
        break;
          }
    delay(500);
  }
  IrReceiver.resume();
}
