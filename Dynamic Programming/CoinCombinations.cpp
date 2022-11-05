#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;

int main()
{
    int num_coins, sum, coin;
    cin >> num_coins >> sum;
    vector<int> coins(num_coins);
    for (int c = 0; c < num_coins; c++)
    {
        cin >> coins[c]; 
    }
    sort(coins.begin(), coins.end());

    vector<int> dp (sum+1, 0);
    dp[0] = 1;
    for (int x = 1; x < sum + 1; x++)
    {
        for (int c = 0; c < coins.size(); c++)
        {
            if (x - coins[c] >= 0) dp[x] = (dp[x] + dp[x-coins[c]]) % MOD;
            else break;
        }
    }

    cout << dp[sum];
}