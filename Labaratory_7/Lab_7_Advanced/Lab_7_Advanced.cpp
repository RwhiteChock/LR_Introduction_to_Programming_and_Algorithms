#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int ROWS = 5;
    const int COLUMNS = 5;

    // Создаём массив с дополнительной строкой
    int matrix[ROWS + 1][COLUMNS];

    srand(time(0));

    // Заполнение первых пяти строк случайными числами
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            matrix[i][j] = rand() % 100 + 1;
        }
    }

    // Вывод исходной матрицы
    cout << "Original matrix:" << endl;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Ввод новой строки
    cout << "\nEnter 5 elements for the new row:" << endl;

    for (int j = 0; j < COLUMNS; j++)
    {
        cin >> matrix[ROWS][j];
    }

    // Вывод матрицы с новой строкой
    cout << "\nMatrix after adding a row:" << endl;

    for (int i = 0; i < ROWS + 1; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}