#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;

int main()
{
    int n, highest, actual;
    cin >> n >> highest;
    vector<int> original(n+1, 0);
    vector<vector<int>> dp (highest+1, vector<int> (n+1, 0));
    cin >> actual;
    if (actual != 0) dp[actual][1] = 1;
    else 
    {
        for (int i = 1; i <= highest; i++) dp[i][1] = 1;
    }
    for (int k = 2; k <= n; k++)
    {
        cin >> actual;
        if (actual != 0)
        {
            for (int l = 1; l <= highest; l++)
            {
                dp[actual][k] = dp[actual][k-1];
                if (actual-1 > 0) dp[actual][k] =  (dp[actual][k] + dp[actual-1][k-1]) % MOD;
                if (actual+1 <= highest) dp[actual][k] = (dp[actual][k] + dp[actual+1][k-1]) % MOD;
            }
        } 
        else 
        {
            for (int l = 1; l <= highest; l++)
            {
                dp[l][k] = dp[l][k-1];
                if (l-1 > 0) dp[l][k] =  (dp[l][k] + dp[l-1][k-1]) % MOD;
                if (l+1 <= highest) dp[l][k] = (dp[l][k] + dp[l+1][k-1]) % MOD;
            }
        }
    }

    int ret = 0;
    for (int l = 1; l <= highest; l++)
    {
        ret = (ret + dp[l][n]) % MOD;
    }
    cout << ret;
}