
#include <iostream>  // Для ввода и вывода данных
#include <iomanip>   // Для красивого вывода цен
#include <limits>    // Для очистки потока ввода
#include <string>    // Для работы с названиями товаров
#include <vector>    // Для хранения товаров в корзине

using namespace std;

// Создаём структуру для хранения информации об одном товаре.
// У каждого товара есть название, цена и количество.
struct CartItem
{
    string name;
    double price;
    int quantity;
};

// Функция для ввода целого числа.
// Если пользователь введёт буквы вместо числа,
// программа очистит ошибку и попросит ввести число ещё раз.
int readInt()
{
    int number;

    // Цикл повторяется, пока пользователь не введёт целое число.
    while (!(cin >> number))
    {
        // Сбрасываем ошибку ввода.
        cin.clear();

        // Удаляем неправильные символы из строки ввода.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input! Enter a number: ";
    }

    return number;
}

// Функция добавления товара в корзину.
// Передаём название, цену и количество товара.
void addToCart(vector<CartItem>& cart, string name,
               double price, int quantity)
{
    // Добавляем новый товар в конец корзины.
    cart.push_back({name, price, quantity});

    cout << "Product added to cart!" << endl;
}

// Функция для ввода количества товара.
// Количество должно быть положительным числом.
int readQuantity()
{
    int quantity;

    // Повторяем запрос, если введено неправильное количество.
    do
    {
        cout << "Enter quantity: ";
        quantity = readInt();

        if (quantity <= 0)
        {
            cout << "Quantity must be positive!" << endl;
        }

    } while (quantity <= 0);

    return quantity;
}

// Функция выбора конкретного товара.
// category показывает, какую категорию выбрал пользователь.
// cart — корзина, куда добавляются выбранные товары.
void selectProduct(int category, vector<CartItem>& cart)
{
    int choice;
    int quantity;

    // Первый switch выбирает категорию товаров.
    switch (category)
    {
    case 1:
        // Категория салатов.
        cout << "\n--- SALADS ---\n";
        cout << "1. Caesar Salad - $8.50\n";
        cout << "2. Greek Salad - $7.00\n";
        cout << "0. Back\n";

        cin >> choice;

        // Второй switch выбирает конкретный салат.
        switch (choice)
        {
        case 1:
            // Если выбран салат Цезарь,
            // запрашиваем количество и добавляем его в корзину.
            quantity = readQuantity();
            addToCart(cart, "Caesar Salad", 8.50, quantity);
            break;

        case 2:
            // Если выбран греческий салат,
            // также запрашиваем количество.
            quantity = readQuantity();
            addToCart(cart, "Greek Salad", 7.00, quantity);
            break;

        case 0:
            // Возвращаемся в главное меню.
            break;

        default:
            // Если введён неправильный номер.
            cout << "Invalid choice!" << endl;
        }
        break;

    case 2:
        // Категория горячих блюд.
        cout << "\n--- HOT MEALS ---\n";
        cout << "1. Chicken Steak - $12.00\n";
        cout << "2. Pasta - $9.50\n";
        cout << "0. Back\n";

        cin >> choice;

        // Выбираем конкретное горячее блюдо.
        switch (choice)
        {
        case 1:
            quantity = readQuantity();
            addToCart(cart, "Chicken Steak", 12.00, quantity);
            break;

        case 2:
            quantity = readQuantity();
            addToCart(cart, "Pasta", 9.50, quantity);
            break;

        case 0:
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
        break;

    case 3:
        // Категория напитков.
        cout << "\n--- DRINKS ---\n";
        cout << "1. Water - $1.50\n";
        cout << "2. Orange Juice - $3.00\n";
        cout << "0. Back\n";

        cin >> choice;

        // Выбираем конкретный напиток.
        switch (choice)
        {
        case 1:
            quantity = readQuantity();
            addToCart(cart, "Water", 1.50, quantity);
            break;

        case 2:
            quantity = readQuantity();
            addToCart(cart, "Orange Juice", 3.00, quantity);
            break;

        case 0:
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
        break;

    case 4:
        // Категория десертов.
        cout << "\n--- DESSERTS ---\n";
        cout << "1. Cheesecake - $5.00\n";
        cout << "2. Ice Cream - $3.50\n";
        cout << "0. Back\n";

        cin >> choice;

        // Выбираем конкретный десерт.
        switch (choice)
        {
        case 1:
            quantity = readQuantity();
            addToCart(cart, "Cheesecake", 5.00, quantity);
            break;

        case 2:
            quantity = readQuantity();
            addToCart(cart, "Ice Cream", 3.50, quantity);
            break;

        case 0:
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
        break;

    default:
        cout << "Invalid category!" << endl;
    }
}

// Функция просмотра корзины.
// Показывает все товары, их количество и стоимость.
void showCart(const vector<CartItem>& cart)
{
    double total = 0;

    cout << "\n========== YOUR CART ==========\n";

    // Проверяем, есть ли товары в корзине.
    if (cart.empty())
    {
        cout << "Your cart is empty!" << endl;
        return;
    }

    // Перебираем все товары в корзине.
    for (const CartItem& item : cart)
    {
        // Считаем стоимость конкретного товара.
        double itemTotal = item.price * item.quantity;

        // Выводим информацию о товаре.
        cout << item.name
             << " | Quantity: " << item.quantity
             << " | Price: $" << fixed << setprecision(2)
             << item.price
             << " | Total: $" << itemTotal << endl;

        // Добавляем стоимость товара к общей сумме.
        total += itemTotal;
    }

    // Показываем общую стоимость корзины.
    cout << "Total: $" << total << endl;
}

// Функция оформления покупки и расчёта скидки.
void checkout(const vector<CartItem>& cart)
{
    // Нельзя оформить покупку с пустой корзиной.
    if (cart.empty())
    {
        cout << "Your cart is empty!" << endl;
        return;
    }

    // Считаем первоначальную стоимость всех товаров.
    double subtotal = 0;

    for (const CartItem& item : cart)
    {
        subtotal += item.price * item.quantity;
    }

    // Проверяем, что сумма заказа положительная.
    if (subtotal <= 0)
    {
        cout << "Invalid order total!" << endl;
        return;
    }

    int choice;

    // Выводим варианты скидок.
    cout << "\n========== CHECKOUT ==========\n";
    cout << "0. No discount\n";
    cout << "1. VIP card - 10%\n";
    cout << "2. Student card - 5%\n";

    // Проверяем правильность выбора скидки.
    do
    {
        cout << "Choose discount: ";
        choice = readInt();

        if (choice < 0 || choice > 2)
        {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice < 0 || choice > 2);

    // Переменная для хранения размера скидки.
    double discount = 0;

    // Определяем размер скидки с помощью switch.
    switch (choice)
    {
    case 0:
        discount = 0;
        break;

    case 1:
        discount = 10;
        break;

    case 2:
        discount = 5;
        break;
    }

    // Рассчитываем сумму скидки.
    double discountAmount = subtotal * discount / 100;

    // Вычитаем скидку из первоначальной стоимости.
    double finalTotal = subtotal - discountAmount;

    // Формируем итоговый чек.
    cout << "\n========== RECEIPT ==========\n";

    for (const CartItem& item : cart)
    {
        cout << item.name << " x " << item.quantity
             << " = $" << item.price * item.quantity << endl;
    }

    // Выводим итоговую информацию о покупке.
    cout << "-----------------------------\n";
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Discount: " << discount << "%\n";
    cout << "Discount amount: $" << discountAmount << endl;
    cout << "Final total: $" << finalTotal << endl;
    cout << "=============================\n";
    cout << "Thank you for your purchase!\n";
}

// Главная функция программы.
// Здесь находится главное меню магазина.
int main()
{
    // Создаём пустую корзину для товаров.
    vector<CartItem> cart;

    int choice;

    // Главное меню повторяется, пока пользователь не выберет 0.
    do
    {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Salads\n";
        cout << "2. Hot meals\n";
        cout << "3. Drinks\n";
        cout << "4. Desserts\n";
        cout << "5. View cart\n";
        cout << "6. Checkout\n";
        cout << "0. Exit\n";

        cout << "Choose an option: ";
        choice = readInt();

        // Обрабатываем выбор пользователя.
        switch (choice)
        {
        case 1:
        case 2:
        case 3:
        case 4:
            // Передаём номер категории в функцию выбора товара.
            selectProduct(choice, cart);
            break;

        case 5:
            // Показываем содержимое корзины.
            showCart(cart);
            break;

        case 6:
            // Оформляем покупку и рассчитываем скидку.
            checkout(cart);
            break;

        case 0:
            // Завершаем работу программы.
            cout << "Thank you for visiting our store!\n";
            break;

        default:
            // Обрабатываем неправильный выбор.
            cout << "Invalid menu option!\n";
        }

    } while (choice != 0);

    return 0;
}
