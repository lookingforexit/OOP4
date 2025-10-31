#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <Polygon.h>

template <Scalar T>
class Rectangle : public Polygon<T> {
private:
    constexpr static size_t amountOfVertices_ = 4;
public:
    Rectangle();
    Rectangle(const std::initializer_list<Point<T>>& points);
public:
    Rectangle(Rectangle&&) noexcept = default;
    Rectangle& operator=(Rectangle&&) noexcept = default;
public:
    ~Rectangle() noexcept override = default;
};

template <Scalar T>
Rectangle<T>::Rectangle() : Polygon<T>(amountOfVertices_) {}

template <Scalar T>
Rectangle<T>::Rectangle(const std::initializer_list<Point<T>>& points) : Polygon<T>(points)
{
    if (points.size() != amountOfVertices_)
    {
        throw std::invalid_argument("invalid amount of points");
    }
}

#endif //RECTANGLE_H