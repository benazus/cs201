#pragma once // remember to delete

/*
Berat Biçer
Sec.2
21503050
25.11.2016
*/

class Flight {
public:
	Flight(const int flightNo, const int row_size, const int column_size);
	Flight();
	//Flight(Flight &flight); // Copy Constructor
	~Flight();
	void getSeatingPlan();
	//void operator=(Flight &flight);
	int getAvailableSeatCount();

	int getFlightNo();
	int getRowSize();
	int getColumnSize();
	char** getAircraft();
	void setSeatingPlan(const int numPassengers, const int *seatRow, const char *seatCol);
	void resetSeatingPlan(const int numPassengers, const int *seatRow, const char *seatCol);

private:
	int flightNo; // Flight ID for e specific flight
	int row_size; // Row count of the aircraft
	int column_size; // Column count for the aircraft
	char** aircraft; // Double char array for the seating plan of the aircraft
};