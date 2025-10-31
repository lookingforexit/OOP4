#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

template <Scalar T>
class Square final : public Rectangle<T> {
public:
    Square() = default;
    explicit Square(std::vector<std::unique_ptr<Point<T>>>&&);
public:
    Square(Square&&) = default;
    Square& operator=(Square&&) = default;
public:
    ~Square() override = default;
};

template <Scalar T>
Square<T>::Square(std::vector<std::unique_ptr<Point<T>>>&& points) : Polygon<T>(std::move(points)) {}

#endif //SQUARE_H