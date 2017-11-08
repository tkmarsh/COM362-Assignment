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

}

void FlightSystem::RemoveAircraft(std::string flightNumber) {
	//week 4 vectors
}
void FlightSystem::ChangeHeading(std::string flightNumber, int heading) {

}

int FlightSystem::GetHeading(std::string flightNumber) {

}

void FlightSystem::ChangeAltitude(std::string flightNumber,int altitude){

}

int FlightSystem::GetAltitude(std::string flightNumber) {

}

int FlightSystem::NumAircraftinSector() {

}