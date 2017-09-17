/* Author: Malcolm Knapp
 *  Class: Embedded Drivers
 *  Project: 2's Complement Example
 * 
 */
//#include <stdint.h>

unsigned int registerHex = 0xFFFF;
uint16_t  u_registerHex = 0xFFFF;
int negative_value;
int postive_value;

void setup() {
  Serial.begin (115200);
  
  Serial.println ("1.8.4");
  Serial.println ("'Negative' uint16_t");
  Serial.print ("Uninterpreted register uint16_t "); Serial.println (u_registerHex);
  Serial.print ("Uninterpreted register uint16_t in Binary: "); Serial.println (u_registerHex, BIN);
  // cast to a signed interpretation
  Serial.print ("int16_t cast register to int16_t "); Serial.println ((int16_t)u_registerHex);
  Serial.print ("int16_t cast register to int16_t in Binary: "); Serial.println ((int16_t)u_registerHex, BIN);
  Serial.println("");
  
  Serial.println ("'Negative' unsigned int");
  Serial.print ("Uninterpreted register unsigned int "); Serial.println (registerHex);
  Serial.print ("Uninterpreted register unsigned int in Binary: "); Serial.println (registerHex, BIN);
  // cast to a signed interpretation
  Serial.print ("Int cast register to signed int "); Serial.println ((int)registerHex);
  Serial.print ("register cast to signed "); Serial.println ((signed)registerHex);
  Serial.print ("Cast register Hex in Binary: "); Serial.println ((signed)registerHex, BIN);
  Serial.println("");
  
  registerHex = 0x0FFF;
  Serial.println ("'Positive' Hex");
  Serial.print ("Uninterpreted register Hex "); Serial.println (registerHex);
  Serial.print ("Uninterpreted register Hex in Binary: "); Serial.println (registerHex, BIN);
  // cast to a signed interpretation
  Serial.print ("Int cast register Hex "); Serial.println ((int)registerHex);
  Serial.print ("Interpreted register Hex "); Serial.println ((signed)registerHex);
  Serial.print ("Interpreted register Hex in Binary: "); Serial.println (registerHex, BIN);
  Serial.println("");
  
  Serial.println ("Negation"); 
  // Note that this is a to negation so it will convert a positive number 
  // to its negative equivalent and visa versa
  negative_value = ~registerHex+1; // conversion. 
  Serial.print ("Register coverted to negitive number: "); Serial.println (negative_value);
  Serial.print ("Register coverted to negitive number in binary: "); Serial.println (negative_value, BIN); // this is printed as a long so there are 32 bits
  postive_value = ~negative_value+1; //same equestion to covert back :).
  Serial.print ("Register converted back: "); Serial.println (postive_value); 
  Serial.print ("Register coverted to negitive number in binary: "); Serial.println (postive_value, BIN);
}

void loop() {
  // put your main code here, to run repeatedly:

}
