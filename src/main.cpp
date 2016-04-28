//#include <Arduino.h>
//
//#include "Settings.h"
//#include "BaseRobotSequece.h"
//#include "BaseRobotStep.h"
//#include "StepperMotor.h"
//#include "MoveStepperRobotStep.h"
//
//class StepperSequence: public BaseRobotSequence {
//public:
//	StepperSequence(StepperMotor *motor, int halfRotation) :
//			BaseRobotSequence(3) {
//		for (int i = 0; i < 3; ++i) {
//			MoveStepperRobotStep *step = new MoveStepperRobotStep(motor,
//					i & 1 ? StepperMotor::FORWARD : StepperMotor::BACKWARD,
//					halfRotation * (i + 1));
//			addStep(step);
//		}
//	}
//};
//
//BaseRobotSequence *sequence;
//BaseRobotSequence *sequence2;
//StepperMotor *stepperMare;
//StepperMotor *stepperMic;
//
//const int stepPinMare = 3;
//const int dirPinMare = 2;
//
//const int stepPinMic = 5;
//const int dirPinMic = 4;
//int a = 0;
//
//void setup() {
//	Serial.begin(9600);
////	Settings::instance()->writeDistanceOfFirstCut(111);
////	Settings::instance()->writeDistanceOfSecondCut(1024);
//
//	stepperMare = new StepperMotor(stepPinMare, dirPinMare, 1000);
//	stepperMic = new StepperMotor(stepPinMic, dirPinMic, 5000);
//	sequence = new StepperSequence(stepperMare, 200);
//	sequence2 = new StepperSequence(stepperMic, 24);
//}
//
//void loop() {
////	if (sequence != NULL && !sequence->isFinished()) {
////		sequence->execute();
////	}
//	Serial.println("Gata");
//	delay(1000);
//
////	if (sequence2 != NULL && !sequence2->isFinished()) {
////		sequence2->execute();
////	}
//}

//Asem Khattab Aug 2 2014
bool change = false;

//calling the keypad library.
#include <Keypad.h>
#include <Arduino.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

//defining the symbols on the buttons of the keypads.
char hexaKeys[ROWS][COLS] = { { '1', '2', '3', 'A' }, { '4', '5', '6', 'B' }, {
		'7', '8', '9', 'C' }, { '*', '0', '#', 'D' } };
byte colPins[ROWS] = { 11, 10, 9, 8 }; //pins connected to the row pinouts of the keypad
byte rowPins[COLS] = { 7, 6, 5, 4 }; //pins connected to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS,
		COLS);

//determining the pin connected to an LED.
// Pin 13 has an LED connected on most Arduino boards.
//const int led = 13;

//when 'A' is pressed allow the user to input a key.

void setup() {
	Serial.begin(9600);
}

void loop() {
	char key = customKeypad.getKey();

	if (key) {
		Serial.println(key);
	}
}

