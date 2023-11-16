#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxPath(vector<vector<int>>& triangle)
{
    int n = triangle.size();

    // Creating a copy of the triangle to store intermediate results
    vector<vector<int>> dp(triangle);

    // We pass through the triangle from the bottom up, starting from the second row
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            // Select the maximum value from three adjacent elements in the next row
            dp[i][j] += max(dp[i + 1][j], max(dp[i + 1][j + 1], dp[i + 1][j + 2]));
        }
    }

    // Return the maximum load value at the vertex of the triangle
    return dp[0][0];
}

vector<int> findOptimalPath(vector<vector<int>>& triangle)
{
    int n = triangle.size();

    // Creating a copy of the triangle to store intermediate results
    vector<vector<int>> dp(triangle);

    // We pass through the triangle from the bottom up, starting from the second row
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            // Select the maximum value from three adjacent elements in the next row
            dp[i][j] += max(dp[i + 1][j], max(dp[i + 1][j + 1], dp[i + 1][j + 2]));
        }
    }

    // Restoring the optimal path
    vector<int> path;
    int row = 0, col = 0;
    path.push_back(triangle[row][col]);

    while (row < n - 1)
    {
        if (dp[row + 1][col] > dp[row + 1][col + 1])
        {
            row++;
        }
        else if (dp[row + 1][col + 1] > dp[row + 1][col + 2])
        {
            row++;
            col++;
        }
        else
        {
            row++;
            col += 2;
        }
        path.push_back(triangle[row][col]);
    }

    return path;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    // Opening the file for reading
    ifstream inputFile("triangle.txt");
    if (!inputFile)
    {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    // Reading a triangle from a file
    vector<vector<int>> triangle;
    int num;
    while (inputFile >> num)
    {
        vector<int> row;
        for (int i = 0; i < num; i++)
        {
            int value;
            inputFile >> value;
            row.push_back(value);
        }
        triangle.push_back(row);
    }

    inputFile.close();

    int maxSum = findMaxPath(triangle);
    vector<int> optimalPath = findOptimalPath(triangle);

    cout << "Максимальное суммарное значение нагрузок: " << maxSum << endl;
    cout << "Оптимальный путь: " << " ";
    for (int i = 0; i < optimalPath.size(); i++)
    {
        cout << optimalPath[i] << " ";
    }
    cout << endl;

    return 0;
}