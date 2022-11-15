#include <bits/stdc++.h>

using namespace std;

vector<int> group;
vector<vector<int>> conexions;
int actual_group;

void dfs(int x)
{
    group[x] = actual_group;
    for (auto v : conexions[x])
    {
        if (group[v] == 0) dfs(v);
    }
}


int main()
{
    int N, num_conexiones;
    cin >> N >> num_conexiones;

    group.resize(N+1, 0);
    conexions.resize(N+1);

    int a, b;
    for (int i = 0; i < num_conexiones; i++)
    {
        cin >> a >> b;
        conexions[a].push_back(b);
        conexions[b].push_back(a);
    } 

    for (int i = 1; i <= N; i++)
    {
        actual_group = i;
        if (group[i] == 0) dfs(i);
    } 

    vector<pair<int, int>> ret;
    int base_group = 1;
    vector<int> group_done (N+1, false);
    group_done[1] = true;
    for (int i = 2; i <= N; i++)
    {
        if (group_done[group[i]]) continue;
        ret.push_back({1, i});
        group_done[group[i]] = true;
    } 

    cout << ret.size() << endl;
    for (auto r : ret)
    {
        cout << r.first << " " << r.second << endl;
    }


}