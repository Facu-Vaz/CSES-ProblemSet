#include <bits/stdc++.h>

using namespace std;


int MOD = 1e9 + 7;

int main ()
{
    int num_coins, desired_sum;
    cin >> num_coins >> desired_sum;

    vector<int> dinamica(desired_sum+1, 0);
    vector<int> coins(num_coins, 0);

    for (int c = 0; c < num_coins; c++)
    {
        cin >> coins[c];
    }
    
    sort(coins.begin(), coins.end());

    dinamica[0] = 1;

    for (int i = 1; i <= desired_sum; i++)
    {
        for (int c = 0; c < coins.size(); c++)
        {
            if (i - coins[c] >= 0)
            {  
                dinamica[i] = (dinamica[i-coins[c]]  + dinamica[i]) % MOD;
            }
            else
            {
                continue;
            }
        }
    }

    cout << dinamica[desired_sum];
}