#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Задаём точность сравнения чисел с плавающей точкой.
    // Это позволяет учитывать небольшие погрешности вычислений.
    const double EPSILON = 1e-9;

    // Объявляем переменные для хранения трёх сторон.
    double A, B, C;

    // Просим пользователя ввести три числа.
    cout << "Enter three numbers A, B, C: ";

    // Проверяем, удалось ли считать все три числа.
    if (!(cin >> A >> B >> C))
    {
        // Выводим сообщение, если введены не числа.
        cout << "ERROR: Invalid input!" << endl;
        return 1;
    }

    // Проверяем, что все стороны положительные.
    if (A <= 0 || B <= 0 || C <= 0)
    {
        cout << "ERROR: All sides must be positive!" << endl;
        return 1;
    }

    // Упорядочиваем числа по возрастанию.
    // После этих действий A будет наименьшей стороной,
    // B — средней, а C — наибольшей.

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

    // Проверяем неравенство треугольника.
    // Сумма двух меньших сторон должна быть больше наибольшей.
    if (A + B <= C)
    {
        cout << "These numbers cannot form a triangle." << endl;
        return 0;
    }

    // Проверяем теорему Пифагора с учётом заданной точности.
    // Если разница между A^2 + B^2 и C^2 меньше EPSILON,
    // считаем равенство выполненным.
    if (fabs(A * A + B * B - C * C) < EPSILON)
    {
        cout << "The triangle is a right triangle." << endl;
    }
    else
    {
        // Если равенство не выполняется, треугольник
        // не является прямоугольным.
        cout << "The triangle is not a right triangle." << endl;
    }

    return 0;
}