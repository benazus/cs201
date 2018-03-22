#include "ReservationSystem.h"
#include <iostream>
using namespace std;

int main() {
	ReservationSystem rs;
	rs.addFlight(123, 6, 6);
	rs.addFlight(451, 7, 7);
	rs.addFlight(658, 9, 9);
	rs.addFlight(989, 9, 9);
	
	rs.showAllFlights();

	int* x = new int[4];
	x[0] = 0;
	x[1] = 1; 
	x[2] = 2;
	x[3] = 3;

	char* y = new char[4];
	y[0] = 'a';
	y[1] = 'b';
	y[2] = 'c';
	y[3] = 'd';
	int a = rs.makeReservation(123, 4, x, y);
	
	int b = rs.makeReservation(451, 4, x, y);

	int c = rs.makeReservation(658, 4, x, y);

	rs.showReservation(a);
	rs.showReservation(b);
	rs.showReservation(c);

	rs.cancelReservation(a);
	rs.cancelReservation(b);
	rs.cancelReservation(c);
	delete[] x;
	delete[] y;
	int q;
	std::cin >> q;
}