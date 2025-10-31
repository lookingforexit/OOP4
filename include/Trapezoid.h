#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Polygon.h"

template <Scalar T>
class Trapezoid final: public Polygon<T> {
public:
    Trapezoid() = default;
    explicit Trapezoid(std::vector<std::unique_ptr<Point<T>>>&& points) noexcept;
public:
    Trapezoid(Trapezoid&&) noexcept = default;
    Trapezoid& operator=(Trapezoid&&) noexcept = default;
public:
    ~Trapezoid() noexcept override = default;
};

template <Scalar T>
Trapezoid<T>::Trapezoid(std::vector<std::unique_ptr<Point<T>>>&& points) noexcept : Polygon<T>(std::move(points)) {}

#endif //TRAPEZOID_H