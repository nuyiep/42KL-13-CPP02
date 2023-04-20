
#include <iostream>

class Person {
public:
    std::string name;
    int age;

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << "Name: " << person.name << ", Age: " << person.age;
        return os;
    }
};

int main(void)
{
	Person john;
	john.name = "John";
	john.age = 30;

	std::cout << john << std::endl;

}
