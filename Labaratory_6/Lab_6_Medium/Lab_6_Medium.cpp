#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Задаём размер массива
    const int SIZE = 15;

    // Объявляем массив
    int arr[SIZE];

    // Запускаем генератор случайных чисел
    srand(time(nullptr));

    // Заполняем массив случайными числами от 0 до 100
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 101;
    }

    // Выводим исходный массив в виде таблицы
    cout << "Original array:" << endl;
    cout << "Index    Value" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(5) << i << setw(9) << arr[i] << endl;
    }

    // Объявляем переменные для вычислений
    int sum = 0;
    int minElement = arr[0];
    int maxElement = arr[0];

    // Находим сумму, минимум и максимум
    for (int i = 0; i < SIZE; i++)
    {
        // Добавляем текущий элемент к сумме
        sum += arr[i];

        // Проверяем, является ли элемент минимальным
        if (arr[i] < minElement)
        {
            minElement = arr[i];
        }

        // Проверяем, является ли элемент максимальным
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }

    // Вычисляем среднее арифметическое
    double average = (double)sum / SIZE;

    // Считаем количество максимальных элементов
    int countMax = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] == maxElement)
        {
            countMax++;
        }
    }

    // Выводим результаты вычислений
    cout << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Minimum: " << minElement << endl;
    cout << "Maximum: " << maxElement << endl;
    cout << "Number of maximum elements: " << countMax << endl;

    return 0;
}