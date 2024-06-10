#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "json.hpp"
using namespace std;

class Human
{
private:
    string name;
    int age = 21;
    string gender;
    int weight;
    int height;
    bool isWorking;

public:
    Human(string name, int age, string gender, int weight, int heightm, bool isWorking);
    Human(nlohmann::json);
    inline std::string getName() { return name; }
    inline int	getAge() { return age; }
    inline std::string getGender() { return gender; }
    inline int getWeight() { return weight; }
    inline int getHeight() { return height; }
    inline bool getIsWorking() { return isWorking; }
    nlohmann::json getJsonObj();
    friend std::ostream& operator<<(std::ostream& os, const Human& human);


};

