#ifndef BASE_ROBOT_SEQUENCE_H
#define BASE_ROBOT_SEQUENCE_H

#include "BaseRobotStep.h"

/**
 * A container for a ordered list of steps to execute.
 */
class BaseRobotSequence {
public:
	BaseRobotSequence(int numberOfSteps);
	virtual ~BaseRobotSequence() = 0;

	/**
	 * Executes each part of each step in order.
	 */
	void execute();

	/**
	 * is true when all steps are executed.
	 */
	bool isFinished();

protected:
	/**
	 * Adds a step to the list. This class owns all steps it handles.
	 */
	void addStep(BaseRobotStep *step);

private:
	BaseRobotStep **steps;
	int numberOfSteps;
	int currentStepCountToAdd;
	int currentStepCountToExecute;
};

#endif
