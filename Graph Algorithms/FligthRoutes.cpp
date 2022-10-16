#include <bits/stdc++.h>

using namespace std;

#define INF LONG_LONG_MAX
#define ll long long

int main()
{
    long long num_nodes, num_paths, num_ret, a, b, c, dis;
    cin >> num_nodes >> num_paths >> num_ret;

    vector<vector<pair<ll, ll>>> path (num_nodes+1, vector<pair<ll, ll>>());
    vector<ll> ret;
    vector<ll> num_visits (num_nodes+1, 0);
    priority_queue<pair<ll, ll>> queue;

    for (int p = 0; p < num_paths; p++)
    {
        cin >> a >> b >> c;
        path[a].push_back({b, c});
    }

    queue.push({0, 1});
 
    while (!queue.empty())
    {
        tie(dis, a) = queue.top(); queue.pop();
        if (a == num_nodes) 
        {
            ret.push_back(-dis);
            if (ret.size() == num_ret) break;
        }
        if (num_visits[a] > 10) continue;
        num_visits[a]++;
        for (auto u : path[a])
        {
            tie(b, c) = u;
            if (num_visits[b] < 10)
            {
                queue.push({dis - c, b});
            }
        }
    }

    for (auto r : ret)
    {
        cout << r << " ";
    }


}