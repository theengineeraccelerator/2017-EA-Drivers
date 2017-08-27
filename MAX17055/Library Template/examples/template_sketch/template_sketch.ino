#include <LibraryTemplate.h>

//**************************************************
/*
  Author: Malcolm Knapp
  Project: Arduino Library Template Example
  Date: 8/26/17
  Version: 0.1
  Description: A example for an Arduino library template.  
*/ 
//**************************************************

// Constructor Call
LibraryTemplate libarayTemplate = LibraryTemplate(3);

void setup()
{
Serial.begin(9600);
}

void loop()
{
  libarayTemplate.publicFunction();
  delay(500);
}

