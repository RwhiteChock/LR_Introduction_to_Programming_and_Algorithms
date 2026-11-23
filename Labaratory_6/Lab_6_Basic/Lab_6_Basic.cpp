#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Задаём размер массива
    const int SIZE = 10;

    // Объявляем массив из 10 целых чисел
    int arr[SIZE];

    // Инициализируем генератор случайных чисел
    srand(time(nullptr));

    // Заполняем массив случайными числами от 10 до 99
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = 10 + rand() % 90;
    }

    // Выводим все элементы массива
    cout << "Array: ";

    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Создаём счётчик элементов больше 50
    int count = 0;

    // Проверяем каждый элемент массива
    for (int i = 0; i < SIZE; i++)
    {
        // Если элемент больше 50, увеличиваем счётчик
        if (arr[i] > 50)
        {
            count++;
        }
    }

    // Выводим количество найденных элементов
    cout << "Number of elements greater than 50: " << count << endl;

    return 0;
}