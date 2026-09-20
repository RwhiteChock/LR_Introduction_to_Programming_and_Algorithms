#include <iostream>
#include <iomanip>
#include <limits>

int main()
{
    // Константа для перевода процентов в десятичную долю.
    // Используем const, чтобы значение не изменялось во время работы программы.
    const double PERCENT_DIVISOR = 100.0;

    // Стоимость обеда и процент чаевых могут быть дробными, поэтому используем тип double.
    // Тип double позволяет хранить вещественные числа, например 1250.50 или 12.5.
    // При работе с double возможна небольшая погрешность представления некоторых дробных чисел.
    double mealCost{};
    double tipPercent{};

    // Запрашиваем стоимость обеда.
    std::cout << "Enter the meal cost: ";
    std::cin >> mealCost;

    // Проверяем, что пользователь ввёл число.
    if (std::cin.fail())
    {
        // Сбрасываем состояние ошибки ввода.
        std::cin.clear();

        // Удаляем некорректные данные из буфера ввода.
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Error: a number must be entered."
            << std::endl;

        return 1;
    }

    // Проверяем граничное значение: стоимость обеда не может быть отрицательной.
    if (mealCost < 0)
    {
        std::cout << "Error: meal cost cannot be negative."
            << std::endl;

        return 1;
    }

    // Запрашиваем процент чаевых.
    std::cout << "Enter the tip percentage: ";
    std::cin >> tipPercent;

    // Проверяем корректность второго ввода.
    if (std::cin.fail())
    {
        // Сбрасываем состояние ошибки ввода.
        std::cin.clear();

        // Удаляем некорректные данные из буфера ввода.
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Error: a number must be entered."
            << std::endl;

        return 1;
    }

    // Проверяем граничное значение: процент чаевых не может быть отрицательным.
    if (tipPercent < 0)
    {
        std::cout << "Error: tip percentage cannot be negative."
            << std::endl;

        return 1;
    }

    // Явно преобразуем процент в тип double перед делением.
    // Это демонстрирует понимание приведения типов и предотвращает целочисленное деление.
    // При использовании очень больших чисел типа doubleвозможна потеря точности или переполнение.
    double tipRate = static_cast<double>(tipPercent)
        / PERCENT_DIVISOR;

    // Рассчитываем сумму чаевых.
    double tipAmount = mealCost * tipRate;

    // Рассчитываем общую стоимость обеда.
    double totalCost = mealCost + tipAmount;

    // Форматируем вещественные числа: fixed выводит число в обычном десятичном формате, setprecision(2) оставляет два знака после запятой.
    // Это удобно для денежных значений и скрывает
    // небольшую погрешность представления дробных чисел.
    std::cout << std::fixed << std::setprecision(2);

    // Выводим результаты в виде структурированного сообщения.
    std::cout << "\n-----------------------------\n";
    std::cout << "Meal cost:       " << mealCost << "\n";
    std::cout << "Tip:             " << tipAmount << "\n";
    std::cout << "Total:           " << totalCost << "\n";
    std::cout << "-----------------------------\n";

    // Завершаем программу с кодом 0, который означает успешное выполнение.
    return 0;
}