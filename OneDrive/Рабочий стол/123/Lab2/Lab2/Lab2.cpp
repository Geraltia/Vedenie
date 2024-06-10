#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

class User {
public:
    std::string name;
    int age;
    std::string email;
    struct Address {
        std::string street;
        std::string city;
        std::string state;
        std::string zip;
    } address;
    struct PhoneNumber {
        std::string type;
        std::string number;
    };
    std::vector<PhoneNumber> phoneNumbers;

    void printDetails() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << "Address: " << address.street << ", " << address.city << ", " << address.state << " " << address.zip << std::endl;
        std::cout << "Phone Numbers:" << std::endl;
        for (const auto& phoneNumber : phoneNumbers) {
            std::cout << "    Type: " << phoneNumber.type << ", Number: " << phoneNumber.number << std::endl;
        }
    }
};

int main() {
   
    std::ifstream file("MyJson.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file for reading." << std::endl;
        return 1;
    }

    json jsonData = json::parse(file);
    file.close();

   
    User user;
    user.name = jsonData["name"];
    user.age = jsonData["age"];
    user.email = jsonData["email"];
    user.address.street = jsonData["address"]["street"];
    user.address.city = jsonData["address"]["city"];
    user.address.state = jsonData["address"]["state"];
    user.address.zip = jsonData["address"]["zip"];
    for (const auto& phoneNumber : jsonData["phoneNumbers"]) {
        User::PhoneNumber phone;
        phone.type = phoneNumber["type"];
        phone.number = phoneNumber["number"];
        user.phoneNumbers.push_back(phone);
    }

    
    user.printDetails();

    return 0;
}
