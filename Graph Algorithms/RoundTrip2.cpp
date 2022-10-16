#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> path;
vector<bool> visited;
vector<bool> cycle_flag;
stack<int> recursion;
bool posible = false;
int num_nodes, num_paths, a, b;


bool dfs(int node)
{
    //cout << node << endl;
    visited[node] = true;
    recursion.push(node);
    cycle_flag[node] = true;
    for (auto n : path[node])
    {
        if (!visited[n])
        {
            if(dfs(n)) 
                return true;
        }
        if (cycle_flag[n])
        {
            recursion.push(n);
            return true;
        }
    }
    recursion.pop();
    cycle_flag[node] = false;
    return false;

}

void visit_all()
{
    for (int n = 1; n <= num_nodes; n++)
    {
        if (!visited[n])
        {
            if(dfs(n))
                break;
        }
    }
}

int main()
{    
    cin >> num_nodes >> num_paths;
    
    path.resize(num_nodes+1, vector<int> ());
    cycle_flag.resize(num_nodes+1, false);
    visited.resize(num_nodes+1, false);


    for (int p = 0; p < num_paths; p++)
    {
        cin >> a >> b;
        path[a].push_back(b);
    }

    visit_all();

    if (recursion.size() == 0)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> ret;
    int start = recursion.top();
    while (!recursion.empty())
    {
        ret.push_back(recursion.top());
        recursion.pop();
        if (ret.back() == start and ret.size() != 1)
            break;
    }
    reverse(ret.begin(), ret.end());

    cout << ret.size() << endl;
    for (auto r : ret)
    {
        cout << r << " ";
    }



}