#include<bits/stdc++.h>

using namespace std;

#define INF LONG_LONG_MAX

int main()
{    
    long long num_nodes, num_paths, a, b, cost;
    cin >> num_nodes >> num_paths;

    vector<vector<pair<long long, long long>>> path (num_nodes+1, vector<pair<long long, long long>>() );
    vector<long long> distance (num_nodes+1, INF);
    priority_queue<pair<long long, long long>> queue;
    vector<bool> processed (num_nodes+1, false);

    distance[1] = 0;

    for (int c = 0; c < num_paths; c++)
    {
        cin >> a >> b >> cost;
        path[a].push_back({b, cost});
    }

    queue.push({0, 1});

    while(!queue.empty())
    {
        a = queue.top().second; queue.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : path[a])
        {
            tie(b, cost) = u;
            if (distance[a] + cost < distance[b])
            {
                distance[b] = distance[a] + cost;
                queue.push({-distance[b], b});
            }
        }
    }

    for (int b = 1; b < distance.size(); b++){
        cout << distance[b] << " "; 
    }







}