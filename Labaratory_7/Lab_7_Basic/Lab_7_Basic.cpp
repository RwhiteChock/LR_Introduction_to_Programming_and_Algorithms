#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 4;
    int matrix[SIZE][SIZE];

    // Ввод элементов матрицы
    cout << "Enter matrix elements:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Вывод исходной матрицы
    cout << "Original matrix:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Вывод элементов выше главной диагонали
    cout << "Elements above the main diagonal:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            cout << matrix[i][j] << " ";
        }
    }

    cout << endl;

    return 0;
}