#include <Arduino.h>

#include "Settings.h"
#include "BaseRobotSequece.h"
#include "BaseRobotStep.h"
#include "StepperMotor.h"
#include "MoveStepperRobotStep.h"

class StepperSequence: public BaseRobotSequence {
public:
	StepperSequence(StepperMotor *motor, int halfRotation) :
			BaseRobotSequence(3) {
		for (int i = 0; i < 3; ++i) {
			MoveStepperRobotStep *step = new MoveStepperRobotStep(motor,
					i & 1 ? StepperMotor::FORWARD : StepperMotor::BACKWARD,
					halfRotation * (i + 1));
			addStep(step);
		}
	}
};

BaseRobotSequence *sequence;
BaseRobotSequence *sequence2;
StepperMotor *stepperMare;
StepperMotor *stepperMic;

const int stepPinMare = 3;
const int dirPinMare = 2;

const int stepPinMic = 5;
const int dirPinMic = 4;
int a = 0;

void setup() {
	Serial.begin(9600);
//	Settings::instance()->writeDistanceOfFirstCut(111);
//	Settings::instance()->writeDistanceOfSecondCut(1024);

	stepperMare = new StepperMotor(stepPinMare, dirPinMare, 1000);
	stepperMic = new StepperMotor(stepPinMic, dirPinMic, 5000);
	sequence = new StepperSequence(stepperMare, 200);
	sequence2 = new StepperSequence(stepperMic, 24);
}

void loop() {
	if (sequence != NULL && !sequence->isFinished()) {
		sequence->execute();
	}

//	if (sequence2 != NULL && !sequence2->isFinished()) {
//		sequence2->execute();
//	}
}
