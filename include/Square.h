#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

template <Scalar T>
class Square final : public Rectangle<T> {
public:
    Square();
    Square(const std::initializer_list<Point<T>>& points);
public:
    Square(Square&&) = default;
    Square& operator=(Square&&) = default;
public:
    ~Square() override = default;
};

template <Scalar T>
Square<T>::Square() : Rectangle<T>() {}

template <Scalar T>
Square<T>::Square(const std::initializer_list<Point<T>>& points) : Rectangle<T>(points) {}

#endif //SQUARE_H