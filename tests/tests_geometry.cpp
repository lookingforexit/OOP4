#include <gtest/gtest.h>
#include <sstream>
#include <memory>
#include "Point.h"
#include "Figure.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Square.h"
#include "Trapezoid.h"

// ==================== Point Tests ====================

class PointTest : public ::testing::Test {
protected:
    using PointInt = Point<int>;
    using PointDouble = Point<double>;
};

TEST_F(PointTest, DefaultConstructor) {
    PointInt p;
    EXPECT_EQ(p.x, 0);
    EXPECT_EQ(p.y, 0);
}

TEST_F(PointTest, ParametrizedConstructor) {
    PointInt p(5, 10);
    EXPECT_EQ(p.x, 5);
    EXPECT_EQ(p.y, 10);
}

TEST_F(PointTest, ParametrizedConstructorDouble) {
    PointDouble p(3.5, 7.2);
    EXPECT_DOUBLE_EQ(p.x, 3.5);
    EXPECT_DOUBLE_EQ(p.y, 7.2);
}

TEST_F(PointTest, OutputOperator) {
    PointInt p(3, 4);
    std::ostringstream oss;
    oss << p;
    EXPECT_EQ(oss.str(), "(3, 4)");
}

TEST_F(PointTest, OutputOperatorDouble) {
    PointDouble p(1.5, 2.5);
    std::ostringstream oss;
    oss << p;
    EXPECT_EQ(oss.str(), "(1.5, 2.5)");
}

TEST_F(PointTest, InputOperator) {
    PointInt p;
    std::istringstream iss("10 20");
    iss >> p;
    EXPECT_EQ(p.x, 10);
    EXPECT_EQ(p.y, 20);
}

TEST_F(PointTest, InputOperatorDouble) {
    PointDouble p;
    std::istringstream iss("3.14 2.71");
    iss >> p;
    EXPECT_DOUBLE_EQ(p.x, 3.14);
    EXPECT_DOUBLE_EQ(p.y, 2.71);
}

TEST_F(PointTest, InputOperatorInvalidType) {
    PointInt p;
    std::istringstream iss("invalid data");
    EXPECT_THROW(iss >> p, std::invalid_argument);
}

TEST_F(PointTest, InputOperatorPartialData) {
    PointInt p;
    std::istringstream iss("10");
    EXPECT_THROW(iss >> p, std::invalid_argument);
}

TEST_F(PointTest, NegativeCoordinates) {
    PointInt p(-5, -10);
    EXPECT_EQ(p.x, -5);
    EXPECT_EQ(p.y, -10);
}

TEST_F(PointTest, ZeroCoordinates) {
    PointInt p(0, 0);
    EXPECT_EQ(p.x, 0);
    EXPECT_EQ(p.y, 0);
}

TEST_F(PointTest, LargeCoordinates) {
    PointInt p(1000000, 2000000);
    EXPECT_EQ(p.x, 1000000);
    EXPECT_EQ(p.y, 2000000);
}

// ==================== Rectangle Tests ====================

class RectangleTest : public ::testing::Test {
protected:
    using RectangleInt = Rectangle<int>;
    using RectangleDouble = Rectangle<double>;
};

TEST_F(RectangleTest, DefaultConstructor) {
    RectangleInt rect;
    EXPECT_NO_THROW(rect.calcGeometricCenter());
}

TEST_F(RectangleTest, ConstructorWithFourPoints) {
    RectangleInt rect({{0, 0}, {10, 0}, {10, 5}, {0, 5}});
    double area = static_cast<double>(rect);
    EXPECT_DOUBLE_EQ(area, 50.0);
}

TEST_F(RectangleTest, ConstructorWithInvalidPointCount) {
    EXPECT_THROW(RectangleInt({{0, 0}, {1, 1}, {2, 2}}), std::invalid_argument);
}

TEST_F(RectangleTest, ConstructorWithMoreThanFourPoints) {
    EXPECT_THROW(RectangleInt({{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}}),
                 std::invalid_argument);
}

TEST_F(RectangleTest, AreaCalculation) {
    RectangleInt rect({{0, 0}, {5, 0}, {5, 3}, {0, 3}});
    double area = static_cast<double>(rect);
    EXPECT_DOUBLE_EQ(area, 15.0);
}

TEST_F(RectangleTest, GeometricCenter) {
    RectangleInt rect({{0, 0}, {8, 0}, {8, 4}, {0, 4}});
    auto center = rect.calcGeometricCenter();
    EXPECT_EQ(center.x, 4);
    EXPECT_EQ(center.y, 2);
}

TEST_F(RectangleTest, MoveConstructor) {
    RectangleInt rect1({{0, 0}, {5, 0}, {5, 5}, {0, 5}});
    RectangleInt rect2(std::move(rect1));
    double area = static_cast<double>(rect2);
    EXPECT_DOUBLE_EQ(area, 25.0);
}

TEST_F(RectangleTest, MoveAssignment) {
    RectangleInt rect1({{0, 0}, {5, 0}, {5, 5}, {0, 5}});
    RectangleInt rect2;
    rect2 = std::move(rect1);
    double area = static_cast<double>(rect2);
    EXPECT_DOUBLE_EQ(area, 25.0);
}

TEST_F(RectangleTest, RectangleWithNegativeCoordinates) {
    RectangleInt rect({{-5, -5}, {5, -5}, {5, 5}, {-5, 5}});
    double area = static_cast<double>(rect);
    EXPECT_DOUBLE_EQ(area, 100.0);
}

TEST_F(RectangleTest, RectangleWithDoubleCoordinates) {
    RectangleDouble rect({{0.0, 0.0}, {2.5, 0.0}, {2.5, 4.0}, {0.0, 4.0}});
    double area = static_cast<double>(rect);
    EXPECT_NEAR(area, 10.0, 0.0001);
}

// ==================== Square Tests ====================

class SquareTest : public ::testing::Test {
protected:
    using SquareInt = Square<int>;
    using SquareDouble = Square<double>;
};

TEST_F(SquareTest, DefaultConstructor) {
    SquareInt square;
    EXPECT_NO_THROW(square.calcGeometricCenter());
}

TEST_F(SquareTest, ConstructorWithFourPoints) {
    SquareInt square({{0, 0}, {5, 0}, {5, 5}, {0, 5}});
    double area = static_cast<double>(square);
    EXPECT_DOUBLE_EQ(area, 25.0);
}

TEST_F(SquareTest, AreaCalculation) {
    SquareInt square({{0, 0}, {10, 0}, {10, 10}, {0, 10}});
    double area = static_cast<double>(square);
    EXPECT_DOUBLE_EQ(area, 100.0);
}

TEST_F(SquareTest, GeometricCenter) {
    SquareInt square({{0, 0}, {4, 0}, {4, 4}, {0, 4}});
    auto center = square.calcGeometricCenter();
    EXPECT_EQ(center.x, 2);
    EXPECT_EQ(center.y, 2);
}

TEST_F(SquareTest, MoveConstructor) {
    SquareInt square1({{0, 0}, {3, 0}, {3, 3}, {0, 3}});
    SquareInt square2(std::move(square1));
    double area = static_cast<double>(square2);
    EXPECT_DOUBLE_EQ(area, 9.0);
}

TEST_F(SquareTest, MoveAssignment) {
    SquareInt square1({{0, 0}, {7, 0}, {7, 7}, {0, 7}});
    SquareInt square2;
    square2 = std::move(square1);
    double area = static_cast<double>(square2);
    EXPECT_DOUBLE_EQ(area, 49.0);
}

TEST_F(SquareTest, ConstructorWithInvalidPointCount) {
    EXPECT_THROW(SquareInt({{0, 0}, {1, 1}}), std::invalid_argument);
}

TEST_F(SquareTest, SquareWithNegativeCoordinates) {
    SquareInt square({{-3, -3}, {3, -3}, {3, 3}, {-3, 3}});
    double area = static_cast<double>(square);
    EXPECT_DOUBLE_EQ(area, 36.0);
}

TEST_F(SquareTest, SquareWithDoubleCoordinates) {
    SquareDouble square({{0.0, 0.0}, {2.5, 0.0}, {2.5, 2.5}, {0.0, 2.5}});
    double area = static_cast<double>(square);
    EXPECT_NEAR(area, 6.25, 0.0001);
}

TEST_F(SquareTest, IsFinal) {
    EXPECT_TRUE(std::is_final_v<SquareInt>);
}

// ==================== Trapezoid Tests ====================

class TrapezoidTest : public ::testing::Test {
protected:
    using TrapezoidInt = Trapezoid<int>;
    using TrapezoidDouble = Trapezoid<double>;
};

TEST_F(TrapezoidTest, DefaultConstructor) {
    TrapezoidInt trap;
    EXPECT_NO_THROW(trap.calcGeometricCenter());
}

TEST_F(TrapezoidTest, ConstructorWithFourPoints) {
    TrapezoidInt trap({{0, 0}, {4, 0}, {3, 2}, {1, 2}});
    double area = static_cast<double>(trap);
    EXPECT_GT(area, 0.0);
}

TEST_F(TrapezoidTest, AreaCalculation) {
    TrapezoidInt trap({{0, 0}, {6, 0}, {5, 3}, {1, 3}});
    double area = static_cast<double>(trap);
    EXPECT_GT(area, 0.0);
}

TEST_F(TrapezoidTest, GeometricCenter) {
    TrapezoidInt trap({{0, 0}, {4, 0}, {3, 2}, {1, 2}});
    auto center = trap.calcGeometricCenter();
    EXPECT_EQ(center.x, 2);
}

TEST_F(TrapezoidTest, MoveConstructor) {
    TrapezoidInt trap1({{0, 0}, {5, 0}, {4, 3}, {1, 3}});
    TrapezoidInt trap2(std::move(trap1));
    double area = static_cast<double>(trap2);
    EXPECT_GT(area, 0.0);
}

TEST_F(TrapezoidTest, MoveAssignment) {
    TrapezoidInt trap1({{0, 0}, {5, 0}, {4, 3}, {1, 3}});
    TrapezoidInt trap2;
    trap2 = std::move(trap1);
    double area = static_cast<double>(trap2);
    EXPECT_GT(area, 0.0);
}

TEST_F(TrapezoidTest, ConstructorWithInvalidPointCount) {
    EXPECT_THROW(TrapezoidInt({{0, 0}, {1, 1}, {2, 2}}), std::invalid_argument);
}

TEST_F(TrapezoidTest, TrapezoidWithNegativeCoordinates) {
    TrapezoidInt trap({{-3, -2}, {3, -2}, {2, 2}, {-2, 2}});
    double area = static_cast<double>(trap);
    EXPECT_GT(area, 0.0);
}

TEST_F(TrapezoidTest, TrapezoidWithDoubleCoordinates) {
    TrapezoidDouble trap({{0.0, 0.0}, {5.0, 0.0}, {4.0, 2.5}, {1.0, 2.5}});
    double area = static_cast<double>(trap);
    EXPECT_GT(area, 0.0);
}

TEST_F(TrapezoidTest, IsFinal) {
    EXPECT_TRUE(std::is_final_v<TrapezoidInt>);
}

// ==================== Polymorphism Tests ====================

class PolymorphismTest : public ::testing::Test {
protected:
    using FigureInt = Figure<int>;
    using RectangleInt = Rectangle<int>;
    using SquareInt = Square<int>;
    using TrapezoidInt = Trapezoid<int>;
};

TEST_F(PolymorphismTest, RectangleIsFigure) {
    auto rect = std::make_shared<RectangleInt>(
        std::initializer_list<Point<int>>{{0, 0}, {5, 0}, {5, 5}, {0, 5}});
    FigureInt* fig = rect.get();
    auto center = fig->calcGeometricCenter();
    EXPECT_EQ(center.x, 2);
}

TEST_F(PolymorphismTest, SquareIsFigure) {
    auto square = std::make_shared<SquareInt>(
        std::initializer_list<Point<int>>{{0, 0}, {4, 0}, {4, 4}, {0, 4}});
    FigureInt* fig = square.get();
    double area = static_cast<double>(*fig);
    EXPECT_DOUBLE_EQ(area, 16.0);
}

TEST_F(PolymorphismTest, TrapezoidIsFigure) {
    auto trap = std::make_shared<TrapezoidInt>(
        std::initializer_list<Point<int>>{{0, 0}, {4, 0}, {3, 2}, {1, 2}});
    FigureInt* fig = trap.get();
    EXPECT_NO_THROW(fig->calcGeometricCenter());
}

TEST_F(PolymorphismTest, ArrayOfShapes) {
    std::vector<std::shared_ptr<FigureInt>> figures;
    figures.push_back(std::make_shared<RectangleInt>(
        std::initializer_list<Point<int>>{{0, 0}, {5, 0}, {5, 5}, {0, 5}}));
    figures.push_back(std::make_shared<SquareInt>(
        std::initializer_list<Point<int>>{{0, 0}, {3, 0}, {3, 3}, {0, 3}}));

    double totalArea = 0.0;
    for (const auto& fig : figures) {
        totalArea += static_cast<double>(*fig);
    }
    EXPECT_GT(totalArea, 0.0);
}

TEST_F(PolymorphismTest, CalculateGeometricCentersForAllFigures) {
    std::vector<std::shared_ptr<FigureInt>> figures;
    figures.push_back(std::make_shared<RectangleInt>(
        std::initializer_list<Point<int>>{{0, 0}, {6, 0}, {6, 4}, {0, 4}}));
    figures.push_back(std::make_shared<SquareInt>(
        std::initializer_list<Point<int>>{{0, 0}, {4, 0}, {4, 4}, {0, 4}}));
    figures.push_back(std::make_shared<TrapezoidInt>(
        std::initializer_list<Point<int>>{{0, 0}, {4, 0}, {3, 2}, {1, 2}}));

    for (const auto& fig : figures) {
        auto center = fig->calcGeometricCenter();
        EXPECT_NE(center.x, INT_MIN);
        EXPECT_NE(center.y, INT_MIN);
    }
}

// ==================== Template Type Tests ====================

class TemplateTypeTest : public ::testing::Test {};

TEST_F(TemplateTypeTest, PointWithInt) {
    Point<int> p(5, 10);
    EXPECT_EQ(p.x, 5);
    EXPECT_EQ(p.y, 10);
}

TEST_F(TemplateTypeTest, PointWithDouble) {
    Point<double> p(3.14, 2.71);
    EXPECT_DOUBLE_EQ(p.x, 3.14);
    EXPECT_DOUBLE_EQ(p.y, 2.71);
}

TEST_F(TemplateTypeTest, PointWithFloat) {
    Point<float> p(1.5f, 2.5f);
    EXPECT_FLOAT_EQ(p.x, 1.5f);
    EXPECT_FLOAT_EQ(p.y, 2.5f);
}

TEST_F(TemplateTypeTest, PointWithLong) {
    Point<long> p(1000000L, 2000000L);
    EXPECT_EQ(p.x, 1000000L);
    EXPECT_EQ(p.y, 2000000L);
}

TEST_F(TemplateTypeTest, RectangleWithIntAndDouble) {
    Rectangle<int> rectInt({{0, 0}, {4, 0}, {4, 3}, {0, 3}});
    Rectangle<double> rectDouble({{0.0, 0.0}, {4.0, 0.0}, {4.0, 3.0}, {0.0, 3.0}});

    double areaInt = static_cast<double>(rectInt);
    double areaDouble = static_cast<double>(rectDouble);
    EXPECT_NEAR(areaInt, areaDouble, 0.0001);
}

// ==================== Edge Cases Tests ====================

class EdgeCasesTest : public ::testing::Test {};

TEST_F(EdgeCasesTest, RectangleWithColinearPoints) {
    // Rectangle создает 4 вершины, даже если они коллинеарны
    Rectangle<int> rect({{0, 0}, {1, 0}, {2, 0}, {3, 0}});
    double area = static_cast<double>(rect);
    // Площадь может быть 0 для коллинеарных точек
    EXPECT_GE(area, 0.0);
}

TEST_F(EdgeCasesTest, VerySmallCoordinates) {
    Rectangle<double> rect({{0.0001, 0.0001}, {0.0002, 0.0001}, {0.0002, 0.0002}, {0.0001, 0.0002}});
    double area = static_cast<double>(rect);
    EXPECT_GT(area, 0.0);
}

TEST_F(EdgeCasesTest, RectangleWithNegativeCoordinates) {
    Rectangle<int> rect({{-100, -100}, {100, -100}, {100, 100}, {-100, 100}});
    double area = static_cast<double>(rect);
    EXPECT_DOUBLE_EQ(area, 40000.0);
}

TEST_F(EdgeCasesTest, SquareWithLargeValues) {
    Square<int> square({{0, 0}, {1000, 0}, {1000, 1000}, {0, 1000}});
    double area = static_cast<double>(square);
    EXPECT_DOUBLE_EQ(area, 1000000.0);
}

TEST_F(EdgeCasesTest, TrapezoidSymmetric) {
    Trapezoid<int> trap({{0, 0}, {10, 0}, {8, 4}, {2, 4}});
    double area = static_cast<double>(trap);
    EXPECT_GT(area, 0.0);
}

// ==================== Integration Tests ====================

class IntegrationTest : public ::testing::Test {};

TEST_F(IntegrationTest, CreatingMixedShapesArray) {
    std::vector<std::shared_ptr<Figure<int>>> shapes;

    shapes.push_back(std::make_shared<Rectangle<int>>(
        std::initializer_list<Point<int>>{{0, 0}, {10, 0}, {10, 5}, {0, 5}}));
    shapes.push_back(std::make_shared<Square<int>>(
        std::initializer_list<Point<int>>{{0, 0}, {5, 0}, {5, 5}, {0, 5}}));
    shapes.push_back(std::make_shared<Trapezoid<int>>(
        std::initializer_list<Point<int>>{{0, 0}, {6, 0}, {5, 3}, {1, 3}}));

    EXPECT_EQ(shapes.size(), 3);
    double totalArea = 0.0;
    for (const auto& shape : shapes) {
        totalArea += static_cast<double>(*shape);
    }
    EXPECT_GT(totalArea, 0.0);
}

TEST_F(IntegrationTest, ProcessingAllShapesWithCommonMethods) {
    std::vector<std::shared_ptr<Figure<double>>> shapes;

    shapes.push_back(std::make_shared<Rectangle<double>>(
        std::initializer_list<Point<double>>{{0.0, 0.0}, {10.0, 0.0}, {10.0, 5.0}, {0.0, 5.0}}));
    shapes.push_back(std::make_shared<Square<double>>(
        std::initializer_list<Point<double>>{{0.0, 0.0}, {5.0, 0.0}, {5.0, 5.0}, {0.0, 5.0}}));
    shapes.push_back(std::make_shared<Trapezoid<double>>(
        std::initializer_list<Point<double>>{{0.0, 0.0}, {6.0, 0.0}, {5.0, 3.0}, {1.0, 3.0}}));

    for (const auto& shape : shapes) {
        auto center = shape->calcGeometricCenter();
        double area = static_cast<double>(*shape);
        EXPECT_GE(area, 0.0);
    }
}

TEST_F(IntegrationTest, MoveSemanticsBetweenShapes) {
    Rectangle<int> rect({{0, 0}, {5, 0}, {5, 5}, {0, 5}});
    Rectangle<int> rect2(std::move(rect));
    double area = static_cast<double>(rect2);
    EXPECT_DOUBLE_EQ(area, 25.0);
}

// ==================== Additional Tests for Protected Constructors ====================

class ProtectedConstructorTest : public ::testing::Test {
protected:
    using RectangleInt = Rectangle<int>;
    using SquareInt = Square<int>;
    using TrapezoidInt = Trapezoid<int>;
};

TEST_F(ProtectedConstructorTest, RectangleDefaultConstructor) {
    RectangleInt rect;
    auto center = rect.calcGeometricCenter();
    EXPECT_NO_THROW(auto area = static_cast<double>(rect));
}

TEST_F(ProtectedConstructorTest, SquareDefaultConstructor) {
    SquareInt square;
    auto center = square.calcGeometricCenter();
    EXPECT_NO_THROW(auto area = static_cast<double>(square));
}

TEST_F(ProtectedConstructorTest, TrapezoidDefaultConstructor) {
    TrapezoidInt trap;
    auto center = trap.calcGeometricCenter();
    EXPECT_NO_THROW(auto area = static_cast<double>(trap));
}

TEST_F(ProtectedConstructorTest, RectangleInputOperator) {
    RectangleInt rect;
    std::istringstream iss("0 0 5 0 5 5 0 5");
    EXPECT_NO_THROW(iss >> rect);
}

TEST_F(ProtectedConstructorTest, SquareInputOperator) {
    SquareInt square;
    std::istringstream iss("0 0 4 0 4 4 0 4");
    EXPECT_NO_THROW(iss >> square);
}

TEST_F(ProtectedConstructorTest, TrapezoidInputOperator) {
    TrapezoidInt trap;
    std::istringstream iss("0 0 4 0 3 2 1 2");
    EXPECT_NO_THROW(iss >> trap);
}

TEST_F(ProtectedConstructorTest, RectangleOutputOperator) {
    RectangleInt rect({{0, 0}, {5, 0}, {5, 5}, {0, 5}});
    std::ostringstream oss;
    EXPECT_NO_THROW(oss << rect);
    EXPECT_GT(oss.str().length(), 0);
}

TEST_F(ProtectedConstructorTest, SquareOutputOperator) {
    SquareInt square({{0, 0}, {4, 0}, {4, 4}, {0, 4}});
    std::ostringstream oss;
    EXPECT_NO_THROW(oss << square);
    EXPECT_GT(oss.str().length(), 0);
}

TEST_F(ProtectedConstructorTest, TrapezoidOutputOperator) {
    TrapezoidInt trap({{0, 0}, {4, 0}, {3, 2}, {1, 2}});
    std::ostringstream oss;
    EXPECT_NO_THROW(oss << trap);
    EXPECT_GT(oss.str().length(), 0);
}