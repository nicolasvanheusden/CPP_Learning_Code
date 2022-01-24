#include <iostream>

class Person {

public:
    void               set_name(const std::string& name) { _name = name; }
    void               set_age(int age) { _age = age; }
    unsigned int       get_age() const { return _age; }
    const std::string& get_name() const { return _name; }

private:
    std::string _name;
    int         _age = 0u;
};

int main() {
    Person p;

    p.set_name("Batman");
    p.set_age(23);

    std::cout << "Person named '" << p.get_name() << "' is " << p.get_age() << " years old." << std::endl;

    return 0;
}
