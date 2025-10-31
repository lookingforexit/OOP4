#include "Trapezoid.h"
#include "Square.h"
#include <iostream>

template <Scalar T>
std::vector<std::unique_ptr<Point<T>>> makePoints(std::initializer_list<std::pair<T, T>> coords)
{
    std::vector<std::unique_ptr<Point<T>>> pts;
    for (const auto& [x, y] : coords) {
        pts.push_back(std::make_unique<Point<T>>(x, y));
    }

    return pts;
}

int main() {

    Trapezoid trap(makePoints<double>({{0, 0}, {5, 0}, {4, 3}, {1, 3}}));

    std::cout << "Trapezoid: " << trap << std::endl;
    std::cout << "Center: " << trap.calcGeometricCenter() << std::endl;
    std::cout << "Area: " << static_cast<double>(trap) << std::endl;

    Trapezoid<double> copy(std::move(trap));

    std::cout << copy << std::endl;

    return 0;
}
