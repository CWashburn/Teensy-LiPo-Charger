// Nano-Sized LiPo Charger for Teensy
// 
// This is a super simple demo sketch that shows 
// off the features of this tiny board.
//
// If you like what you see, visit my Tindie Store 
// for more awesome boards from Hyperbolic Labs!
//
// https://www.tindie.com/stores/Hyperbolic_Designs/
//

  

const uint8_t vsense_pin = A10;


void setup(){

  pinMode(vsense_pin, INPUT);  

  Serial.begin(9600);

  analogReadResolution(16);
  analogReference(INTERNAL);
}


void loop(){

  uint16_t mV = analogRead(vsense_pin)/10;

  
  Serial.print("Power source: ");
  if(mV > 4400)
    Serial.println("USB");
  else
    Serial.println("Battery");


  Serial.print("Charge Status: ");  
  if(mV > 4100)
    Serial.println("Charge complete!\n");
  else
    Serial.println("Charging...\n");


  Serial.print("VIN voltage: ");
  Serial.print(mV);
  Serial.println("mV");  


  delay(1000);
}

