#include <iostream>

#include "var.hpp"

int main() {
    using namespace markusjx;
    var v = undefined;
    try {
        std::cout << v << std::endl;

        var fn = []() {
            std::cout << "abc: " << 5 << std::endl;
        };

        fn();

        std::cout << v << std::endl;
    } catch (markusjx::exception &e) {
        std::cerr << "Exception thrown: " << e.getType() << ": " << e.what() << std::endl;
    }
}

