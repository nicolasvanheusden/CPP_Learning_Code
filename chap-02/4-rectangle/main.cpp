#include "Rectangle.h"

#include <iostream>

int main() {
    Rectangle rect(2.f, 4.f);
    std::cout << "{ L: " << rect.get_length() << ", W: " << rect.get_width() << " }" << std::endl;

    rect.scale(3);
    std::cout << "{ L: " << rect.get_length() << ", W: " << rect.get_width() << " }" << std::endl;

    Rectangle::set_default_size(3.f);
    Rectangle s1;
    Rectangle s2;

    /* some instruction saying that next squares's size will now be 5.f */
    Rectangle::set_default_size(5.f);
    Rectangle s3;
    Rectangle s4;
    Rectangle s5;
    return 0;
}
