#include "stdafx.h"
#include "Aircraft.h"
#include "FlightSystem.h"
#include <iostream>
#include <string>
#include <iomanip>

bool verifyFlightNumber(std::string flightNumber) {
	return true;
}

bool verifyAirline(std::string airline) {
	return true;
}

bool verifyAltitude(int altitude) {
	return true;
}

bool verifySpeed(int groundspeed) {
	return true;
}

bool verifyGrid(std::string gridReference) {
	return true;
}

bool verifyHeading(int heading) {
	return true;
}

void collisionDetection() {

}

void displayMenu() {
	std::cout << "--- Aircraft Control System menu ---\n";
	std::cout << "\n Select an option:\n";
	std::cout << "Register a new Aircraft (1)\n";
	std::cout << "List all registered Aircraft (2)\n";
	std::cout << "List all cruising registered Aircraft (3)\n";
	std::cout << "Remove a registered Aircraft (4)\n";
	std::cout << "Edit the altitude of a registered Aircraft (5)\n";
	std::cout << "Edit the heading of a registered Aircraft (6)\n";
	std::cout << "\nExit the program (7)\n";
}

void printFlight(FlightSystem flightsys, int index) {
	std::vector<Aircraft> aircraftList_ = flightsys.ListAircraft();
	std::cout << std::setw(10) << aircraftList_.at(index).GetFlightNumber();
	std::cout << std::setw(10) << aircraftList_.at(index).GetAirline();
	std::cout << std::setw(10) << aircraftList_.at(index).GetAltitude();
	std::cout << std::setw(10) << aircraftList_.at(index).GetGroundSpeed();
	std::cout << std::setw(10) << aircraftList_.at(index).GetGridReference();
	if (aircraftList_.at(index).GetHeading() >=0 && aircraftList_.at(index).GetHeading() < 90) {
		std::cout << std::setw(8) << "(N) " << aircraftList_.at(index).GetHeading() << std::endl;
	}
	else if (aircraftList_.at(index).GetHeading() >= 90 && aircraftList_.at(index).GetHeading() < 180) {
		std::cout << std::setw(8) << "(E) " << aircraftList_.at(index).GetHeading() << std::endl;
	}
	else if (aircraftList_.at(index).GetHeading() >= 180 && aircraftList_.at(index).GetHeading() < 270) {
		std::cout << std::setw(8) << "(S) " << aircraftList_.at(index).GetHeading() << std::endl;
	}
	else if (aircraftList_.at(index).GetHeading() >= 270 && aircraftList_.at(index).GetHeading() <= 360) {
		std::cout << std::setw(8) << "(W) " << aircraftList_.at(index).GetHeading() << std::endl;
	}
}

void printCruisingFlight(FlightSystem flightsys, int index) {
	std::vector<Aircraft> aircraftList_ = flightsys.ListAllCruisingAircraft();
	std::cout << std::setw(10) << aircraftList_.at(index).GetFlightNumber();
	std::cout << std::setw(10) << aircraftList_.at(index).GetAirline();
	std::cout << std::setw(10) << aircraftList_.at(index).GetAltitude();
	std::cout << std::setw(10) << aircraftList_.at(index).GetGroundSpeed();
	std::cout << std::setw(10) << aircraftList_.at(index).GetGridReference();
	if (aircraftList_.at(index).GetHeading() >= 0 && aircraftList_.at(index).GetHeading() < 90) {
		std::cout << std::setw(8) << "(N) " << aircraftList_.at(index).GetHeading() << std::endl;
	}
	else if (aircraftList_.at(index).GetHeading() >= 90 && aircraftList_.at(index).GetHeading() < 180) {
		std::cout << std::setw(8) << "(E) " << aircraftList_.at(index).GetHeading() << std::endl;
	}
	else if (aircraftList_.at(index).GetHeading() >= 180 && aircraftList_.at(index).GetHeading() < 270) {
		std::cout << std::setw(8) << "(S) " << aircraftList_.at(index).GetHeading() << std::endl;
	}
	else if (aircraftList_.at(index).GetHeading() >= 270 && aircraftList_.at(index).GetHeading() <= 360) {
		std::cout << std::setw(8) << "(W) " << aircraftList_.at(index).GetHeading() << std::endl;
	}
}

int main(){
	int groundspeed;
	int altitude;
	int heading;
	int menuChoice = 0;
	bool exit = false;
	std::string flightNumber;
	std::string airline;
	std::string aircraftType;
	std::string gridReference;
	std::string remove = "";
	std::string titles[] = {"Flight #", "Airline","Altitude","Speed","Grid","Heading"};
	FlightSystem flightsys;
	while (!exit) {
		displayMenu();
		std::cin >> menuChoice;
		switch (menuChoice) {
		case 1:
			std::cout << "Enter flight number: " << std::endl;
			std::cin >> flightNumber;
			std::cout << "Enter airline name: " << std::endl;
			std::cin >> airline;
			std::cout << "Enter aircraft type: " << std::endl;
			std::cin >> aircraftType;
			std::cout << "Enter ground speed: " << std::endl;
			std::cin >> groundspeed;
			std::cout << "Enter altitude: " << std::endl;
			std::cin >> altitude;
			std::cout << "Enter grid reference: " << std::endl;
			std::cin >> gridReference;
			std::cout << "Enter heading: " << std::endl;
			std::cin >> heading;
			flightsys.AddAircraft(flightNumber, airline, aircraftType, groundspeed, altitude, gridReference, heading);
			break;
		case 2: //list aircraft
			for (int x = 0; x < 6; x++) {
				std::cout << std::setw(10) << titles[x];
			}
			std::cout << std::endl;
			for (int i = 0; i < flightsys.NumAircraftinSector(); i++) {
				printFlight(flightsys, i);
			}
			break;
		case 3: //list cruising aircraft //out of bounds
			for (int x = 0; x < 6; x++) {
				std::cout << std::setw(10) << titles[x];
			}
			std::cout << std::endl;
			for (int i = 0; i < (int) flightsys.ListAllCruisingAircraft().size(); i++) {
				printFlight(flightsys, i);
			}
			break;
		case 4: //remove
			std::cout << "Enter flight number of aircraft to remove: ";
			std::cin >> remove;
			flightsys.RemoveAircraft(remove);
			break;
		case 5: //edit altitude
			std::cout << "Enter flight number to change altitude of: ";
			std::cin >> flightNumber;
			std::cout << "Enter new altitude for " << flightNumber << ": ";
			std::cin >> altitude;
			flightsys.ChangeAltitude(flightNumber, altitude);
			break;
		case 6: //edit heading
			std::cout << "Enter flight number to change heading of: ";
			std::cin >> flightNumber;
			std::cout << "Enter new heading for " << flightNumber << ": ";
			std::cin >> heading;
			flightsys.ChangeAltitude(flightNumber, heading);
			break;
		case 7: //exit
			//exit(0);
			break;


		}
		menuChoice = 0;
	}
    return 0;
}

