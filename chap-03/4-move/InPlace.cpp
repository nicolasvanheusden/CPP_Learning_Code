#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

struct Test {
    Test(int v)
        : value { v } {
        std::cout << "Constructor was called with " << v << "." << std::endl;
    }

    Test(const Test& other)
        : value { other.value } {
        std::cout << "Copy constructor was called." << std::endl;
    }

    int value = 0;
};

Test create_test(int value) {
    Test result { value };
    return result;
}

int main() {
    Test test = create_test(3);
    std::cout << test.value << std::endl;

    std::vector<std::unique_ptr<std::string>> many_strings;

    auto value = std::make_unique<std::string>("lalala");

    if (value != nullptr) {
        std::cout << "Value is " << *value << std::endl;
    } else {
        std::cout << "Value is empty" << std::endl;
    }

    many_strings.emplace_back(std::move(value));

    if (many_strings[0] != nullptr) {
        std::cout << "Value is " << *many_strings[0] << std::endl;
    } else {
        std::cout << "many strings[0] is empty" << std::endl;
    }

    return 0;
}