#ifndef FIGURE_H
#define FIGURE_H

#include "Point.h"

template <Scalar T>
class Figure {
protected:
    Figure() = default;
protected:
    Figure(const Figure&) = default;
    Figure& operator=(const Figure&) = default;
protected:
    Figure(Figure&&) noexcept = default;
    Figure& operator=(Figure&&) noexcept = default;
public:
    virtual ~Figure() noexcept = default;
public:
    virtual Point<T> calcGeometricCenter() const = 0;
public:
    virtual explicit operator double() const = 0;
};

#endif //FIGURE_H