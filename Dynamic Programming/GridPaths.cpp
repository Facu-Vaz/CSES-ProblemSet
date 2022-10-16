#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    vector<bool> is_trap(n*n, false);
    vector<int> dinamica(n*n, 0);

    dinamica[0] = 1;
    char temp;

    for (int i = 0; i < n*n; i++)
    {
        cin >> temp;
        if (temp == '*')
        {
            if (i == 0) 
            {
                dinamica[0] = 0;
                break;
            }
            continue;
        }
        if (i >= n)
        {
            dinamica[i] = (dinamica[i-n]  + dinamica[i]) % MOD;
        }
        if (i % n != 0)
        {
            dinamica[i] = (dinamica[i-1] + dinamica[i]) % MOD;
        }
        //cout << dinamica[i] << endl;
    }

    cout << dinamica[n*n - 1];

}