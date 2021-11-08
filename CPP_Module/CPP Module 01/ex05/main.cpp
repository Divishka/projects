#include "Karen.hpp"

int main() {
    Karen karen;

    // TRUE tests
    karen.complain("info");
    karen.complain("info");
    karen.complain("debug");
    karen.complain("warning");
    karen.complain("error");
    karen.complain("error");
    karen.complain("info");

    // FALSE tests
    karen.complain("inf");
    karen.complain("");
    karen.complain("EROROOROR");
    return (0);
}