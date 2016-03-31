#include <Arduino.h>

#include "Settings.h"
#include "BaseRobotSequece.h"
#include "BaseRobotStep.h"
#include "StepperMotor.h"

class SampleRobotStep: public BaseRobotStep {
public:
	SampleRobotStep(int N) {
		this->N = N;
	}

	void execute() {
		if (N > 0) {
			Serial.println(N);
			--N;
		}
	}

	bool isFinished() {
		return N == 0;
	}

private:
	int N;

};

class SampleRobotSequence: public BaseRobotSequence {
public:
	SampleRobotSequence() :
			BaseRobotSequence(4) {
		for (int i = 1; i <= 4; ++i) {
			SampleRobotStep *step = new SampleRobotStep(i);
			addStep(step);
		}
	}
};

BaseRobotSequence *sequence;
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
//	sequence = new SampleRobotSequence();

	stepperMare = new StepperMotor(stepPinMare, dirPinMare);
	stepperMic = new StepperMotor(stepPinMic, dirPinMic, 5000);
}

void loop() {
	Serial.print("loop: ");
	Serial.print(a);
	stepperMare->setDirection(
			a % 2 == 1 ? StepperMotor::FORWARD : StepperMotor::BACKWARD);
	stepperMare->step(400);

	stepperMic->setDirection(
			a % 2 == 0 ? StepperMotor::FORWARD : StepperMotor::BACKWARD);
	stepperMic->step(48);
	++a;
	delay(2000);

//	Serial.print(Settings::instance()->getDistanceOfFirstCut());
//	Serial.print(" ");
//	Serial.println(Settings::instance()->getDistanceOfSecondCut());

//	if (Serial.available() > 0) {
//		Serial.println("Read: " + Serial.readString());
//	}
//
//	delay(1000);
//
//	if (sequence != NULL && !sequence->isFinished()) {
//		sequence->execute();
//	} else {
//		delete sequence;
//		sequence = NULL;
//		Serial.println("Secventa terminata");
//	}

}
