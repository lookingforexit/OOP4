#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <Polygon.h>

template <Scalar T>
class Rectangle : public Polygon<T> {
public:
    Rectangle() = default;
    explicit Rectangle(std::vector<std::unique_ptr<Point<T>>>&& points) noexcept;
public:
    Rectangle(Rectangle&&) = default;
    Rectangle& operator=(Rectangle&&) noexcept = default;
public:
    ~Rectangle() noexcept override = default;
};

template <Scalar T>
Rectangle<T>::Rectangle(std::vector<std::unique_ptr<Point<T>>>&& points) noexcept : Polygon<T>(std::move(points)) {}

#endif //RECTANGLE_H