#ifndef OUR_PASSENGER
#define OUR_PASSENGER

#include <string>
#include "Seat.h"

class Our_Passenger {
    public:
        Our_Passenger();
        ~Our_Passenger();
        Our_Passenger(const Our_Passenger& other);
        Our_Passenger& operator=(const Our_Passenger& other);
        
        void setfName(const std::string& firstName);
        std::string getfName() const;

        void setlName(const std::string& firstName);
        std::string getlName() const;

        void setPhoneNumber(const std::string& phoneNumber);
        std::string getPhoneNumber() const;

        void set_id(int id);
        int get_id() const;

        void set_Seat(int seatRow, char seatColumn, char status, int numRows, int numSeats);
        Our_Seat* get_Seat() const;

    private:
      Our_Seat* seat;
      std::string fname;
      std::string lname;
      std::string phoneNumber;
      int id;
};

#endif