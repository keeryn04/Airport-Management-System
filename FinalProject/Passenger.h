#ifndef OUR_PASSENGER
#define OUR_PASSENGER

#include <string>

class Our_Passenger {
    public:
        Our_Passenger();
        
        void setfName(const std::string& firstName);
        std::string getfName() const;

        void setlName(const std::string& firstName);
        std::string getlName() const;

        void setPhoneNumber(const std::string& phoneNumber);
        std::string getPhoneNumber() const;

        void set_id(int id);
        int get_id() const;

        Our_Passenger& operator=(const Our_Passenger& rhs) {
            if (this != &rhs) {  
                fname = rhs.fname;
                lname = rhs.lname;
                phoneNumber = rhs.phoneNumber;
                id = rhs.id;
            }
            return *this;
        }

    private:
      std::string fname;
      std::string lname;
      std::string phoneNumber;
      int id;
};

Our_Passenger::Our_Passenger() {
    id = 0;
    phoneNumber = "911";
    fname = "John";
    lname = "Smith";
}

//Setters
void Our_Passenger::setfName(const std::string& firstName) {
    this->fname = fname;
}

void Our_Passenger::setlName(const std::string& lastName) {
    this->lname = lname;
}

void Our_Passenger::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Our_Passenger::set_id(int id) {
    this->id = id;
}


//Getters
std::string Our_Passenger::getfName()  const {
    return fname;
}

std::string Our_Passenger::getlName()  const {
    return lname;
}

std::string Our_Passenger::getPhoneNumber() const {
    return phoneNumber;
}

int Our_Passenger::get_id() const {
    return id;
}

#endif