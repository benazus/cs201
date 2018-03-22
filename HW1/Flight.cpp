/*
Berat Biçer
Sec.2
21503050
25.11.2016
*/

#include "Flight.h"
#include <iostream>
using namespace std;

Flight::Flight(const int flightNo, const int row_size, const int column_size) {
	// Initializing parameters using given variables
	this->flightNo = flightNo;
	this->row_size = row_size;
	this->column_size = column_size;

	this->aircraft = new char*[row_size];
	for (int i = 0; i < row_size; i++)
		this->aircraft[i] = new char[column_size];

	// Setting seats empty
	for (int i = 0; i < row_size; i++)
		for (int j = 0; j < column_size; j++)
			aircraft[i][j] = 'o';
}

Flight::Flight() {
	this->flightNo = 0;
	this->column_size = 0;
	this->row_size = 0;
	this->aircraft = NULL;
}

/*Flight::Flight(Flight &flight) {
	// Deleting current aircraft;
	for (int i = 0; i < row_size; i++)
		if (this->aircraft[i] != NULL)
			delete[] aircraft[i];
	if(aircraft != NULL)
		delete[] aircraft;

	// Copying integer values
	this->flightNo = flight.getFlightNo();
	this->row_size = flight.getRowSize();
	this->column_size = flight.getColumnSize();

	// Reinitializing the seating plan
	aircraft = new char*[row_size];
	for (int i = 0; i < row_size; i++)
		aircraft[i] = new char[column_size];

	for (int i = 0; i < row_size; i++)
		for (int j = 0; j < column_size; j++)
			this->aircraft[i][j] = (flight.getAircraft())[i][j];
}*/

Flight::~Flight() {
	for (int i = 0; i < row_size; i++)
		if (aircraft[i] != NULL)
			delete[] aircraft[i];
	if(aircraft != NULL)
		delete[] aircraft;
}

/*void Flight::operator=(Flight &flight) {
	for (int i = 0; i < row_size; i++)
		if (aircraft[i] != NULL)
			delete[] aircraft[i];
	if(aircraft != NULL)
		delete[] aircraft;

	this->flightNo = flight.getFlightNo();
	this->row_size = flight.getRowSize();
	this->column_size = flight.getColumnSize();

	this->aircraft = new char*[row_size];
	for (int i = 0; i < row_size; i++)
		for (int j = 0; j < column_size; j++)
			aircraft[i] = new char[column_size];

	for (int i = 0; i < row_size; i++)
		for (int j = 0; j < column_size; j++)
			aircraft[i][j] = (flight.getAircraft())[i][j];
}*/

int Flight::getAvailableSeatCount() {
	int count = 0;
	for (int i = 0; i < row_size; i++)
		for (int j = 0; j < column_size; j++)
			if (aircraft[i] != NULL && aircraft[i][j] == 'o')
				count++;
	return count;
}

void Flight::getSeatingPlan() {
	cout << "Seating Plan: " << endl;
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < column_size; j++)
				cout << " " << aircraft[i][j] << " ";
		cout << endl;
	}
}

void Flight::setSeatingPlan(const int numPassengers, const int *seatRow, const char *seatCol) {
	for (int i = 0; i < numPassengers; i++)
		this->aircraft[seatRow[i]][seatCol[i]-97] = 'x';

	this->getSeatingPlan();
}

void Flight::resetSeatingPlan(const int numPassengers, const int *seatRow, const char *seatCol) {
	for (int i = 0; i < numPassengers; i++)
		this->aircraft[seatRow[i]][seatCol[i] - 97] = 'o';

	this->getSeatingPlan();
}

int Flight::getFlightNo() {
	return this->flightNo;
}

int Flight::getRowSize() {
	return this->row_size;
}

int Flight::getColumnSize() {
	return this->column_size;
}

char** Flight::getAircraft() {
	return this->aircraft;
}