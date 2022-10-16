#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;

int main (){
    int num_coins, desired_sum;
    cin >> num_coins >> desired_sum;

    vector<int> dinamica(desired_sum+1, 0);
    int coin;

    dinamica[0] = 1;

    for (int c = 0; c < num_coins; c++){
        cin >> coin;
        for (int i = 1; i <= desired_sum; i++)
        {
            if (i-coin >= 0) {
                dinamica[i] = (dinamica[i-coin] + dinamica[i]) % MOD;
            }
        }
    }

    cout << dinamica[desired_sum];


}