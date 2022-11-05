#include <bits/stdc++.h>

using namespace std;

int INF = INT_MAX;

int main()
{
    int h, w;
    cin >> h >> w;
    int num_nodes = w*h;
    char temp;

    vector<bool> grid(num_nodes, false);
    queue<pair<int, int>> q;
    vector<int> monsters(num_nodes, INF);
    int start;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> temp;
            if (temp != '#') grid[w*i + j] = true;
            if (temp == 'M'){
                q.push({w*i + j, 0});
                monsters[w*i + j] = 0;
            }
            if (temp == 'A') start = w*i + j;
        }
    }


    vector<vector<int>> neighbours(num_nodes);

    for (int n = 0; n < num_nodes; n++)
    {
        if (!grid[n]) continue;
        if (n - 1 > 0){
            if (grid[n - 1]) neighbours[n].push_back(n - 1);
        }
        if (n - w > 0){
            if (grid[n - w]) neighbours[n].push_back(n - w);
        }
        if (n + 1 < num_nodes){
            if (grid[n + 1]) neighbours[n].push_back(n + 1);
        }
        if (n + w < num_nodes){
            if (grid[n + w]) neighbours[n].push_back(n + w);
        }
    }

    int n_actual, dis;
    while (!q.empty())
    {
        tie(n_actual, dis) = q.front(); q.pop();
        for (auto n : neighbours[n_actual])
        {
            if (monsters[n] > dis+1) 
            {
                monsters[n] = dis+1;
                q.push({n, dis+1});
            }
        }
    }

    vector<pair<int, char>> father(num_nodes, {-1, 'X'});
    father[start] = {-2, 'X'};
    q.push({start, 0});
    bool done = false;
    int end;

    while(!q.empty() && !done)
    {
        tie(n_actual, dis) = q.front(); q.pop();

        if (n_actual % w == 0 || n_actual % w == w-1 || (n_actual >= 0 && n_actual < w) || (n_actual >= num_nodes-w && n_actual < num_nodes))
        {
            end = n_actual;
            done = true; break;
        }
        //cout << n_actual << " : ";
        for (auto n : neighbours[n_actual])
        {
            if (father[n].first == -1) 
            {
                if (dis+1 < monsters[n])
                {
                    father[n].first = n_actual;
                    if (n_actual + 1 == n) father[n].second = 'R';
                    if (n_actual - 1 == n) father[n].second = 'L';
                    if (n_actual + w == n) father[n].second = 'D';
                    if (n_actual - w == n) father[n].second = 'U';
                    q.push({n, dis+1});
                    //cout << n << "," << dis+1 << " ";
                } 
            }
        }
    }

    if (!done) cout << "NO";
    else
    {
        cout << "YES" << endl;
        vector<char> path;
        int i = end;
        while (father[i].first != -2)
        {
            path.push_back(father[i].second);
            i = father[i].first;
        }

        cout << path.size() << endl;
        reverse(path.begin(), path.end());
        for (auto c : path)
        {
            cout << c;
        }
    }
    // for (int n = 0; n < num_nodes; n++)
    // {
    //     cout << n << ": ";
    //     for (auto a : neighbours[n])
    //     {
    //         cout << a << " , ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //     {
    //         cout << monsters[w*i + j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << start;
}