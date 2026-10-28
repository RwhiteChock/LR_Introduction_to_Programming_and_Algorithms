#include <iostream>
#include <limits>
#include <cmath>

// Безопасный ввод вещественного числа.
// При ошибке очищаем поток и повторяем запрос.
double readDouble(const char* prompt)
{
    double value;

    while (true)
    {
        std::cout << prompt;

        if (std::cin >> value && std::isfinite(value))
        {
            return value;
        }

        // Восстанавливаем поток после некорректного ввода.
        std::cin.clear();

        // Удаляем оставшиеся символы из входного буфера.
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );

        std::cout
            << "Invalid input. Please enter a valid finite number.\n";
    }
}

// Безопасный ввод символа операции.
char readOperation()
{
    char operation;

    while (true)
    {
        std::cout << "Enter an operation (+, -, *, /, ^, %): ";

        if (std::cin >> operation)
        {
            // Проверяем, относится ли символ к разрешённым операциям.
            switch (operation)
            {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case '%':
                return operation;

            default:
                std::cout
                    << "Invalid operation. Please try again.\n";
                break;
            }
        }
        else
        {
            // Обрабатываем ошибку чтения из входного потока.
            std::cin.clear();

            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n'
            );

            std::cout << "Invalid input. Please enter an operator.\n";
        }
    }
}

int main()
{
    std::cout << "========== CALCULATOR ==========\n";

    // Получаем два операнда.
    double a = readDouble("Enter the first number: ");
    double b = readDouble("Enter the second number: ");

    // Получаем операцию в виде символа.
    char operation = readOperation();

    // Переменная для хранения результата вычисления.
    double result = 0.0;

    // Флаг показывает, удалось ли выполнить операцию.
    bool success = true;

    // Выбираем математическое действие по введённому символу.
    switch (operation)
    {
    case '+':
        // Складываем два числа.
        result = a + b;
        break;

    case '-':
        // Вычитаем второе число из первого.
        result = a - b;
        break;

    case '*':
        // Умножаем первый операнд на второй.
        result = a * b;
        break;

    case '/':
        // Перед делением обязательно проверяем знаменатель.
        if (b == 0.0)
        {
            std::cout << "Error: division by zero is not allowed.\n";
            success = false;
        }
        else
        {
            result = a / b;
        }
        break;

    case '^':
        // Возводим первое число в степень, заданную вторым.
        result = std::pow(a, b);

        // Проверяем результат, например при переполнении
        // или недопустимой операции с вещественными числами.
        if (!std::isfinite(result))
        {
            std::cout
                << "Error: the power operation has no finite result.\n";
            success = false;
        }
        break;

    case '%':
        // Остаток вычисляется через fmod, поддерживающий double.
        if (b == 0.0)
        {
            std::cout
                << "Error: remainder by zero is not allowed.\n";
            success = false;
        }
        else
        {
            result = std::fmod(a, b);
        }
        break;

    default:
        // Защитная ветвь на случай изменения программы.
        std::cout << "Error: unsupported operation.\n";
        success = false;
        break;
    }

    // Проверяем, что результат можно корректно представить
    // конечным значением типа double.
    if (success && !std::isfinite(result))
    {
        std::cout << "Error: the result is outside the valid range.\n";
        success = false;
    }

    // Выводим результат только после успешного вычисления.
    if (success)
    {
        std::cout << "Result: " << a << ' ' << operation << ' '
            << b << " = " << result << '\n';
    }

    return 0;
}