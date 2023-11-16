#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RUS");
    int size;
    cout << "Введите размер треугольника: ";
    cin >> size;

    vector<vector<int>> triangle(size, vector<int>(size));

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j <= i; j++)
        {
            triangle[i][j] = rand() % 100; 
        }
    }

    cout << "Треугольник:\n";
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> path;
    int maxSum = triangle[0][0];
    int maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (triangle[i][maxIndex] < triangle[i][maxIndex + 1]) 
        {
            maxIndex++;
        }

        maxSum += triangle[i][maxIndex];
        path.push_back(maxIndex);
    }

    cout << "Максимальная сумма: " << maxSum << endl;
    cout << "Путь: ";
    for (int i = 0; i < path.size(); i++) 
    {
        cout << "(" << i << ", " << path[i] << ") ";
    }
    cout << endl;

    return 0;
}
