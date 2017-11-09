#include <string>
#pragma once
class Aircraft{
public:
	Aircraft(std::string flightNumber, std::string airline, std::string aircraftType,
		int groundspeed, int altitude, std::string gridReference, int heading);
	void SetFlightNumber(std::string flightNumber);
	std::string GetFlightNumber() const;
	void SetAirline(std::string airline);
	std::string GetAirline() const;
	void SetAircraftType(std::string aircraftType);
	std::string GetAircraftType() const;
	void SetGroundSpeed(int groundSpeed);
	int GetGroundSpeed() const;
	void SetAltitude(int altitude);
	int GetAltitude() const;
	void SetGridReference(std::string gridReference);
	std::string GetGridReference();
	void SetHeading(int heading);
	int GetHeading() const;

private:
	std::string flightNumber_;
	std::string airline_;
	std::string aircraftType_;
	std::string gridReference_;
	int groundSpeed_;
	int altitude_;
	int heading_;
};
