#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int SIZE = 3;
    int matrix[SIZE][SIZE];

    srand(time(0));

    // Заполнение матрицы случайными числами
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = rand() % 100 + 1;
        }
    }

    // Вывод матрицы
    cout << "Matrix:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int rowSum[SIZE] = { 0 };
    int columnSum[SIZE] = { 0 };
    int mainDiagonal = 0;
    int secondaryDiagonal = 0;

    // Вычисление сумм строк, столбцов и диагоналей
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            rowSum[i] += matrix[i][j];
            columnSum[j] += matrix[i][j];

            if (i == j)
            {
                mainDiagonal += matrix[i][j];
            }

            if (i + j == SIZE - 1)
            {
                secondaryDiagonal += matrix[i][j];
            }
        }
    }

    // Вывод сумм строк
    cout << "\nRow sums:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << rowSum[i] << " ";
    }

    // Вывод сумм столбцов
    cout << "\nColumn sums:" << endl;

    for (int j = 0; j < SIZE; j++)
    {
        cout << columnSum[j] << " ";
    }

    cout << "\nMain diagonal sum: " << mainDiagonal << endl;
    cout << "Secondary diagonal sum: " << secondaryDiagonal << endl;

    // Проверка магического квадрата
    bool isMagic = true;

    for (int i = 0; i < SIZE; i++)
    {
        if (rowSum[i] != rowSum[0] ||
            columnSum[i] != rowSum[0])
        {
            isMagic = false;
        }
    }

    if (mainDiagonal != rowSum[0] ||
        secondaryDiagonal != rowSum[0])
    {
        isMagic = false;
    }

    if (isMagic == true)
    {
        cout << "\nThe matrix is a magic square." << endl;
    }
    else
    {
        cout << "\nThe matrix is not a magic square." << endl;
    }

    return 0;
}