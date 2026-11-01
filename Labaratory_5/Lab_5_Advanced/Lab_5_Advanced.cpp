#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

// Функция двух переменных
double calculateZ(double x, double y) {
    return x * x + y * y;
}

// Функция для проверки ввода одного числа
bool readNumber(double& value) {
    if (!(cin >> value)) {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }

    return isfinite(value);
}

int main() {
    double xStart, xEnd, hx;
    double yStart, yEnd, hy;

    // Вводим границы и шаг для переменной x
    cout << "Enter x start, x end and x step: ";

    if (!readNumber(xStart) ||
        !readNumber(xEnd) ||
        !readNumber(hx)) {
        cout << "Error: Please enter valid numbers." << endl;
        return 1;
    }

    // Вводим границы и шаг для переменной y
    cout << "Enter y start, y end and y step: ";

    if (!readNumber(yStart) ||
        !readNumber(yEnd) ||
        !readNumber(hy)) {
        cout << "Error: Please enter valid numbers." << endl;
        return 1;
    }

    // Проверяем корректность границ и шагов
    if (xStart > xEnd || yStart > yEnd ||
        hx <= 0 || hy <= 0) {
        cout << "Error: Invalid interval or step." << endl;
        return 1;
    }

    // Задаём погрешность для сравнения вещественных чисел
    const double EPS = 1e-9;

    // Ограничиваем количество значений по каждой оси
    const int MAX_POINTS = 1000;

    // Сохраняем значения y для построения заголовка таблицы
    vector<double> yValues;

    // Формируем список значений y с заданным шагом
    for (int i = 0; ; i++) {
        if (i >= MAX_POINTS) {
            cout << "Error: Too many y values." << endl;
            return 1;
        }

        double y = yStart + i * hy;

        // Проверяем, не вышли ли за верхнюю границу
        if (y > yEnd + EPS) {
            break;
        }

        // Проверяем корректность вычисленного значения
        if (!isfinite(y)) {
            cout << "Error: Calculation overflow." << endl;
            return 1;
        }

        yValues.push_back(y);
    }

    // Проверяем, что список значений y не пуст
    if (yValues.empty()) {
        cout << "Error: No y values to display." << endl;
        return 1;
    }

    // Выводим название функции
    cout << "\nFunction: z = x^2 + y^2\n\n";

    // Выводим заголовок таблицы
    cout << left << setw(12) << "X / Y";

    for (double y : yValues) {
        cout << setw(12) << fixed << setprecision(3) << y;
    }

    cout << endl;

    // Выводим разделительную линию
    cout << string(12 * (yValues.size() + 1), '-') << endl;

    // Внешний цикл перебирает значения x
    for (int i = 0; ; i++) {
        if (i >= MAX_POINTS) {
            cout << "Error: Too many x values." << endl;
            return 1;
        }

        double x = xStart + i * hx;

        // Завершаем цикл при достижении конца интервала x
        if (x > xEnd + EPS) {
            break;
        }

        // Проверяем корректность текущего значения x
        if (!isfinite(x)) {
            cout << "Error: Calculation overflow." << endl;
            return 1;
        }

        // Выводим значение x в начале строки
        cout << left << setw(12) << fixed << setprecision(3) << x;

        // Внутренний цикл перебирает все значения y
        for (double y : yValues) {
            // Вычисляем значение функции для текущих x и y
            double z = calculateZ(x, y);

            // Проверяем корректность результата
            if (!isfinite(z)) {
                cout << "\nError: Calculation overflow." << endl;
                return 1;
            }

            // Выводим значение функции в таблицу
            cout << setw(12) << fixed << setprecision(3) << z;
        }

        // Переходим к следующей строке таблицы
        cout << endl;
    }

    // Сообщаем об успешном завершении программы
    cout << "\nCalculation completed successfully!" << endl;

    return 0;
}