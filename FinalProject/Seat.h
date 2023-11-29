#ifndef OUR_SEAT
#define OUR_SEAT

class Our_Seat {
    public:
        Our_Seat();

        void set_row(int row);
        int get_row() const;

        void set_col(char col);
        char get_col() const;

        void set_status(char status);
        char get_status() const;

    private:
        int row;
        char seat;
        char status;
};

//Default Constructor
Our_Seat::Our_Seat() {
    row = 1;
    seat = 'A'; 
}

//Setters
void Our_Seat::set_row(int row) {
    this->row = row;
}

void Our_Seat::set_col(char col) {
    this->seat = col;
}

void Our_Seat::set_status(char status) {
    this->status = status;
}

//Getters
int Our_Seat::get_row() const {
    return row;
}

char Our_Seat::get_col() const {
    return seat;
}

char Our_Seat::get_status() const {
    return status;
}

#endif