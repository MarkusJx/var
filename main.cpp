#include <iostream>

#include "var.hpp"

int main() {
    using namespace markusjx;
    var v = nullptr;
    try {
        v = nullptr;
        std::cout << v << std::endl;

        v = "abc";
        std::cout << v << std::endl;

        v = v + 5;

        std::cout << v << std::endl;

        v = [](var i) {
            std::cout << i << std::endl;
            return i;
        };

        std::cout << v(5) << std::endl;

        var fn = [](int i) {
            return i;
        };

        v = object({{"a", "b"},
                    {"b", "d"},
                    {"e", [](int i) {
                        return i;
                    }}});

        for (const auto& p: v.asObject()) {
            std::cout << p.first << ", " << p.second << std::endl;
        }

        // TODO: Fix this search
        std::cout << v["b"] << ", " << v["e"](25) << std::endl;

        v = array({0, 1, 2, v});

        std::cout << v << std::endl;

        for (const var& v : v.asArray()) {
            std::cout << v << std::endl;
        }

        std::cout << v[3]["a"] << std::endl;
    } catch (markusjx::exception &e) {
        std::cerr << "Exception thrown: " << e.getType() << ": " << e.what() << std::endl;
    }
}

