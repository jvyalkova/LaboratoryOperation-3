#include <iostream>
#include <vector>
#include <string>

using namespace std;

string findMaxCommonSubsequence(string s1, string s2) 
{
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; ++i)
    {
        for (int j = 1; j <= n2; ++j) 
        {
            if (s1[i - 1] == s2[j - 1]) 
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else 
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string result;
    int i = n1, j = n2;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            result = s1[i - 1] + result;
            --i;
            --j;
        }
        else {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                --j;
            }
            else 
            {
                --i;
            }
        }
    }

    return result;
}

int main() 
{
    setlocale(LC_ALL, "RUS");
    string s1, s2;
    cout << "������ ������� ��������: ";
    cin >> s1;
    cout << "������ ������� ��������: ";
    cin >> s2;

    string maxCommonSubsequence = findMaxCommonSubsequence(s1, s2);

    cout << "����������� ����������� ����� ����������: " << maxCommonSubsequence << endl;

    return 0;
}