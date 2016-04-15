#ifndef MOVE_STEPPER_ROBOT_STEP_H
#define MOVE_STEPPER_ROBOT_STEP_H

#include "BaseRobotStep.h"
#include "StepperMotor.h"

class MoveStepperRobotStep: public BaseRobotStep {
public:
	MoveStepperRobotStep(StepperMotor *motor, StepperMotor::Direction direction,
			int steps);
	virtual void execute();
	virtual bool isFinished();
	virtual void abort();
private:
	StepperMotor *motor;
	StepperMotor::Direction direction;
	int steps;
};

#endif
