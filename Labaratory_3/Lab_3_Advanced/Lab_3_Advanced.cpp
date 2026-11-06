#include <iostream>

using namespace std;

int main()
{
    double A, B, C;

    cout << "Enter three numbers A, B, C: ";
    cin >> A >> B >> C;

    // Проверяем правильность ввода
    if (A <= 0 || B <= 0 || C <= 0)
    {
        cout << "ERROR: All sides must be positive!" << endl;
        return 1;
    }

    // Упорядочиваем стороны по возрастанию
    double temp;

    if (A > B)
    {
        temp = A;
        A = B;
        B = temp;
    }

    if (B > C)
    {
        temp = B;
        B = C;
        C = temp;
    }

    if (A > B)
    {
        temp = A;
        A = B;
        B = temp;
    }

    // Проверяем, можно ли построить треугольник
    if (A + B <= C)
    {
        cout << "These numbers cannot form a triangle." << endl;
        return 0;
    }

    // Проверяем, является ли треугольник прямоугольным
    if (A * A + B * B == C * C)
    {
        cout << "The triangle is a right triangle." << endl;
    }
    else
    {
        cout << "The triangle is not a right triangle." << endl;
    }

    return 0;
}
