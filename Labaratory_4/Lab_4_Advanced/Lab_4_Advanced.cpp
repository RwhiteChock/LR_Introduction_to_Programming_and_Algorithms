#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>

// ============================================================
// ЛАБОРАТОРНАЯ РАБОТА № 4
// Повышенный уровень, вариант № 11.
// Магазин с категориями товаров, корзиной и скидками.
//
// Используются:
// 1. Вложенные операторы switch.
// 2. Проверка корректности пользовательского ввода.
// 3. Очистка потока при ошибках через cin.clear() и cin.ignore().
// 4. Повторный запрос при некорректном вводе.
// 5. Проверка количества товаров и стоимости заказа.
// 6. Расчёт скидки и формирование чека.
// ============================================================

// Структура описывает один товар в корзине.
struct CartItem
{
    std::string name; // Название товара.
    double price;     // Цена одной единицы товара.
    int quantity;     // Количество единиц товара.
};

// ------------------------------------------------------------
// Функция безопасного ввода целого числа.
//
// Если пользователь вводит буквы вместо числа, программа
// очищает состояние потока, удаляет ошибочные символы
// и повторяет запрос.
// ------------------------------------------------------------
int readInt(const std::string& prompt)
{
    int value;

    while (true)
    {
        std::cout << prompt;

        if (std::cin >> value)
        {
            return value;
        }

        // Сбрасываем состояние ошибки стандартного потока.
        std::cin.clear();

        // Удаляем некорректные данные из буфера ввода.
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );

        std::cout
            << "Invalid input. Please enter an integer.\n";
    }
}

// ------------------------------------------------------------
// Функция добавления товара в корзину.
//
// Если товар уже присутствует в корзине, увеличиваем его
// количество, чтобы не создавать лишние позиции в чеке.
// ------------------------------------------------------------
void addToCart(
    std::vector<CartItem>& cart,
    const std::string& name,
    double price,
    int quantity)
{
    // Защищаем корзину от некорректных значений.
    if (quantity <= 0 || price < 0.0)
    {
        std::cout << "Error: invalid product quantity or price.\n";
        return;
    }

    // Проверяем, есть ли такой товар в корзине.
    for (CartItem& item : cart)
    {
        if (item.name == name && item.price == price)
        {
            // Проверяем переполнение при сложении количеств.
            if (quantity > std::numeric_limits<int>::max()
                - item.quantity)
            {
                std::cout
                    << "Error: product quantity limit exceeded.\n";
                return;
            }

            // Увеличиваем количество существующей позиции.
            item.quantity += quantity;

            std::cout << "Product quantity updated: "
                << item.name << ".\n";
            return;
        }
    }

    // Если товар ещё не добавлялся, создаём новую позицию.
    cart.push_back({ name, price, quantity });

    std::cout << "Product added to cart: " << name << ".\n";
}

// ------------------------------------------------------------
// Функция выбора количества товара.
//
// Количество должно быть положительным целым числом.
// Ноль и отрицательные значения не принимаются.
// ------------------------------------------------------------
int readQuantity()
{
    while (true)
    {
        int quantity = readInt("Enter quantity (1 or more): ");

        if (quantity > 0)
        {
            return quantity;
        }

        std::cout
            << "Invalid quantity. Please enter a positive integer.\n";
    }
}

// ------------------------------------------------------------
// Функция вывода меню конкретной категории.
//
// Внутри каждого пункта категории используется вложенный
// switch для выбора конкретного товара.
// ------------------------------------------------------------
void selectProduct(
    int category,
    std::vector<CartItem>& cart)
{
    int productChoice;

    // Внешний switch определяет категорию товаров.
    switch (category)
    {
    case 1:
    {
        // Категория 1: салаты.
        std::cout << "\n--- SALADS ---\n";
        std::cout << "1. Caesar Salad - $8.50\n";
        std::cout << "2. Greek Salad  - $7.00\n";
        std::cout << "0. Return to main menu\n";

        productChoice = readInt("Choose a salad: ");

        // Вложенный switch выбирает конкретный салат.
        switch (productChoice)
        {
        case 1:
        {
            // Добавляем салат «Цезарь».
            int quantity = readQuantity();

            addToCart(
                cart, "Caesar Salad", 8.50, quantity
            );
            break;
        }

        case 2:
        {
            // Добавляем греческий салат.
            int quantity = readQuantity();

            addToCart(
                cart, "Greek Salad", 7.00, quantity
            );
            break;
        }

        case 0:
            // Возвращаемся к главному меню магазина.
            std::cout << "Returning to main menu.\n";
            break;

        default:
            // Обрабатываем неправильный номер блюда.
            std::cout << "Invalid salad selection.\n";
            break;
        }

        break;
    }

    case 2:
    {
        // Категория 2: горячие блюда.
        std::cout << "\n--- HOT MEALS ---\n";
        std::cout << "1. Chicken Steak - $12.00\n";
        std::cout << "2. Pasta         - $9.50\n";
        std::cout << "0. Return to main menu\n";

        productChoice = readInt("Choose a hot meal: ");

        // Вложенный switch обрабатывает выбор блюда.
        switch (productChoice)
        {
        case 1:
        {
            // Добавляем куриный стейк.
            int quantity = readQuantity();

            addToCart(
                cart, "Chicken Steak", 12.00, quantity
            );
            break;
        }

        case 2:
        {
            // Добавляем пасту.
            int quantity = readQuantity();

            addToCart(
                cart, "Pasta", 9.50, quantity
            );
            break;
        }

        case 0:
            // Возврат к главному меню.
            std::cout << "Returning to main menu.\n";
            break;

        default:
            // Неверный номер горячего блюда.
            std::cout << "Invalid hot meal selection.\n";
            break;
        }

        break;
    }

    case 3:
    {
        // Категория 3: напитки.
        std::cout << "\n--- DRINKS ---\n";
        std::cout << "1. Water       - $1.50\n";
        std::cout << "2. Orange Juice - $3.00\n";
        std::cout << "0. Return to main menu\n";

        productChoice = readInt("Choose a drink: ");

        // Вложенный switch выбирает напиток.
        switch (productChoice)
        {
        case 1:
        {
            // Добавляем воду.
            int quantity = readQuantity();

            addToCart(
                cart, "Water", 1.50, quantity
            );
            break;
        }

        case 2:
        {
            // Добавляем апельсиновый сок.
            int quantity = readQuantity();

            addToCart(
                cart, "Orange Juice", 3.00, quantity
            );
            break;
        }

        case 0:
            // Возвращаемся к главному меню.
            std::cout << "Returning to main menu.\n";
            break;

        default:
            // Обрабатываем неверный выбор напитка.
            std::cout << "Invalid drink selection.\n";
            break;
        }

        break;
    }

    case 4:
    {
        // Категория 4: десерты.
        std::cout << "\n--- DESSERTS ---\n";
        std::cout << "1. Cheesecake - $5.00\n";
        std::cout << "2. Ice Cream  - $3.50\n";
        std::cout << "0. Return to main menu\n";

        productChoice = readInt("Choose a dessert: ");

        // Вложенный switch выбирает десерт.
        switch (productChoice)
        {
        case 1:
        {
            // Добавляем чизкейк.
            int quantity = readQuantity();

            addToCart(
                cart, "Cheesecake", 5.00, quantity
            );
            break;
        }

        case 2:
        {
            // Добавляем мороженое.
            int quantity = readQuantity();

            addToCart(
                cart, "Ice Cream", 3.50, quantity
            );
            break;
        }

        case 0:
            // Возвращаемся к главному меню.
            std::cout << "Returning to main menu.\n";
            break;

        default:
            // Обрабатываем неправильный номер десерта.
            std::cout << "Invalid dessert selection.\n";
            break;
        }

        break;
    }

    default:
        // Обработка некорректного номера категории.
        std::cout << "Invalid category selection.\n";
        break;
    }
}

// ------------------------------------------------------------
// Функция просмотра текущей корзины.
//
// Выводит названия товаров, количество, цену за единицу
// и стоимость каждой позиции.
// ------------------------------------------------------------
void showCart(const std::vector<CartItem>& cart)
{
    std::cout << "\n========== YOUR CART ==========\n";

    if (cart.empty())
    {
        std::cout << "Your cart is empty.\n";
        return;
    }

    double total = 0.0;

    // Перебираем все позиции корзины.
    for (const CartItem& item : cart)
    {
        double itemTotal = item.price * item.quantity;

        std::cout << item.name
            << " | Quantity: " << item.quantity
            << " | Price: $" << std::fixed
            << std::setprecision(2) << item.price
            << " | Total: $" << itemTotal << '\n';

        total += itemTotal;
    }

    std::cout << "Subtotal: $" << std::fixed
        << std::setprecision(2) << total << '\n';

    std::cout << "===============================\n";
}

// ------------------------------------------------------------
// Функция формирования итогового чека.
//
// Пользователь выбирает тип скидки:
// 0 - без скидки;
// 1 - VIP-карта, скидка 10%;
// 2 - студенческая карта, скидка 5%.
//
// После выбора рассчитывается скидка и итоговая стоимость.
// ------------------------------------------------------------
void checkout(const std::vector<CartItem>& cart)
{
    // Нельзя оформить заказ с пустой корзиной.
    if (cart.empty())
    {
        std::cout
            << "Your cart is empty. Add products before checkout.\n";
        return;
    }

    // Рассчитываем первоначальную стоимость заказа.
    double subtotal = 0.0;

    for (const CartItem& item : cart)
    {
        subtotal += item.price * item.quantity;
    }

    // Проверяем возможность корректного расчёта суммы.
    if (!std::isfinite(subtotal))
    {
        std::cout
            << "Error: the order total is outside the valid range.\n";
        return;
    }

    // Выводим варианты скидок.
    std::cout << "\n========== CHECKOUT ==========\n";
    std::cout << "0. No discount\n";
    std::cout << "1. VIP card - 10% discount\n";
    std::cout << "2. Student card - 5% discount\n";

    int discountChoice;

    // Запрашиваем корректный код скидки.
    while (true)
    {
        discountChoice = readInt("Choose your discount: ");

        if (discountChoice >= 0 && discountChoice <= 2)
        {
            break;
        }

        std::cout
            << "Invalid choice. Enter 0, 1, or 2.\n";
    }

    double discountRate = 0.0;

    // Выбираем размер скидки с помощью switch.
    switch (discountChoice)
    {
    case 0:
        // Покупатель не использует скидочную карту.
        discountRate = 0.0;
        break;

    case 1:
        // VIP-карта предоставляет скидку 10%.
        discountRate = 0.10;
        break;

    case 2:
        // Студенческая карта предоставляет скидку 5%.
        discountRate = 0.05;
        break;

    default:
        // Защитная ветвь на случай изменения программы.
        std::cout << "Invalid discount selection.\n";
        return;
    }

    // Рассчитываем скидку и сумму к оплате.
    double discountAmount = subtotal * discountRate;
    double finalTotal = subtotal - discountAmount;

    // Печатаем чек.
    std::cout << "\n========== RECEIPT ==========\n";

    for (const CartItem& item : cart)
    {
        std::cout << std::left << std::setw(18) << item.name
            << " x" << item.quantity
            << " = $" << std::fixed
            << std::setprecision(2)
            << item.price * item.quantity << '\n';
    }

    std::cout << "------------------------------\n";
    std::cout << "Subtotal: $" << subtotal << '\n';

    std::cout << "Discount: "
        << discountRate * 100.0 << "%\n";

    std::cout << "Discount amount: $" << discountAmount << '\n';
    std::cout << "Final total: $" << finalTotal << '\n';

    std::cout << "==============================\n";
    std::cout << "Thank you for your purchase!\n";
}

// ------------------------------------------------------------
// Главная функция программы.
//
// Организует главное меню магазина и позволяет:
// 1. Выбирать категории товаров.
// 2. Просматривать корзину.
// 3. Завершать покупку.
// 0. Выходить из программы.
//
// Цикл обеспечивает возможность возвращаться в главное меню
// после выбора товара или просмотра корзины.
// ------------------------------------------------------------
int main()
{
    // Вектор хранит все выбранные товары.
    std::vector<CartItem> cart;

    // Переменная хранит выбор пользователя в главном меню.
    int menuChoice;

    std::cout << "================================\n";
    std::cout << "       WELCOME TO THE STORE\n";
    std::cout << "================================\n";

    // Повторяем главное меню, пока пользователь не выберет выход.
    while (true)
    {
        std::cout << "\n========== MAIN MENU ==========\n";
        std::cout << "1. Salads\n";
        std::cout << "2. Hot meals\n";
        std::cout << "3. Drinks\n";
        std::cout << "4. Desserts\n";
        std::cout << "5. View cart\n";
        std::cout << "6. Checkout\n";
        std::cout << "0. Exit\n";

        menuChoice = readInt("Choose an option: ");

        // Главный switch управляет переходами между разделами.
        switch (menuChoice)
        {
        case 1:
            // Переходим к подменю салатов.
            selectProduct(1, cart);
            break;

        case 2:
            // Переходим к подменю горячих блюд.
            selectProduct(2, cart);
            break;

        case 3:
            // Переходим к подменю напитков.
            selectProduct(3, cart);
            break;

        case 4:
            // Переходим к подменю десертов.
            selectProduct(4, cart);
            break;

        case 5:
            // Показываем содержимое корзины.
            showCart(cart);
            break;

        case 6:
            // Оформляем заказ и печатаем чек.
            checkout(cart);
            break;

        case 0:
            // Завершаем программу по запросу пользователя.
            std::cout << "Thank you for visiting our store!\n";
            return 0;

        default:
            // Обрабатываем неверный пункт главного меню.
            std::cout
                << "Invalid menu option. Please try again.\n";
            break;
        }
    }
}
