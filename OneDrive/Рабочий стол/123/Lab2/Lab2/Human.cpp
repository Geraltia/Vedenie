#include "Human.h"

Human::Human(nlohmann::json jHuman)
{
	name = jHuman["name"].get<std::string>();
	age = jHuman["age"].get<int>();
	gender = jHuman["gender"].get<std::string>();
	weight = jHuman["weight"].get<int>();
	height = jHuman["height"].get<int>();
	isWorking = jHuman["isWorking"].get<bool>();


}
std::ostream& operator<<(std::ostream& os, const Human& human)
{
    os << "Name: " << human.name << std::endl;
    os << "Age: " << human.age << std::endl;
    os << "Gender: " << human.gender << std::endl;
    os << "Weight: " << human.weight << std::endl;
    os << "Height: " << human.height << std::endl;
    os << "Is working: " << (human.isWorking ? "Yes" : "No") << std::endl;
    return os;
}

