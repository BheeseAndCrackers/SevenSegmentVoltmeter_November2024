#include <SevSeg.h>//library that handles seven segment displays
SevSeg sevseg; //creating an instance

const uint8_t segmentpins[] = {13, 12, 11, 10, 8, 7, 6, 5}; // array of pins connected to segments; A-G,+DP.
const uint8_t digitpins[] = {A1, A2, A3, A4}; //array of pins connected to the display pins (Cathode); 1-4.


void setup() {
  //setting pin modes
  
  for (int a=0; a<4; a++){
    pinMode(digitpins[a], OUTPUT);
  }
  
   for (int i=0; i<8; i++){
    pinMode(segmentpins[i], OUTPUT);
  }
pinMode(A0, INPUT);

// starting the library, passing number of digits, the pins associated with digits and segments, and turning 'leading zeros' bool to true.
sevseg.begin(COMMON_CATHODE, 4, digitpins, segmentpins, 0,0,1,0); 
}

void loop() {
    float reading = analogRead(A0); //getting reading from pot
    float voltage = (reading/1023)*50; //converting to a voltage, multiplied by 100 to fit the display
     
        sevseg.setNumber(voltage, 1); //displaying the voltage
        sevseg.refreshDisplay(); //refreshing the display     
}
