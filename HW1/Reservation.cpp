/*
Berat Biçer
Sec.2
21503050
25.11.2016
*/

#include "Reservation.h"
#include <iostream>
using namespace std;

Reservation::Reservation(const int numPassengers, const int* seatRow, const char* seatCol, const int id, const int flight) {
	this->size = numPassengers;
	this->id = id;
	this->rows = new int[this->size];
	this->cols = new char[this->size];

	for (int i = 0; i < size; i++) {
		rows[i] = seatRow[i];
		cols[i] = seatCol[i];
	}

	this->flight = flight;
}

Reservation::Reservation() {
	this->rows = NULL;
	this->cols = NULL;
	this->size = 0;
	this->id = 0;
	this->flight = 0;
}

/*Reservation::Reservation(Reservation &res) {
	if (this->rows != NULL)
		delete[] this->rows;
	if (this->cols != NULL)
		delete[] this->cols;

	this->size = res.getPassengers();
	this->id = res.getID();
	this->rows = new int[this->size];
	this->cols = new char[this->size];

	for (int i = 0; i < size; i++) {
		rows[i] = (res.getRows())[i];
		cols[i] = (res.getCols())[i];
	}

	this->flight = res.getFlight();
}*/

Reservation::~Reservation(){
	delete[] rows;
	delete[] cols;
}

/*void Reservation::operator=(Reservation &res) {
	if (this->rows != NULL)
		delete[] this->rows;
	if (this->cols != NULL)
		delete[] this->cols;

	this->size = res.getPassengers();
	this->id = res.getID();
	this->rows = new int[this->size];
	this->cols = new char[this->size];

	for (int i = 0; i < size; i++) {
		rows[i] = (res.getRows())[i];
		cols[i] = (res.getCols())[i];
	}
	this->flight = res.getFlight();
}*/

void Reservation::showReservation() {
	cout << "ResId: " << this->id << " Size: " << this->size << " FlightNo: " << this->flight << endl;
	cout << "Reserved Seats: " << endl;
	for (int i = 0; i < this->size; i++)
		cout << " " << rows[i] << "-" << cols[i] << " ";
	cout << endl;
}

int Reservation::getPassengers() {
	return this->size;
}

int* Reservation::getRows() {
	return this->rows;
}

char* Reservation::getCols() {
	return this->cols;
}

int Reservation::getID() {
	return this->id;
}

int Reservation::getFlight() {
	return this->flight;
}