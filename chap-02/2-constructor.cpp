#include <iostream>
#include <string>

class Person {
public:
    Person(const std::string& name, const std::string& surname, unsigned int age)
        : _name { name }
        , _surname { _surname }
        , _age { age } {
        std::cout << "Person named '" << _name << "' is " << _age << " years old." << std::endl;
    }
    const std::string& get_full_name() const { return _surname + " " + _name; }
    unsigned int       get_age() const { return _age; }

    void wait(unsigned int years) { _age += years; }

private:
    const std::string _name;
    const std::string _surname;
    unsigned int      _age = 0u;
};

int main() {
    Person p { "Bruce", "Wayne", 23 };

    return 0;
}
