#ifndef POINT_H
#define POINT_H

#include <iostream>

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>
class Point {
public:
    T x;
    T y;
public:
    Point() = default;
    Point(T x, T y);
public:
    virtual ~Point() noexcept = default;
public:
    template <Scalar U>
    friend std::istream& operator>>(std::istream& istream, Point<U>& point);

    template <Scalar U>
    friend std::ostream& operator<<(std::ostream& ostream, const Point<U>& point);
};

template <Scalar T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template <Scalar T>
std::istream& operator>>(std::istream& istream, Point<T>& point)
{
    if (!(istream >> point.x) || !(istream >> point.y))
    {
        throw std::invalid_argument("incorrect type provided");
    }
    return istream;
}

template <Scalar T>
std::ostream& operator<<(std::ostream& ostream, const Point<T>& point)
{
    return ostream << '(' << point.x << ", " << point.y << ')';
}

#endif //POINT_H