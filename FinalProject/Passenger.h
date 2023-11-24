#ifndef OUR_PASSENGER
#define OUR_PASSENGER

#include <string>

class Our_Passenger {
    public:
      void setName(const std::string& firstName);
      std::string getName() const;

      void setPhoneNumber(const std::string& phoneNumber);
      std::string getPhoneNumber() const;

      void set_id(int id);
      int get_id() const;
    private:
      std::string name;
      std::string phoneNumber;
      int id;
};

//Setters
void Our_Passenger::setName(const std::string& firstName) {
    this->name = name;
}

void Our_Passenger::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Our_Passenger::set_id(int id) {
    this->id = id;
}


//Getters
std::string Our_Passenger::getName()  const {
    return name;
}

std::string Our_Passenger::getPhoneNumber() const {
    return phoneNumber;
}

int Our_Passenger::get_id() const {
    return id;
}

#endif