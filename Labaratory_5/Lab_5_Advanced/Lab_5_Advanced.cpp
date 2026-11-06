#include <iostream>
#include <iomanip>

using namespace std;

// Функция двух переменных
double calculateZ(double x, double y) {
    return x * x + y * y;
}

int main() {
    double xStart, xEnd, hx;
    double yStart, yEnd, hy;

    cout << "Enter x start, x end and x step: ";
    cin >> xStart >> xEnd >> hx;

    cout << "Enter y start, y end and y step: ";
    cin >> yStart >> yEnd >> hy;

    // Проверка введённых данных
    if (xStart > xEnd || yStart > yEnd || hx <= 0 || hy <= 0) {
        cout << "Error: Invalid input." << endl;
        return 1;
    }

    cout << "\nFunction: z = x^2 + y^2\n\n";

    // Заголовок таблицы
    cout << setw(12) << "X / Y";

    for (double y = yStart; y <= yEnd; y += hy) {
        cout << setw(12) << fixed << setprecision(3) << y;
    }

    cout << endl;

    // Основной цикл по x
    for (double x = xStart; x <= xEnd; x += hx) {
        cout << setw(12) << fixed << setprecision(3) << x;

        // Внутренний цикл по y
        for (double y = yStart; y <= yEnd; y += hy) {
            double z = calculateZ(x, y);

            cout << setw(12) << fixed << setprecision(3) << z;
        }

        cout << endl;
    }

    cout << "\nCalculation completed!" << endl;

    return 0;
}
