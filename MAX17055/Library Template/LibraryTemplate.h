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

// include guard - this makes sure that the header is only included once
#ifndef LibraryTemplate_h
#define LibraryTemplate_h

// include defines for all fixed numbers to make them more human readable and for build options 
// For example register addresses, error codes, calculation constants etc
#define TEMPLATE_VALUE 1
#define BIT_SHIFT 2
#define FIELD_SHIFT 3

// include macros as needed
#define shift_bit(x) 1 << (x)
#define shift_field(x,y) (y) << (x)

// include Arduino functions
#include "Arduino.h"

// class description
class LibraryTemplate
{
  // API for this library. Theses functions are what the .ino will call
  public:
    LibraryTemplate(int);
    void publicFunction(void);

  // internal functions for this library. These function can only be called by this library
  private:
    int setup_value;
    void privateFunction(void);
};

#endif

