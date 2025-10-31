#include "Trapezoid.h"
#include "Square.h"
#include <iostream>

int main()
{
    Trapezoid<int> trap({{5, 0}, {4, 3}, {1, 3}, {0, 1}});

    std::cout << "Trapezoid: " << trap << std::endl;
    std::cout << "Center: " << trap.calcGeometricCenter() << std::endl;
    std::cout << "Area: " << static_cast<double>(trap) << std::endl;

    Trapezoid<int> copy(std::move(trap));
    std::cout << copy;
    std::cout << trap;

    Trapezoid<double> io;
    std::cin >> io;
    std::cout << io;

    return 0;
}
