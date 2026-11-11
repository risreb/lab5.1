#include <iostream>
#include <Windows.h>

class Figure
{
public:
    virtual void print() const = 0;
    virtual ~Figure() {}
};

class Triangle : public Figure
{
private:

    double a, b, c;
    double A, B, C;

public:

    Triangle(double a, double b, double c, double A, double B, double C)

        : a(a), b(b), c(c), A(A), B(B), C(C)
    {
    }

    void print() const override
    {

        std::cout << "Стороны: "

            << "a = " << a << " " << "b = " << b << " " << "c = " << c << std::endl;

        std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << std::endl;

    }

};

class RightTriangle : public Triangle

{
public:

    RightTriangle(double a, double b, double c, double A, double B)

        : Triangle(a, b, c, A, B, 90)
    {
    }

};

class IsoscelesTriangle : public Triangle

{
public:

    IsoscelesTriangle(double a, double b, double A, double B)

        : Triangle(a, b, a, A, B, A)
    {
    }
};

class EquilateralTriangle : public Triangle

{
public:

    EquilateralTriangle(double side)

        : Triangle(side, side, side, 60, 60, 60)
    {
    }
};

class Quadrilateral : public Figure

{
private:

    double a, b, c, d;
    double A, B, C, D;

public:

    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D)

        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
    {

    }

    void print() const override
    {
        std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << " " << "d = " << d << std::endl;

        std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << " " << "D = " << D << std::endl;
    }
};

class MyRectangle : public Quadrilateral

{
public:
    MyRectangle(double a, double b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90)
    {
    }
};

class Square : public Quadrilateral

{
public:
    Square(double side)
        : Quadrilateral(side, side, side, side, 90, 90, 90, 90)
    {
    }
};

class Parallelogram : public Quadrilateral

{
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B)
    {
    }
};

class Rhombus : public Quadrilateral

{
public:
    Rhombus(double side, double A, double B)
        : Quadrilateral(side, side, side, side, A, B, A, B)
    {
    }
};

void print_info(Figure* figure)

{
    figure->print();
    std::cout << std::endl;
}

int main()

{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Triangle triangle(10, 20, 30, 50, 60, 70);

    RightTriangle rightTriangle(10, 20, 30, 50, 60);

    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);

    EquilateralTriangle equilateralTriangle(30);

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);

    MyRectangle rectangle(10, 20);

    Square square(20);

    Parallelogram parallelogram(20, 30, 30, 40);

    Rhombus rhombus(30, 30, 40);

    std::cout << "Треугольник: " << std::endl;

    print_info(&triangle);

    std::cout << "Прямоугольный треугольник : "  << std::endl;

    print_info(&rightTriangle);

    std::cout << "Равнобедренный треугольник : " << std::endl;

    print_info(&isoscelesTriangle);

    std::cout << "Равносторонний треугольник : " << std::endl;

    print_info(&equilateralTriangle);

    std::cout << "Четырёхугольник:" << std::endl;

    print_info(&quadrilateral);

    std::cout <<"Прямоугольник:" << std::endl;

    print_info(&rectangle);

    std::cout << "Квадрат:" << std::endl;

    print_info(&square);
    std::cout << "Параллелограмм : " << std::endl;

    print_info(&parallelogram);

    std::cout << "Ромб: " << std::endl;

    print_info(&rhombus);

    return 0;

}
   
   