#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int maxWeight;
    vector<int> weights;
    vector<int> utilities;

    // Reading data from a file
    ifstream inputFile("backpack.txt");
    if (!inputFile)
    {
        cout << "Îøèáêà ÷òåíèÿ ôàéëà." << endl;
        return 0;
    }

    inputFile >> maxWeight;
    int weight, utility;
    while (inputFile >> weight >> utility)
    {
        weights.push_back(weight);
        utilities.push_back(utility);
    }
    inputFile.close();

    int n = weights.size();

    // Creating a table to store maximum utility
    vector<vector<int>> table(n + 1, vector<int>(maxWeight + 1, 0));

    // Filling in the table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= maxWeight; w++)
        {
            if (weights[i - 1] <= w)
            {
                table[i][w] = max(table[i - 1][w], utilities[i - 1] + table[i - 1][w - weights[i - 1]]);
            }
            else {
                table[i][w] = table[i - 1][w];
            }
        }
    }

    // Determining the items to put in the backpack
    vector<int> chosenItems;
    int w = maxWeight;
    for (int i = n; i > 0; i--)
    {
        if (table[i][w] != table[i - 1][w])
        {
            chosenItems.push_back(i);
            w -= weights[i - 1];
        }
    }

    // Output of results
    cout << "Максимально возможная суммарная полезность: " << table[n][maxWeight] << endl;
    cout << "Номера предметов, которые необходимо положить в рюкзак: ";
    for (int i = chosenItems.size() - 1; i >= 0; i--) {
        cout << chosenItems[i] << " ";
    }
    cout << endl;

    return 0;
}
