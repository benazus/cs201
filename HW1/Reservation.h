#pragma once
/*
Berat Biçer
Sec.2
21503050
25.11.2016
*/

class Reservation {
public:
	Reservation(const int numPassengers, const int* seatRow, const char* seatCol, const int id, const int flight);
	Reservation();
	//Reservation(Reservation &res);
	~Reservation();
	//void operator=(Reservation &res);

	int getPassengers();
	int getID();
	int* getRows();
	char* getCols();
	int getFlight();
	void showReservation();

private:
	int* rows;
	char* cols;
	int size;
	int id;
	int flight;
};
