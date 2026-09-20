#include <iostream>

int main()
{
    // Объявляем переменные для хранения длин трёх сторон.
    // Используем double, так как длина стороны может быть дробным числом.
    double sideA{};
    double sideB{};
    double sideC{};

    // Запрашиваем у пользователя длину первой стороны.
    std::cout << "Enter the length of the first side: ";
    std::cin >> sideA;

    // Запрашиваем длину второй стороны.
    std::cout << "Enter the length of the second side: ";
    std::cin >> sideB;

    // Запрашиваем длину третьей стороны.
    std::cout << "Enter the length of the third side: ";
    std::cin >> sideC;

    // Периметр треугольника равен сумме длин его трёх сторон.
    double perimeter = sideA + sideB + sideC;

    // Выводим рассчитанный периметр на экран.
    std::cout << "\nTriangle perimeter: "
        << perimeter << std::endl;

    return 0;
}