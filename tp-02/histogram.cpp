
#include "histogram.h"

void Histogram::print() const {
    for (int value : this->_count) {
        std::cout << value << std::endl;
    }
}

int main(void) {

    Histogram h1, h2;
    Histogram h3 { Histogram { h1 } };

    h1.print();
}