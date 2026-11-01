#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, h;

    // Ввод начала и конца интервала, а также шага
    cout << "Enter a, b and h: ";

    // Проверка корректности ввода
    if (!(cin >> a >> b >> h)) {
        cout << "Error: Please enter valid numbers." << endl;
        return 1;
    }

    // Проверка введённых значений
    if (!isfinite(a) || !isfinite(b) || !isfinite(h)
        || a > b || h <= 0) {
        cout << "Error: Invalid interval or step." << endl;
        return 1;
    }

    // Задаём погрешность для вещественных чисел
    const double EPS = 1e-9;

    // Ограничиваем количество итераций
    const int MAX_ROWS = 100000;
    int count = 0;

    // Выводим заголовок таблицы
    cout << "\nFunction: y = -x^2 + 4x\n";
    cout << left
        << setw(15) << "X"
        << setw(15) << "Y"
        << endl;

    cout << "------------------------------" << endl;

    // Перебираем значения x от a до b с заданным шагом
    for (double x = a; x <= b + EPS; x += h) {

        // Проверяем корректность текущего значения x
        if (!isfinite(x)) {
            cout << "Error: Calculation overflow." << endl;
            return 1;
        }

        // Вычисляем значение функции
        double y = -x * x + 4 * x;

        // Выводим значения x и y в таблицу
        cout << fixed << setprecision(4)
            << left
            << setw(15) << x
            << setw(15) << y
            << endl;

        // Увеличиваем счётчик итераций
        count++;

        // Проверяем, не превышено ли допустимое количество строк
        if (count >= MAX_ROWS) {
            cout << "Error: Too many iterations." << endl;
            return 1;
        }
    }

    // Сообщаем об успешном завершении программы
    cout << "\nCalculation completed successfully!" << endl;

    return 0;
}