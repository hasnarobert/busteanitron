#include <Arduino.h>

#include "StepperMotor.h"

StepperMotor::StepperMotor(int stepPin, int dirPin) :
		StepperMotor(stepPin, dirPin, defaultStepSleepInMicros) {
}

StepperMotor::StepperMotor(int stepPin, int dirPin, int stepSleepInMicros) {
	this->stepPin = stepPin;
	this->dirPin = dirPin;
	this->stepSleepInMicros = stepSleepInMicros;
	direction = FORWARD;
	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
}

void StepperMotor::setDirection(Direction direction) {
	this->direction = direction;
}

void StepperMotor::step(int numberOfSteps) {
	if (numberOfSteps <= 0) {
		return;
	}
	// Set direction of movement
	digitalWrite(dirPin, direction == FORWARD ? LOW : HIGH);

	while (numberOfSteps--) {
		digitalWrite(stepPin, HIGH);
		delayMicroseconds (stepSleepInMicros);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(stepSleepInMicros);
	}
}

// TODO: Consider adding functionality to also control the speed.
// Minimum seems to be 300 but may be motor dependent.
int StepperMotor::defaultStepSleepInMicros = 500;
