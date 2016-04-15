#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

class StepperMotor {
public:

	enum Direction {
		FORWARD, BACKWARD
	};

	StepperMotor(int stepPin, int dirPin);
	StepperMotor(int stepPin, int dirPin, int stepSleepInMicros);
	void setDirection(Direction direction);
	void step(int numberOfSteps);
private:
	static int defaultStepSleepInMicros;
	int stepSleepInMicros;
	int stepPin;
	int dirPin;
	Direction direction;
};

#endif
