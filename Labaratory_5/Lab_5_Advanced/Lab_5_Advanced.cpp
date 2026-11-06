#include <iostream>  // Библиотека для ввода и вывода
#include <iomanip>  // Библиотека для форматирования таблицы

using namespace std;

// Функция для вычисления значения z
// На вход получаем два числа: x и y
// Возвращаем результат по формуле z = x^2 + y^2
double calculateZ(double x, double y) {
    return x * x + y * y;
}

int main() {

    // Объявляем переменные для X:
    // xStart - начальное значение X
    // xEnd - конечное значение X
    // hx - шаг изменения X
    double xStart, xEnd, hx;

    // Объявляем переменные для Y:
    // yStart - начальное значение Y
    // yEnd - конечное значение Y
    // hy - шаг изменения Y
    double yStart, yEnd, hy;

    // Просим пользователя ввести начальное значение X,
    // конечное значение X и шаг изменения X
    cout << "Enter x start, x end and x step: ";
    cin >> xStart >> xEnd >> hx;

    // Просим пользователя ввести начальное значение Y,
    // конечное значение Y и шаг изменения Y
    cout << "Enter y start, y end and y step: ";
    cin >> yStart >> yEnd >> hy;

    // Проверяем правильность введённых данных:
    // начальное значение не должно быть больше конечного,
    // шаг изменения должен быть положительным
    if (xStart > xEnd || yStart > yEnd || hx <= 0 || hy <= 0) {
        cout << "Error: Invalid input." << endl;
        return 1; // Завершаем программу при ошибке
    }

    // Выводим название функции
    cout << "\nFunction: z = x^2 + y^2\n\n";

    // Выводим заголовок таблицы
    // setw(12) задаёт ширину каждого столбца в 12 символов
    cout << setw(12) << "X / Y";

    // Цикл для вывода значений Y в верхней строке таблицы
    // y начинается с yStart и увеличивается на hy
    for (double y = yStart; y <= yEnd; y += hy) {
        cout << setw(12) << fixed << setprecision(3) << y;
    }

    // Переходим на новую строку
    cout << endl;

    // Внешний цикл перебирает значения X
    // x увеличивается на hx после каждой итерации
    for (double x = xStart; x <= xEnd; x += hx) {

        // Выводим текущее значение X в начале строки
        cout << setw(12) << fixed << setprecision(3) << x;

        // Внутренний цикл перебирает все значения Y
        for (double y = yStart; y <= yEnd; y += hy) {

            // Вычисляем значение функции для текущих X и Y
            double z = calculateZ(x, y);

            // Выводим полученное значение в таблицу
            cout << setw(12) << fixed << setprecision(3) << z;
        }

        // После завершения внутреннего цикла
        // переходим на следующую строку таблицы
        cout << endl;
    }

    // Сообщаем об успешном завершении программы
    cout << "\nCalculation completed!" << endl;

    return 0; // Завершаем программу
}
