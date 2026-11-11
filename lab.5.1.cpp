#include <iostream>
#include <Windows.h>

class Figure
{
private:
    int sides;

public:
    Figure(int count)
    {
        sides = count;
    }
    int getSides()
    {
        return sides;
    }
};

class Triangle : public Figure
{
public:
    Triangle() : Figure(3)
    {
    }
};

class Quaddrilateral : public Figure
{
public:
    Quaddrilateral() : Figure(4)
    {
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure figure{ 0 };
    Triangle triangle;
    Quaddrilateral quaddrilateral;

    std::cout << "Количество сторон: " << std::endl;

    std::cout << "Фигура: " << figure.getSides() << std::endl;
    std::cout << "Треугольник: " << triangle.getSides() << std::endl;
    std::cout << "Четырехугольник: " << quaddrilateral.getSides() << std::endl;

    return 0;
    
}
