/*
Berat Biçer
Sec.2
21503050
25.11.2016
*/

#include "ReservationSystem.h"
#include "Flight.h"
#include <iostream>
#include "Reservation.h"
using namespace std;

ReservationSystem::ReservationSystem() {
	this->system_size = 0;
	this->flightSystem = new Flight*[this->system_size];
	for (int i = 0; i < system_size; i++)
		flightSystem[i] = new Flight();

	int base = 0;
	int res_size = 0;
	resSystem = new Reservation*[res_size];
	for (int i = 0; i < res_size; i++)
		resSystem[i] = new Reservation();

	cout << "Confirmation: FlightSystem Created." << endl;
}

ReservationSystem::~ReservationSystem() {
	for (int i = 0; i < system_size; i++)
		if (flightSystem[i] != NULL)
			delete flightSystem[i];
	if(flightSystem != NULL)
		delete[] flightSystem;
	

	for (int i = 0; i < res_size; i++)
		if (resSystem[i] != NULL)
			delete resSystem[i];
	if(resSystem != NULL)
		delete[] resSystem;
}

void ReservationSystem::addFlight(const int flightNo, const int rowNo, const int seatNo) {
	if (flightNo > 0 && rowNo > 0 && seatNo > 0) {
		if (system_size == 0){
			system_size++;
			flightSystem = new Flight*[system_size];
			flightSystem[0] = new Flight(flightNo, rowNo, seatNo);
			cout << flightSystem[0]->getFlightNo() << endl;
			cout << "Confirmation: Flight Created." << endl;
			cout << "FlightSystem Size: " << this->system_size << endl;
		}
		else if (system_size > 0) {
			// Create copy array
			Flight** system_copy = new Flight*[system_size];

			for (int i = 0; i < system_size; i++)
				system_copy[i] = flightSystem[i];

			delete flightSystem;

			system_size++;
			flightSystem = new Flight*[system_size];
			for (int i = 0; i < system_size-1; i++)
				flightSystem[i] = system_copy[i];

			/*// Initialize the elements of that copy array using a copy constructor
			for (int i = 0; i < system_size; i++)
				system_copy[i] = new Flight(*(flightSystem[i]));

			// Delete the flight system
			for (int i = 0; i < system_size; i++)
				if (this->flightSystem[i] != NULL)
					delete flightSystem[i];
	
			if(this->flightSystem != NULL)
				delete[] this->flightSystem;

			// Increment the size of the system
			this->system_size++;
		
			// Reinitialize the parameters
			flightSystem = new Flight*[system_size];
	
			for (int i = 0; i < system_size-1; i++)
				flightSystem[i] = new Flight( *(system_copy[i]) );
		
			// Add new element to your parameters
			flightSystem[system_size - 1] = new Flight(flightNo, rowNo, seatNo);
	
			// Delete the copy array
			for (int i = 0; i < system_size - 1; i++)
				delete system_copy[i];
			if(system_copy != NULL)
				delete[] system_copy;*/

			flightSystem[system_size - 1] = new Flight(flightNo, rowNo, seatNo);
			delete system_copy;
			// Print confirmation message
			cout << "Confirmation: Flight Created." << endl;
			cout << "SystemSize: " << system_size << endl;
		}
		else
			cout << "Error: Invalid SystemSize" << endl;
	}
	else
		cout << "Error: Invalid Values Entered." << endl;
}

void ReservationSystem::cancelFlight(const int flightNo) {
	if (flightNo > 0) {
		if (system_size > 1) {
			// Determine if a flight with given id exists in system and its index
			bool is_exists = false;
			int index = 0; // Index of the element that is going to be deleted
			for (int i = 0; i < system_size; i++)
				if (flightSystem[i]->getFlightNo() == flightNo) {
					is_exists = true;
					index = i;
				}
		
			// Create Copy pointer
			Flight** system_copy = new Flight*[system_size];

			for (int i = 0; i < system_size; i++)
				system_copy[i] = flightSystem[i];

			delete flightSystem;

			system_size--;

			flightSystem = new Flight*[system_size];

			for (int i = 0; i < index; i++)
				flightSystem[i] = system_copy[i];

			for (int i = index; i < system_size; i++)
				flightSystem[i] = system_copy[i + 1];

			delete system_copy;
			/*// Initialize it to flightSystem by deep copying
			for (int i = 0; i < system_size; i++)
				system_copy[i] = new Flight(*(flightSystem[i]));

			// Delete flight system
			for (int i = 0; i < system_size; i++)
				if (flightSystem[i] != NULL)
					delete flightSystem[i];
			if (flightSystem != NULL)
				delete[] flightSystem;

			// Decrement system size
			system_size--;
		
			// Reinitialize flightSystem to copy pointer by deep copying
			flightSystem = new Flight*[system_size];

			for (int i = 0; i < index; i++)
				flightSystem[i] = new Flight(*(system_copy[i]));
			for (int i = index; i < system_size; i++)
				flightSystem[i] = new Flight(*(system_copy[i + 1]));

			// Delete copy pointer
			for (int i = 0; i < system_size + 1; i++)
				if (system_copy[i] != NULL)
					delete system_copy[i];
			if(system_copy != NULL)
				delete[] system_copy;*/

			// Print confirmation message
			cout << "Confirmation: Flight Deleted." << endl;
			cout << "SystemSize: " << system_size << endl;
		}
		else if (system_size == 1) {
			if (flightSystem[0]->getFlightNo() == flightNo) {
				if(flightSystem[0] != NULL)
					delete flightSystem[0];
				if(flightSystem != NULL)
					delete[] flightSystem;
				system_size = 0;
				flightSystem = NULL;

				cout << "Confirmation: Flight Deleted." << endl;
				cout << "SystemSize: " << system_size << endl;
			}
			else
				cout << "Error: Flight Doesn't Exist." << endl;
		}
		else
			cout << "Error: Invalid System Size." << endl;
	}
	else
		cout << "Error: Invalid FlightId." << endl;
}

void ReservationSystem::showAllFlights() {
	if (system_size > 0)
		for (int i = 0; i < system_size; i++)
			cout << "Flight ID: " << flightSystem[i]->getFlightNo() << " Empty Seats: " << flightSystem[i]->getAvailableSeatCount() << endl;
	else
		cout << "System Empty." << endl;
}

void ReservationSystem::showFlight(const int flightNo) {
	int index = 0;
	for (int i = 0; i < system_size; i++)
		if (flightSystem[i]->getFlightNo() == flightNo)
			index = i;
	flightSystem[index]->getSeatingPlan();
}

int ReservationSystem::makeReservation(const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol) {
	if (flightNo > 0 && numPassengers > 0) {
		if (res_size == 0){
			for (int i = 0; i < res_size; i++)
				delete resSystem[i];
			delete[] resSystem;

			res_size = 1;
			base = 1;

			resSystem = new Reservation*[res_size];
			resSystem[0] = new Reservation(numPassengers, seatRow, seatCol, base, flightNo);
			
			int index = 0;
			for (int i = 0; i < system_size; i++)
				if (flightSystem[i]->getFlightNo() == flightNo)
					index = i;

			flightSystem[index]->setSeatingPlan(numPassengers, seatRow, seatCol);
			cout << "Confirmation: Reservation Created." << endl;
			return base;
		}
		else if (res_size > 0){
			Reservation** copy = new Reservation*[res_size];
			for (int i = 0; i < res_size; i++)
				copy[i] = resSystem[i];

			delete resSystem;

			res_size++;
			resSystem = new Reservation*[res_size];

			for (int i = 0; i < res_size - 1; i++)
				resSystem[i] = copy[i];

			int index = 0;
			for (int i = 0; i < system_size; i++)
				if (flightSystem[i]->getFlightNo() == flightNo)
					index = i;

			delete copy;

			base++;
			resSystem[res_size - 1] = new Reservation(numPassengers, seatRow, seatCol, base, flightNo);
			flightSystem[index]->setSeatingPlan(numPassengers, seatRow, seatCol);
			cout << "Confirmation: Reservation Created." << endl;
			return base;

			/*// Create copy array
			Reservation** copy = new Reservation*[res_size];
			for (int i = 0; i < res_size; i++)
				copy[i] = new Reservation(*(resSystem[i]));

			// Delete ResSystem
			for (int i = 0; i < res_size; i++)
				if (resSystem[i] != NULL)
					delete resSystem[i];
			if(resSystem != NULL)
				delete[] resSystem;

			// Increment size
			res_size++;

			// Reinitialize System
			resSystem = new Reservation*[res_size];
			for (int i = 0; i < res_size-1; i++)
				resSystem[i] = new Reservation( *(copy[i]) );

			// Find flight
			int index = 0;
			for (int i = 0; i < system_size; i++)
				if (flightSystem[i]->getFlightNo() == flightNo)
					index = i;

			// Create Reservation
			base++;
			resSystem[res_size - 1] = new Reservation(numPassengers, seatRow, seatCol, base, flightNo);
			flightSystem[index]->setSeatingPlan(numPassengers, seatRow, seatCol);
			cout << "Confirmation: Reservation Created." << endl;
			return base;

			// Delete copy
			for (int i = 0; i < res_size-1; i++)
				if (copy[i] != NULL)
					delete copy[i];
			if (copy != NULL)
				delete[] copy;*/
		}
		else
			cout << "Error: Invalid ResSize." << endl;
	}
	else
		cout << "Error: Invalid Parameters." << endl;
	return -1;
}

void ReservationSystem::cancelReservation(const int resCode) {
	if (resCode > 0) {
		if (res_size == 1) {
			if (resSystem[0]->getID() == resCode) {
				flightSystem[0]->resetSeatingPlan(resSystem[0]->getPassengers(),resSystem[0]->getRows(), resSystem[0]->getCols());
				
				if(resSystem[0] != NULL)
					delete resSystem[res_size-1];
				if(resSystem != NULL)
					delete[] resSystem;
				res_size = 0;

				resSystem = new Reservation*[res_size];
				for (int i = 0; i < res_size; i++)
					resSystem[i] = new Reservation();
			}
			else
				cout << "Error: No Reservation With Given ResCode Exists." << endl;
		}
		else if (res_size > 1) {

			int res_index = 0;
			int flight_id = 0;
			int flight_index = 0;

			// Finding the reservation
			for (int i = 0; i < res_size; i++)
				if (resSystem[i]->getID() == resCode)
					res_index = i;

			// Finding Flight
			flight_id = resSystem[res_index]->getFlight();
			for (int i = 0; i < system_size; i++)
				if (flightSystem[i]->getFlightNo() == flight_id)
					flight_index = i;

			// Copying ResSystem
			Reservation** copy = new Reservation*[res_size];
			for (int i = 0; i < res_size; i++)
				copy[i] = resSystem[i];

			delete resSystem;

			res_size--;
			resSystem = new Reservation*[res_size];

			for (int i = 0; i < res_index; i++)
				resSystem[i] = copy[i];
			for (int i = res_index; i < res_size; i++)
				resSystem[i] = copy[i + 1];

			delete copy;
			flightSystem[flight_index]->resetSeatingPlan(resSystem[res_index]->getPassengers(), resSystem[res_index]->getRows(), resSystem[res_index]->getCols());

			/*int res_index = 0;
			int flight_id = 0;
			int flight_index = 0;
			
			// Finding the reservation
			for (int i = 0; i < res_size; i++)
				if (resSystem[i]->getID() == resCode)
					res_index = i;

			// Finding Flight
			flight_id = resSystem[res_index]->getFlight();
			for (int i = 0; i < system_size; i++)
				if (flightSystem[i]->getFlightNo() == flight_id)
					flight_index = i;

			// Copying ResSystem
			Reservation** copy = new Reservation*[res_size];
			for (int i = 0; i < res_size; i++)
				copy[i] = new Reservation(*(resSystem[i]));

			// Clear Flight
			flightSystem[flight_index]->resetSeatingPlan(resSystem[res_index]->getPassengers(), resSystem[res_index]->getRows(), resSystem[res_index]->getCols());

			// Delete ResSystem
			for (int i = 0; i < res_size; i++)
				if (resSystem[i] != NULL)
					delete resSystem[i];
			if(resSystem != NULL)
				delete[] resSystem;

			// Decrement System Size
			res_size--;

			// Reinitialize ResSystem
			resSystem = new Reservation*[res_size];
			for (int i = 0; i < res_index; i++)
				resSystem[i] = new Reservation(*(copy[i]));
			for(int i = res_index; i < res_size; i++)
				resSystem[i] = new Reservation(*(copy[i+1]));

			// Delete copy
			for (int i = 0; i < res_size; i++)
				if (copy[i] != NULL)
					delete copy[i];
			if (copy != NULL)
				delete[] copy;*/
			cout << "Confirmation: Reservation Cancelled" << endl;
		}
		else
			cout << "Error: Invalid ResSize." << endl;
	}
	else
		cout << "Error: Invalid ResCode." << endl;
}

void ReservationSystem::showReservation(const int resCode) {
	int res_index = 0;
	for (int i = 0; i < res_size; i++)
		if (resSystem[i]->getID() == resCode)
			res_index = i;

	resSystem[res_index]->showReservation();
}