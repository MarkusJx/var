#include <iostream>

#include "var.hpp"

int main() {
    using namespace markusjx;
    var v = nullptr;
    try {
        v = nullptr;
        std::cout << v << std::endl;

        var fn = [](int i) {
            std::cout << i << std::endl;
        };

        v = array({"a", "b"});

        // TODO: Fix this search
        std::cout << v[1] << std::endl;
    } catch (markusjx::exception &e) {
        std::cerr << "Exception thrown: " << e.getType() << ": " << e.what() << std::endl;
    }
}

