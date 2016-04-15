#ifndef BASE_ROBOT_STEP_H
#define BASE_ROBOT_STEP_H

class BaseRobotStep {
public:
	virtual void execute() = 0;
	virtual bool isFinished() = 0;
	virtual void abort() = 0;
	virtual ~BaseRobotStep() = 0;
};

#endif
