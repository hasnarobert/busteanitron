#include <Arduino.h>

#include "Settings.h"
#include "EEPROMUtils.h"

Settings::Settings() {
	distanceOfFirstCut = EEPROMUtils::readInt(addressOfFirstCut);
	distanceOfSecondCut = EEPROMUtils::readInt(addressOfSecondCut);
}

Settings* Settings::instance() {
	if (Settings::pInstance == NULL) {
		Settings::pInstance = new Settings;
	}
	return Settings::pInstance;
}

bool Settings::validateDistance(int distance) {
	bool invalid = distance < 0 || distance > 32767;
	if (invalid) {
		Serial.println("Max size of int exceeded");
	}
	return invalid;
}

int Settings::getDistanceOfFirstCut() {
	return distanceOfFirstCut;
}

int Settings::getDistanceOfSecondCut() {
	return distanceOfSecondCut;
}

void Settings::writeDistanceOfFirstCut(int distance) {
	if (validateDistance(distance)) {
		return;
	}
	EEPROMUtils::write(addressOfFirstCut, distance);
	distanceOfFirstCut = distance;
}

void Settings::writeDistanceOfSecondCut(int distance) {
	if (validateDistance(distance)) {
		return;
	}
	EEPROMUtils::write(addressOfSecondCut, distance);
	distanceOfSecondCut = distance;
}

Settings* Settings::pInstance = NULL;
