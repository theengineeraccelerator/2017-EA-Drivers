//**************************************************
/*
  Author: Malcolm Knapp
  Project: Arduino Library Template
  Date: 8/26/17
  Version: 0.1
  Description: A compilable template for an arduino 
               library. 
*/ 
//**************************************************

// include Arduino API
#include "Arduino.h"

// include this library's header file
#include "LibraryTemplate.h"

// Constructor

LibraryTemplate::LibraryTemplate(int setupValue)
{
  // initialize variables
  setup_value = setupValue;

  // setup hardware, functions and anything else needed by this library 
  pinMode(13, OUTPUT);
  
}

// Public Methods 
// Accessible functions that can be used by other Arduino sketches and other libraries 

void LibraryTemplate::publicFunction(void)
{
  Serial.print("value is "); Serial.println(setup_value);
  Serial.print("value + TEMPLATE_VALUE is "); Serial.println(TEMPLATE_VALUE + setup_value);
  Serial.print("bit shift ");Serial.println (shift_bit(BIT_SHIFT), BIN);
  Serial.print("field shift "); Serial.println(shift_field(FIELD_SHIFT, setup_value), BIN);


  // internal function call
  privateFunction();
}

// Private Methods
// Internal functions

void LibraryTemplate::privateFunction(void)
{
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
}

