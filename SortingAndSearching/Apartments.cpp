#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> aplicant (N);
    vector<int> apartment (M);

    for (int i = 0; i < N; i++) cin >> aplicant[i];
    for (int i = 0; i < M; i++) cin >> apartment[i];

    sort(aplicant.begin(), aplicant.end());
    sort(apartment.begin(), apartment.end());

    int n_point = 0;
    int m_point = 0;
    int count = 0;

    while (n_point < N && m_point < M)
    {
        if (apartment[m_point] < aplicant[n_point] - K) m_point++;
        else if (apartment[m_point] > aplicant[n_point] + K) n_point++;
        else {
            n_point++;
            m_point++;
            count++;
        }
    }

    cout << count;

}