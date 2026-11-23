#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // Размер массива
    const int SIZE = 20;

    // Проверка, что массив не пустой
    if (SIZE <= 0)
    {
        cout << "Array is empty" << endl;
        return 1;
    }

    int arr[SIZE];

    // Инициализация генератора случайных чисел
    srand(time(nullptr));

    // Заполнение массива числами от 1 до 100
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = 1 + rand() % 100;
    }

    // Вывод исходного массива
    cout << "Original array:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(4) << arr[i];
    }

    cout << endl << endl;

    // Сортировка массива пузырьком
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - 1 - i; j++)
        {
            // Если текущий элемент больше следующего,
            // меняем их местами
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Вывод отсортированного массива
    cout << "Sorted array:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(4) << arr[i];
    }

    cout << endl << endl;

    // Вычисление медианы
    double median = (arr[SIZE / 2 - 1] + arr[SIZE / 2]) / 2.0;

    cout << "Median: " << median << endl;

    return 0;
}