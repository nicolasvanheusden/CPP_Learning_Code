
#include "Cat.h"

#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<Cat> cat = std::make_unique<Cat>("Felix");

    std::cout << *cat << std::endl;

    std::unique_ptr<Cat> cat2;

    if (cat2 == nullptr) {
        std::cout << "nullll" << std::endl;
    }

    cat2 = std::make_unique<Cat>("Le chat");
    std::cout << *cat2 << std::endl;

    if (*cat == *cat2) {
        std::cout << "same object" << std::endl;
    }
    if (cat == cat2) {
        std::cout << "same reference" << std::endl;
    }

    cat.reset();

    if (cat == nullptr) {
        std::cout << "nullll" << std::endl;
    }

    return 0;
}