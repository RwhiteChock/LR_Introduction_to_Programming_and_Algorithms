#include <iostream>
#include <limits>

// Функция безопасного ввода целого числа.
// Повторяет запрос, если пользователь ввёл буквы или другой неверный ввод.
int readInt(const char* prompt)
{
    int value;

    while (true)
    {
        std::cout << prompt;

        if (std::cin >> value)
        {
            // Возвращаем введённое число, если ввод корректен.
            return value;
        }

        // Сбрасываем состояние ошибки потока ввода.
        std::cin.clear();

        // Удаляем некорректные символы из входного буфера.
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );

        std::cout << "Invalid input. Please enter an integer.\n";
    }
}

int main()
{
    // Запрашиваем номер месяца у пользователя.
    int month = readInt("Enter the month number (1-12): ");

    // Выбираем количество дней с помощью оператора switch.
    switch (month)
    {
    case 1:
        // January содержит 31 день.
        std::cout << "January: 31 days.\n";
        break;

    case 2:
        // По условию задачи февраль всегда содержит 28 дней.
        std::cout << "February: 28 days.\n";
        break;

    case 3:
        // March содержит 31 день.
        std::cout << "March: 31 days.\n";
        break;

    case 4:
        // April содержит 30 дней.
        std::cout << "April: 30 days.\n";
        break;

    case 5:
        // May содержит 31 день.
        std::cout << "May: 31 days.\n";
        break;

    case 6:
        // June содержит 30 дней.
        std::cout << "June: 30 days.\n";
        break;

    case 7:
        // July содержит 31 день.
        std::cout << "July: 31 days.\n";
        break;

    case 8:
        // August содержит 31 день.
        std::cout << "August: 31 days.\n";
        break;

    case 9:
        // September содержит 30 дней.
        std::cout << "September: 30 days.\n";
        break;

    case 10:
        // October содержит 31 день.
        std::cout << "October: 31 days.\n";
        break;

    case 11:
        // November содержит 30 дней.
        std::cout << "November: 30 days.\n";
        break;

    case 12:
        // December содержит 31 день.
        std::cout << "December: 31 days.\n";
        break;

    default:
        // Обрабатываем числа, не соответствующие месяцам.
        std::cout << "Error: month number must be from 1 to 12.\n";
        break;
    }

    return 0;
}