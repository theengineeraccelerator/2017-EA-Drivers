
//**************************************************
/*
  Author: Malcolm Knapp
  Project: 
  Date: 
  Version:
  Description:
*/ 
//***************************************************

String userInput = "";
boolean cmdFlag = false;

String cmdType = "";
String cmdSubType ="";
String cmdBody = "";

typedef unsigned char byte;

unsigned long BASE_TIMEOUT = 1000; // timer tick for the whole system set at 1s.  Set to 1000 for release
unsigned long baseTimedOut = 1000;

byte seconds = 0;
byte hours = 0;
byte days = 0;

unsigned long interval1_start_time = 0;
unsigned long INTERVAL1_DURATION = 5*1000;  // in milliseconds

enum {
  // States
  STATE1 = 1,
  STATE2
} STATES;

enum {
  event1 = 0,
  event2,
  ENTRY,
  NONE
} EVENTS;

byte state = STATE1;       // Tracks current state
byte prevState = STATE1;
byte event = NONE;        // Triggers a particular action within current state


//**********************************************************************************************
/* 
   Timers:
   
 */
//**********************************************************************************************
void updatePeriodicTimers () {
  
    //Serial.println("1 second");
    if (seconds == 60) {
        seconds = 0;
        hours++;
    } else { 
      seconds++;
    }
    
    if (hours == 24) {
      hours = 0;
      days++;
    } else { 
      hours++;
    }
    
    if (seconds == 10) {
      // set event
 
    }
    
}

void updateIntervalTimers () {
    if (millis() - interval1_start_time > INTERVAL1_DURATION) {
    // set event
    }
}


void updateState () {
 switch (state) {
    //**********************************************************************************************
    /* 
     State Machine Description:
     
     */
    //**********************************************************************************************

  case STATE1:
  
      if (event == event1) {
        Serial.println ("in event 1");
        Serial.println ("start timer 0");

        event = NONE;
      }
   
    break; 
    
    case STATE2:
    
      if (event == event2) {
        Serial.println ("in event 2");
        Serial.println ("start timer 1");
        event = NONE;
      }
   
    break;
    
    }
    
    if (prevState != state) {
      Serial.print ("new state: "); Serial.println (state);
      prevState = state;
    }
      
}

//**********************************************************************************************
/* 
 Function: parseCommand
 
 Inputs: char *cmd: command parsed
 
 Returns: None
 
 Description: parses commands that come from either the PC or the GSM module. Commands are of 
 the form
 
 XXXZZZZZZZZZZZZZZZZ
 
 XXX: Command type
 ZZZZZZZZZZZ: Command body
 
 Commands 
 
 */
//**********************************************************************************************
void parseCommand (String cmd) {
  int len = 0;
  int index;
  byte section = 0;
  char delimiter = ' ';
  for (index = 0; index < cmd.length(); index++) {
    if (cmd.charAt(index) == delimiter) section++;
    else {
      switch (section){
        case 0: 
          Serial.println ("section 0");
          cmdType.concat(cmd.charAt(index));
        break;
        case 1: 
          Serial.println ("section 1");
          cmdBody.concat(cmd.charAt(index));
        break;
      }
    }
  }
  
  Serial.print("cmd type: "); Serial.println(cmdType);
  Serial.print("cmd Body: "); Serial.println(cmdBody);

  if(cmdType.equals("TEST")) {
    Serial.println ("This is a test");
      if(cmdBody.equals("TIMER")) {
        Serial.println ("We testing the timer ");
      }
  }
  
cmdType = "";
cmdBody = "";
}


void setup () {
  Serial.begin (115200);
  Serial.println("Lets Begin");

}

void loop () {
  if(millis() - baseTimedOut > BASE_TIMEOUT) { 
    updatePeriodicTimers ();
    updateState();
    //printSystemState ();
    
    baseTimedOut = millis();
  }

  updateIntervalTimers ();
   
//**********************************************************************************************
/* 
   PC Serial Input: Serial input comes from a PC over a USB cable. The termination character is
   a carriage return. It is read in and then sent to command parsing. 
 */
//**********************************************************************************************
  
  if(Serial.available()>0){
     int inByte = Serial.read();
    //Serial.print("in byte");  Serial.print(inByte); debug();
    if (inByte == 13) {  // carriage return
      //Serial.print("Command sent: ");  Serial.print(userInput); debug();
      parseCommand(userInput);
      userInput = "";
      inByte = 0;
    }
    else {
      userInput.concat(char(inByte));
    }
  }
}
