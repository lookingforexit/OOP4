#ifndef POLYGON_H
#define POLYGON_H

#include "Figure.h"
#include <vector>
#include <memory>

template <Scalar T>
class Polygon : public Figure<T> {
protected:
    std::vector<std::unique_ptr<Point<T>>> vertices_;
protected:
    explicit Polygon(size_t amountOfVertices);
    Polygon(const std::initializer_list<Point<T>>& rhs);
protected:
    Polygon(Polygon&& rhs) noexcept = default;
    Polygon& operator=(Polygon&& rhs) noexcept = default;
public:
    ~Polygon() noexcept override = default;
public:
    Point<T> calcGeometricCenter() const override;
public:
    explicit operator double() const override;
public:
    template <Scalar U>
    friend std::istream& operator>>(std::istream& istream, Polygon<U>& rhs);
    template <Scalar U>
    friend std::ostream& operator<<(std::ostream& ostream, const Polygon<U>& rhs);
};

template <Scalar T>
Polygon<T>::Polygon(size_t amountOfVertices) : vertices_(amountOfVertices)
{
    for (auto& vert : vertices_)
    {
        vert = std::make_unique<Point<T>>();
    }
}

template <Scalar T>
Polygon<T>::Polygon(const std::initializer_list<Point<T>>& rhs) : vertices_(rhs.size())
{
    size_t i = 0;
    for (const auto& point : rhs)
    {
        vertices_[i++] = std::make_unique<Point<T>>(point.x, point.y);
    }
}

template <Scalar T>
Point<T> Polygon<T>::calcGeometricCenter() const
{
    if (vertices_.empty())
    {
        return Point<T>();
    }

    T xResult = 0;
    T yResult = 0;
    for (size_t i = 0; i < vertices_.size(); ++i)
    {
        xResult += vertices_[i]->x;
        yResult += vertices_[i]->y;
    }

    return Point<T>(xResult / static_cast<T>(vertices_.size()), yResult / static_cast<T>(vertices_.size()));
}

template <Scalar T>
Polygon<T>::operator double() const
{
    if (vertices_.empty())
    {
        return 0;
    }

    double area = 0;
    for (size_t i = 0; i < vertices_.size(); ++i)
    {
        size_t j = (i + 1) % vertices_.size();
        area += vertices_[i]->x * vertices_[j]->y;
        area -= vertices_[j]->x * vertices_[i]->y;
    }

    return std::abs(area) / 2;
}

template <Scalar T>
std::istream& operator>>(std::istream& istream, Polygon<T>& rhs)
{
    for (size_t i = 0; i < rhs.vertices_.size(); ++i)
    {
        if (!(istream >> *rhs.vertices_[i]))
        {
            throw std::invalid_argument("invalid point");
        }
    }

    return istream;
}

template <Scalar T>
std::ostream& operator<<(std::ostream& ostream, const Polygon<T>& rhs)
{
    if (rhs.vertices_.empty())
    {
        return ostream << "empty";
    }

    for (size_t i = 0; i < rhs.vertices_.size() - 1; ++i)
    {
        ostream << *rhs.vertices_[i] << ' ';
    }
    ostream << *rhs.vertices_[rhs.vertices_.size() - 1];

    return ostream;
}

#endif //POLYGON_H