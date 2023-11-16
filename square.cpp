#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Введите размер матрицы: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            matrix[i][j] = rand() % 10 + 1; // Генерация случайных значений от 1 до 10
        }
    }
    cout << "Матрица нагрузок:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    vector<vector<int>> gg(n, vector<int>(n));
    vector<vector<char>> path(n, vector<char>(n));

    gg[0][0] = matrix[0][0];

    // Заполняем первую строку
    for (int j = 1; j < n; j++)
    {
        gg[0][j] = gg[0][j - 1] + matrix[0][j];
        path[0][j] = 'L';
    }

    // Заполняем первый столбец
    for (int i = 1; i < n; i++) 
    {
        gg[i][0] = gg[i - 1][0] + matrix[i][0];
        path[i][0] = 'U';
    }

    // Заполняем остальные ячейки
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int left = gg[i][j - 1] + matrix[i][j];
            int up = gg[i - 1][j] + matrix[i][j];
            if (left < up)
            {
                gg[i][j] = left;
                path[i][j] = 'L';
            }
            else {
                gg[i][j] = up;
                path[i][j] = 'U';
            }
        }
    }

    cout << "Минимальное суммарное значение нагрузок: " << gg[n - 1][n - 1] << endl;

    cout << "Оптимальный путь: ";
    int i = n - 1, j = n - 1;
    while (i > 0 || j > 0)
    {
        cout << "(" << i << "," << j << ")";
        if (path[i][j] == 'L') 
        {
            j--;
        }
        else {
            i--;
        }
        if (i > 0 || j > 0) 
        {
            cout << "  ";
        }
    }

    cout << endl;

    return 0;
}