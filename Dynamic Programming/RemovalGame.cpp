#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    long long sum = 0;

    vector<long long> list (N);
    vector<vector<long long>> dp (N, vector<long long> (N, 0));

    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
        dp[i][i] = list[i];
        sum += list[i];
    }

    // for (auto a: dp)
    // {
    //     for (auto b : a) cout << b << " ";
    //     cout << endl;
    // }
    // cout << endl;


    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j+i < N; j++)
        {
            dp[j][j+i] = max(list[j] - dp[j+1][j+i], list[j+i]- dp[j][j+i-1]);
        }
    }

    long long ret = ((sum - dp[0][N-1]) / 2) + dp[0][N-1];

    cout << ret << endl;

    // for (auto a: dp)
    // {
    //     for (auto b : a) cout << b << " ";
    //     cout << endl;
    // }

}