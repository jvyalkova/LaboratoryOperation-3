#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MaxN = 1000;
int Op[MaxN];

void Solve(int N) 
{
    int i, j;
    Op[1] = 0;

    for (i = 2; i <= N; i++) 
    {
        Op[i] = Op[i - 1] + 1;

        for (j = 2; j <= i - 1; j++) 
        {
            Op[i] = min(Op[i], Op[j] + Op[i - j] + 1);

            if (i % j == 0) 
            {
                Op[i] = min(Op[i], Op[i / j] + j - 1);
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int N;

    cout << "Введите степень числа: ";
    cin >> N;

    Solve(N);

    cout << "Оптимальное количество операций: " << Op[N] << endl;

    vector<int> sequence;
    int i = N;

    while (i > 1)
    {
        sequence.push_back(i);
        int j = 2;

        while (i % j != 0)
        {
            j++;
        }

        if (i % j == 0)
        {
            i /= j;
        }
    }

    sequence.push_back(1);

    reverse(sequence.begin(), sequence.end());

    cout << "Последовательность операций: ";
    for (int num : sequence)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}