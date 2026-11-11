#include <iostream>
#include <cmath>
#include <string>
#include <Windows.h>

class Figure

{
protected:
    std::string name;
    int sides;
public:
    Figure(std::string name, int sides)
        : name(name), sides(sides)
    {
    }

    virtual bool isCorrect() const
    {
        return true;
    }

    virtual void printInfo() const
    {
        std::cout << name << ":" << std::endl;
        if (isCorrect())
            std::cout << "Правильная" << std::endl;
        else
            std::cout << "Неправильная" << std::endl;
        std::cout << "Количество сторон : " << sides << std::endl;
    }
    virtual ~Figure() {}
};

class Triangle : public Figure
{
protected:
    double a, b, c;
    double A, B, C;
public:
    Triangle(double a, double b, double c, double A, double B, double C, std::string name = "Треугольник")

        : Figure(name, 3), a(a), b(b), c(c), A(A), B(B), C(C)
    {
    }

    bool isCorrect() const override
    {
        return std::abs(A + B + C - 180) < 0.000001;
    }

    void printInfo() const override
    {
        Figure::printInfo();
        std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << std::endl;

        std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << std::endl;
    }
};

class RightTriangle : public Triangle

{
public:
    RightTriangle(double a, double b, double c, double A, double B, double C)

        : Triangle(a, b, c, A, B, C, "Прямоугольный треугольник")
    {
    }

    bool isCorrect() const override
    {
        return Triangle::isCorrect() && std::abs(C - 90) < 0.000001;
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(double a, double b, double A, double B)
        : Triangle(a, b, a, A, B, A, "Равнобедренный треугольник")
    {
    }

    bool isCorrect() const override
    {
        return Triangle::isCorrect() && std::abs(a - c) < 0.000001 && std::abs(A - C) < 0.000001;
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60, "Равносторонний треугольник")
    {
    }

    bool isCorrect() const override
    {
        return Triangle::isCorrect() && std::abs(a - b) < 0.000001 && std::abs(b - c) < 0.000001 && A == 60 && B == 60 && C == 60;
    }
};

class Quadrilateral : public Figure
{
protected:
    double a, b, c, d;
    double A, B, C, D;
public:
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D, std::string name = "Четырёхугольник")

        : Figure(name, 4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
    {
    }

    bool isCorrect() const override
    {
        return std::abs(A + B + C + D - 360) < 0.000001;
    }

    void printInfo() const override
    {
        Figure::printInfo();
        std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << " " << "d = " << d << std::endl;

        std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << " " << "D = " << D << std::endl;
    }
};

class MyRectangle : public Quadrilateral
{
public:
    MyRectangle(double a, double b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90, "Прямоугольник")
    {
    }
 
    bool isCorrect() const override
    {
        return Quadrilateral::isCorrect() && std::abs(a - c) < 0.000001 && std::abs(b - d) < 0.000001 
            && A == 90 && B == 90 && C == 90 && D == 90;
    }
};

class Square : public Quadrilateral
{
public:
    Square(double side)
        : Quadrilateral(side, side, side, side, 90, 90, 90, 90, "Квадрат")
    {
    }

    bool isCorrect() const override
    {
        return Quadrilateral::isCorrect() && std::abs(a - b) < 0.000001 &&std::abs(b - c) < 0.000001 &&

            std::abs(c - d) < 0.000001 && A == 90 && B == 90 && C == 90 && D == 90;
    }
};

class Parallelogram : public Quadrilateral
{
public:
   Parallelogram(double a, double b, double A, double B)

        : Quadrilateral(a, b, a, b, A, B, A, B, "Параллелограмм")
    {
    }

    bool isCorrect() const override
    {
        return Quadrilateral::isCorrect() && std::abs(a - c) < 0.000001 && std::abs(b - d) < 0.000001 &&

            std::abs(A - C) < 0.000001 && std::abs(B - D) < 0.000001;
    }
};

class Rhombus : public Quadrilateral
{
public:
    Rhombus(double side, double A, double B)
        : Quadrilateral(side, side, side, side, A, B, A, B, "Ромб")
    {
    }

    bool isCorrect() const override
    {
        return Quadrilateral::isCorrect() && std::abs(a - b) < 0.000001 && std::abs(b - c) < 0.000001 && std::abs(c - d) < 0.000001 &&

            std::abs(A - C) < 0.000001 && std::abs(B - D) < 0.000001;
    }
};

void print_info(Figure* figure)
{
    figure->printInfo();
    std::cout << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure figure("Фигура", 0);

    Triangle triangle(10, 20, 30, 50, 60, 70);

    RightTriangle rightTriangle1(10, 20, 30, 50, 60, 90);

    RightTriangle rightTriangle2(10, 20, 30, 50, 40, 90);

    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);

    EquilateralTriangle equilateralTriangle(30);

    Quadrilateral quadrilateral(10, 20, 30, 40,50, 60, 70, 80);

    MyRectangle rectangle(10, 20);

    Square square(20);

    Parallelogram parallelogram(20, 30, 30, 40);

    Rhombus rhombus(30, 30, 40);

    Figure* figures[] =
    {
        &figure,
        &triangle,
        &rightTriangle1,
        &rightTriangle2,
        &isoscelesTriangle,
        &equilateralTriangle,
        &quadrilateral,
        &rectangle,
        &square,
        &parallelogram,
        &rhombus
    };

    for (Figure* f : figures)
    {
        print_info(f);
    }
    return 0;
}