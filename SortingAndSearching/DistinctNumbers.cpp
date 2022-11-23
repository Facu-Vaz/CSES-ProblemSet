#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int x;
    int count = 0;
    vector<bool> unique (1000000001, false);
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (!unique[x]) 
        {
            count++;
            unique[x] = true;
        }
    }

    cout << count;
}