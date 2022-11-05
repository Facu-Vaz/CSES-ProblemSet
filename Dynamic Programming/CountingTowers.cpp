#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;

int main()
{
    int n;
    int m = 0;
    cin >> n;

    vector<int> q (n);
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
        m = max(m, q[i]);
    }
    // for (auto a : q)
    // {
    //     cout << a << " ";
    // }

    vector<int> compatible = {-1, 0, 0, 1, 0, 0, 0, 1, 1};

    // vector<vector<int>> compatible = {
    //     {},
    //     {1, 3, 4, 5, 6},        
    //     {1, 3, 4, 5, 6},
    //     {2, 7, 8},
    //     {1, 3, 4, 5, 6},
    //     {1, 3, 4, 5, 6},
    //     {1, 3, 4, 5, 6},
    //     {2, 7, 8},
    //     {2, 7, 8},
    // };

    vector<vector<int>> dp (m+1, vector<int> (8+1));

    for (int i = 1; i < 9; i++){
        dp[2][i] = 1;
    }

    for (int h = 3; h <= m; h++)
    {
        for (int t = 1; t <= 8; t++)
        {
            if (compatible[t] == 0) dp[h][t] = ((((dp[h-1][1] + dp[h-1][3]) % MOD + dp[h-1][4]) % MOD + dp[h-1][5]) % MOD + dp[h-1][6]) % MOD;
            else dp[h][t] = ((dp[h-1][2] + dp[h-1][7]) % MOD + dp[h-1][8]) % MOD;
        }
    }

    int sum;
    for (int r = 0; r < q.size(); r++)
    {
        if (q[r] == 1){
            cout << 2 << endl;
            continue;
        }
        
        sum = 0;
        for (int t = 1; t <= 8; t++)
        {
            sum = (sum + dp[q[r]][t]) % MOD;
        }
        cout << sum << endl;
    }


    // for (auto a : dp)
    // {
    //     for (auto b : a)
    //     {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
        
        


}