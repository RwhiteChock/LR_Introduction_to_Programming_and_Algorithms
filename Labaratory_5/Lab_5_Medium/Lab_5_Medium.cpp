#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, h;

    // Вводим начало и конец интервала, а также шаг
    cout << "Enter a, b and h: ";

    // Проверяем корректность ввода
    if (!(cin >> a >> b >> h)) {
        cout << "Error: Please enter valid numbers." << endl;
        return 1;
    }

    // Проверяем границы интервала и значение шага
    if (!isfinite(a) || !isfinite(b) || !isfinite(h)
        || a > b || h <= 0) {
        cout << "Error: Invalid interval or step." << endl;
        return 1;
    }

    // Задаём погрешность для вещественных чисел
    const double EPS = 1e-9;

    // Задаём максимальное количество строк таблицы
    const int MAX_ROWS = 100000;

    // Инициализируем сумму квадратов и счётчик строк
    double sumSquares = 0.0;
    int count = 0;

    // Инициализируем переменные для минимума и максимума
    double minY = 0.0;
    double maxY = 0.0;

    // Выводим название функции и заголовок таблицы
    cout << "\nFunction: y = x * sin(x)\n";

    cout << left
        << setw(15) << "X"
        << setw(15) << "Y"
        << setw(15) << "Y^2"
        << endl;

    cout << "---------------------------------------------" << endl;

    // Перебираем значения x на заданном интервале
    for (double x = a; x <= b + EPS; x += h) {

        // Проверяем, что текущее значение x конечно
        if (!isfinite(x)) {
            cout << "Error: Calculation overflow." << endl;
            return 1;
        }

        // Вычисляем значение функции y = x * sin(x)
        double y = x * sin(x);

        // Вычисляем квадрат значения функции
        double ySquared = y * y;

        // Проверяем корректность результатов вычислений
        if (!isfinite(y) || !isfinite(ySquared)) {
            cout << "Error: Calculation overflow." << endl;
            return 1;
        }

        // Добавляем квадрат значения функции к общей сумме
        sumSquares += ySquared;

        // Для первой строки задаём начальные минимум и максимум
        if (count == 0) {
            minY = y;
            maxY = y;
        }
        else {
            // Обновляем минимальное значение функции
            if (y < minY) {
                minY = y;
            }

            // Обновляем максимальное значение функции
            if (y > maxY) {
                maxY = y;
            }
        }

        // Выводим x, y и квадрат y в таблицу
        cout << fixed << setprecision(6)
            << left
            << setw(15) << x
            << setw(15) << y
            << setw(15) << ySquared
            << endl;

        // Увеличиваем количество обработанных значений
        count++;

        // Останавливаем программу, если строк слишком много
        if (count >= MAX_ROWS) {
            cout << "Error: Too many iterations." << endl;
            return 1;
        }
    }

    // Проверяем, что были вычислены значения функции
    if (count == 0) {
        cout << "No values were calculated." << endl;
        return 1;
    }

    // Выводим сумму квадратов, минимум и максимум
    cout << "\nSum of squares: " << sumSquares << endl;
    cout << "Minimum value: " << minY << endl;
    cout << "Maximum value: " << maxY << endl;
    cout << "Number of values: " << count << endl;

    // Сообщаем об успешном завершении вычислений
    cout << "\nCalculation completed successfully!" << endl;

    return 0;
}