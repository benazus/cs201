/*
Berat Biçer
Sec.2
21503050
25.11.2016
*/

#include "Flight.h"
#include "Reservation.h"
class ReservationSystem {
	public:
		ReservationSystem();
		~ReservationSystem();
		void addFlight(const int flightNo, const int rowNo, const int seatNo);
		void cancelFlight(const int flightNo);
		void showAllFlights();
		void showFlight(const int flightNo);
		int makeReservation(const int flightNo, const int numPassengers,
			const int *seatRow, const char *seatCol);
		void cancelReservation(const int resCode);
		void showReservation(const int resCode);

	private:
		int system_size; // Size of flightSystem
		Flight** flightSystem; // A double Flight pointer which points to an array of Flight objects
		
		Reservation** resSystem;
		int res_size;
		int base;
};