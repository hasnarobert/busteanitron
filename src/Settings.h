#ifndef SETTINGS_H
#define SETTINGS_H

/**
 * Utility for persisting data into EEPROM
 */
class Settings {
public:

	static Settings* instance();

	int getDistanceOfFirstCut();
	int getDistanceOfSecondCut();
	void writeDistanceOfFirstCut(int distance);
	void writeDistanceOfSecondCut(int distance);

private:
	static Settings *pInstance;

	// All distances are millimeters
	int distanceOfFirstCut, addressOfFirstCut = 0;
	int distanceOfSecondCut, addressOfSecondCut = 2;

	Settings();

	bool validateDistance(int distance);
};

#endif

