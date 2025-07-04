//IR_Get_Codes
//Max Woodhead, Jun 2025

//Include the IRremote library and specify the receive pin
#include <IRremote.h>  //Version 4.4.2
#define receivePin 2

void setup() {
  // Initialise the infrared receiver
  IrReceiver.begin(receivePin);
  pinMode(receivePin, INPUT);
  // Initialise the serial monitor
  Serial.begin(9600);
  Serial.println("Waiting .....");
}

void loop() {
  if (IrReceiver.decode())  // Look for data to decode
  {
    Serial.print("Hex Code is: ");
    //Display the button code
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    //Display the protocol data
    IrReceiver.printIRResultShort(&Serial);
    delay(500);
  }
  IrReceiver.resume();  //Look for new data after a short delay
}
