#ifndef OUR_FLIGHT
#define OUR_FLIGHT

#include <vector>
#include <string>

class Our_Flight {
    public:
        Our_Flight();

        void set_flight_id(std::string flight_id);
        std::string get_flight_id() const;
        
        void set_numRows(int num);
        int get_numRows() const;

        void set_numSeats(int num);
        int get_numSeats() const;

        void set_numPass(int num);
        int get_numPass() const;

        void set_Seat_in_map(const Our_Seat& seatInfo);
        Our_Seat get_Seat_in_map(int row, char col) const;

        void set_Passenger(const Our_Passenger& passengerInfo, size_t passNum);
        Our_Passenger get_Passenger(size_t index) const;

        vector<vector<Our_Seat>> get_Seatmap() const;

        void removePassenger(size_t pass_index);

    private:
        vector<vector<Our_Seat>> Seatmap;
        vector<Our_Passenger> Passengers;
        string flight_id;
        int numRows;
        int numSeats;
        int numPass;
};

#endif