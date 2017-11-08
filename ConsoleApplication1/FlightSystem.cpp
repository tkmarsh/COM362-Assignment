#include "stdafx.h"
#include "FlightSystem.h"

FlightSystem::FlightSystem(){
}

void FlightSystem::AddAircraft(std::string flightNumber, std::string airline, std::string aircraftType,
	int groundspeed, int altitude, std::string gridReference, int heading) {
	aircraftList_.push_back(Aircraft(flightNumber, airline, aircraftType, groundspeed, altitude, gridReference, heading));
}

std::vector<Aircraft> FlightSystem::ListAircraft() {
	return aircraftList_;
}

std::vector<Aircraft> FlightSystem::ListAllCruisingAircraft() {
	for (int index = 0; index < aircraftList_.size(); index++) {
		if (aircraftList_.at(index).GetAltitude >=30000) {
			returnedAircraft_.push_back(aircraftList_.at(index));
		}
	}
	return returnedAircraft_;
}

void FlightSystem::RemoveAircraft(std::string flightNumber) {
	for (int index = 0; index < aircraftList_.size(); index++) {
		if (aircraftList_.at(index).GetFlightNumber() == flightNumber) {
			aircraftList_.erase(aircraftList_.begin() + index);
		}
	}
}
void FlightSystem::ChangeHeading(std::string flightNumber, int heading) {
	for (int index = 0; index < aircraftList_.size(); index++) {
		if (aircraftList_.at(index).GetFlightNumber() == flightNumber) {
			aircraftList_.at(index).SetHeading(heading);
		}
	}
}

int FlightSystem::GetHeading(std::string flightNumber) {
	for (int index = 0; index < aircraftList_.size(); index++) {
		if (aircraftList_.at(index).GetFlightNumber() == flightNumber) {
			return aircraftList_.at(index).GetHeading;
		}
	}
}

void FlightSystem::ChangeAltitude(std::string flightNumber,int altitude){
	for (int index = 0; index < aircraftList_.size(); index++) {
		if (aircraftList_.at(index).GetFlightNumber() == flightNumber) {
			aircraftList_.at(index).SetAltitude(altitude);
		}
	}
}

int FlightSystem::GetAltitude(std::string flightNumber) {
	for (int index = 0; index < aircraftList_.size(); index++) {
		if (aircraftList_.at(index).GetFlightNumber() == flightNumber) {
			return aircraftList_.at(index).GetAltitude;
		}
	}
}

int FlightSystem::NumAircraftinSector() {
	return aircraftList_.size();
}