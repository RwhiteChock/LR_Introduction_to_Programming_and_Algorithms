#include <iostream>  // Библиотека для ввода и вывода
#include <iomanip>   // Библиотека для оформления таблицы
#include <cmath>     // Библиотека для функции sin()

using namespace std;

int main() {

    // Объявляем переменные:
    // a - начало интервала
    // b - конец интервала
    // h - шаг изменения x
    double a, b, h;

    // Просим пользователя ввести начало, конец интервала и шаг
    cout << "Enter a, b and h: ";
    cin >> a >> b >> h;

    // Проверяем правильность введённых данных
    if (a > b || h <= 0) {
        cout << "Error: Invalid interval or step." << endl;
        return 1;
    }

    // Переменная для хранения суммы квадратов значений функции
    double sumSquares = 0;

    // Переменные для хранения минимального и максимального значений
    double minY, maxY;

    // Счётчик количества вычисленных значений
    int count = 0;

    // Выводим название функции
    cout << "\nFunction: y = x * sin(x)\n";

    // Выводим заголовок таблицы
    cout << left
         << setw(15) << "X"
         << setw(15) << "Y"
         << setw(15) << "Y^2"
         << endl;

    // Выводим разделительную линию
    cout << "---------------------------------------------" << endl;

    // Перебираем значения x от a до b с шагом h
    for (double x = a; x <= b; x += h) {

        // Вычисляем значение функции y = x * sin(x)
        double y = x * sin(x);

        // Вычисляем квадрат значения функции
        double ySquared = y * y;

        // Добавляем квадрат к общей сумме
        sumSquares += ySquared;

        // Для первого значения устанавливаем минимум и максимум
        if (count == 0) {
            minY = y;
            maxY = y;
        }
        else {
            // Проверяем, является ли текущее значение меньше минимума
            if (y < minY) {
                minY = y;
            }

            // Проверяем, является ли текущее значение больше максимума
            if (y > maxY) {
                maxY = y;
            }
        }

        // Выводим значения x, y и y^2 в таблицу
        cout << fixed << setprecision(6)
             << left
             << setw(15) << x
             << setw(15) << y
             << setw(15) << ySquared
             << endl;

        // Увеличиваем счётчик вычисленных значений
        count++;
    }

    // Выводим итоговые результаты вычислений
    cout << "\nSum of squares: " << sumSquares << endl;
    cout << "Minimum value: " << minY << endl;
    cout << "Maximum value: " << maxY << endl;
    cout << "Number of values: " << count << endl;

    // Сообщаем об успешном завершении программы
    cout << "\nCalculation completed successfully!" << endl;

    return 0;
}
