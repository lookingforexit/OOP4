#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Polygon.h"

template <Scalar T>
class Trapezoid final: public Polygon<T> {
private:
    constexpr static size_t amountOfVertices_ = 4;
public:
    Trapezoid();
    Trapezoid(const std::initializer_list<Point<T>>& points);
public:
    Trapezoid(Trapezoid&&) noexcept = default;
    Trapezoid& operator=(Trapezoid&&) noexcept = default;
public:
    ~Trapezoid() noexcept override = default;
};

template <Scalar T>
Trapezoid<T>::Trapezoid() : Polygon<T>(amountOfVertices_) {}

template <Scalar T>
Trapezoid<T>::Trapezoid(const std::initializer_list<Point<T>>& points) : Polygon<T>(points)
{
    if (points.size() != amountOfVertices_)
    {
        throw std::invalid_argument("invalid amount of points");
    }
}

#endif //TRAPEZOID_H