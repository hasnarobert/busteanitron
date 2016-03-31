#include <Arduino.h>

#include "BaseRobotSequece.h"

BaseRobotSequence::BaseRobotSequence(int numberOfSteps) {
	this->numberOfSteps = numberOfSteps;
	steps = new BaseRobotStep*[numberOfSteps];
	currentStepCountToAdd = 0;
	currentStepCountToExecute = 0;

	for (int i = 0; i < numberOfSteps; ++i) {
		steps[i] = NULL;
	}
}

BaseRobotSequence::~BaseRobotSequence() {
	for (int i = 0; i < numberOfSteps; ++i) {
		if (steps[i] != NULL) {
			delete steps[i];
		}
	}
	delete steps;
}

void BaseRobotSequence::execute() {
	if (isFinished()) {
		//TODO log, error handling??? Everything is already done
		return;
	}

	if (steps[currentStepCountToExecute] == NULL) {
		//TODO log, error handling???
		return;
	}

	steps[currentStepCountToExecute]->execute();
	if (steps[currentStepCountToExecute]->isFinished()) {
		++currentStepCountToExecute;
	}
}

bool BaseRobotSequence::isFinished() {
	return currentStepCountToExecute >= numberOfSteps;
}

void BaseRobotSequence::addStep(BaseRobotStep *step) {
	if (currentStepCountToAdd >= numberOfSteps) {
		//TODO log, error handling???
		return;
	}
	steps[currentStepCountToAdd++] = step;
}
