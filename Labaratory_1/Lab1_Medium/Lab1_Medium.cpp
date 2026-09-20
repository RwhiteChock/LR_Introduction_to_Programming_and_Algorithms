#include <iostream>

int main()
{
    // Объявляем переменные для длин двух отрезков.
    // Используем int, потому что в условии длины заданы
    // в сантиметрах без указания дробной части.
    // Целочисленный тип также позволяет использовать
    // деление с остатком для перевода сантиметров в метры.
    int firstSegment{};
    int secondSegment{};

    // Запрашиваем длину первого отрезка в сантиметрах.
    std::cout << "Enter the length of the first segment (cm): ";
    std::cin >> firstSegment;

    // Запрашиваем длину второго отрезка в сантиметрах.
    std::cout << "Enter the length of the second segment (cm): ";
    std::cin >> secondSegment;

    // Складываем длины двух отрезков.
    int totalCentimeters = firstSegment + secondSegment;

    // В одном метре содержится 100 сантиметров.
    // Используем константу вместо записи числа 100 непосредственно
    // в формулах, чтобы код был понятнее.
    const int centimetersInMeter = 100;
    // Целочисленное деление определяет количество полных метров.
    int meters = totalCentimeters / centimetersInMeter;

    // Остаток от деления определяет оставшиеся сантиметры.
    int centimeters = totalCentimeters % centimetersInMeter;

    // Выводим результат в метрах и сантиметрах.
    std::cout << "\nSum: " << meters
        << " m " << centimeters << " см" << std::endl;

    return 0;
}