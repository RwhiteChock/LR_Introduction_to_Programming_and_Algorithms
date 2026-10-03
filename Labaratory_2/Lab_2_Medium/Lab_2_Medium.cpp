#include <iostream>
#include <iomanip>

int main()
{
    // Константа PI используется для вычисления объёма цилиндра.
    // Тип double выбран для хранения вещественного значения числа PI.
    // Ключевое слово const запрещает изменять значение этой константы.
    const double PI = 3.141592653589793;

    // Переменная radius хранит радиус цилиндра.
    // Используем double, поскольку радиус может быть дробным,
    // например 2.5.
    double radius;

    // Переменная height хранит высоту цилиндра.
    // Также используем double, чтобы разрешить дробные значения.
    double height;

    // Запрашиваем у пользователя радиус цилиндра.
    std::cout << "Enter the radius of the cylinder: ";
    std::cin >> radius;

    // Запрашиваем у пользователя высоту цилиндра.
    std::cout << "Enter the height of the cylinder: ";
    std::cin >> height;

    // Вычисляем квадрат радиуса.
    // static_cast<double> демонстрирует явное приведение типа.
    // В данном случае radius уже имеет тип double,
    // поэтому результат остаётся вещественным.
    double radiusSquared = static_cast<double>(radius) * radius;

    // Вычисляем объём цилиндра по формуле:
    // V = PI * R^2 * h
    double volume = PI * radiusSquared * height;

    // Устанавливаем фиксированный формат вывода.
    // setprecision(2) означает, что после десятичной точки
    // будет отображаться ровно две цифры.
    std::cout << std::fixed << std::setprecision(2);

    // Выводим результат вычисления объёма.
    std::cout << "Volume of the cylinder: " << volume << std::endl;

    // Завершаем работу программы.
    return 0;
}