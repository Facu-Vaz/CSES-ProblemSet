#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("playlist.in");
    int N, x;
    cin >> N;
    int len = 1;
    int max_size = 1;
    int a = 0;
    bool done;
    vector<int> number_list(N, 0);
    vector<bool> is(1000000001, false);

    cin >> number_list[0];
    is[number_list[0]] = true;

    for (int b = 1; b < N; b++)
    {
        cin >> number_list[b];
        cout << number_list[b];
        cout << endl;
        if (!is[number_list[b]])
        {
            len += 1;
            cout << "AAA" << endl;
            is[number_list[b]] = true;
        }
        else
        {
            done = false;
            while (a != b && !done)
            {
                if (number_list[a] != number_list[b])
                {
                    is[a] = false;
                    len--; 
                    a++;
                }
                else done = true;
            }
        }
        max_size = max(max_size, len);
    }

    cout << max_size << endl;
    //for (auto a : num) cout << a << endl;
}