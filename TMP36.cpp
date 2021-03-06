/*
  Arduino Library to TMP36 temperature sensor
  More info in http://www.analog.com/static/imported-files/data_sheets/TMP35_36_37.pdf
*/

#include "Arduino.h"
#include "TMP36.h"

//
// Constructor
//
// initialize connections
TMP36::TMP36(uint8_t inPin){

	_inPin = inPin;
	_refPin = NO_REF;
}


//
// read
//
// read sensor and return the value in Celsius degrees
float TMP36::read(){

	int inValue = analogRead(_inPin);
	//correct sensor output offset (0,5V)
	float voltage = inValue * (5.0 / 1023.0);
	voltage -= 0.5;
	return voltage * 100;	// sensor precision 10mV/�C	
}