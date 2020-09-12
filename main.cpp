#include <iostream>

#include "var.hpp"

int main() {
    using namespace markusjx;
    var v = undefined;
    try {
        std::cout << v << std::endl;

        var v1 = [] (int i) {
            return i;
        };

        std::cout << v1(1) << std::endl;
    } catch (markusjx::exception &e) {
        std::cerr << "Exception thrown: " << e.getType() << ": " << e.what() << std::endl;
    }
}

