#include <iostream>

#include "var.hpp"

int main() {
    markusjx::var v = "abc";
    try {
        std::cout << v << std::endl;
        v = "5";
        v = v / 2;
        std::cout << v << ", " << v->getTypeAsString() << std::endl;
        std::cout << v + true << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception thrown: " << e.what() << std::endl;
    }
}

