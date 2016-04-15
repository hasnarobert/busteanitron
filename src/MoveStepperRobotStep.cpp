#include "MoveStepperRobotStep.h"

MoveStepperRobotStep::MoveStepperRobotStep(StepperMotor *motor,
		StepperMotor::Direction direction, int steps) {
	this->motor = motor;
	this->direction = direction;
	this->steps = steps;
}

void MoveStepperRobotStep::execute() {
	motor->setDirection(direction);
	if (steps > 0) {
		motor->step(1);
		--steps;
	}
}

bool MoveStepperRobotStep::isFinished() {
	return steps == 0;
}

void MoveStepperRobotStep::abort() {
	steps = 0;
}
