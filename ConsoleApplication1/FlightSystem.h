#include "Aircraft.h"
#include <string>
#include <vector>
#pragma once
class FlightSystem{

public:
	FlightSystem();
	void AddAircraft(std::string flightNumber, std::string airline, std::string aircraftType,
		int groundspeed, int altitude, std::string gridReference, int heading);
	std::vector<Aircraft> ListAircraft();
	std::vector<Aircraft> ListAllCruisingAircraft();
	std::vector<Aircraft> returnedAircraft_;
	void RemoveAircraft(std::string flightNumber);
	void ChangeHeading(std::string flightNumber, int heading);
	int GetHeading(std::string flightNumber);
	void ChangeAltitude(std::string flightNumber, int altitude);
	int GetAltitude(std::string flightNumber);
	int NumAircraftinSector();

	std::vector<Aircraft> aircraftList_;

};

	