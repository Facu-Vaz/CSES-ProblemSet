#include <bits/stdc++.h>

using namespace std;

vector<int> ret;

int main()
{
    int N;
    int steps = 1;
    cin >> N;
    int n = N;

    while (n > 1){
        n /= 2;
        steps++;
    }
    steps++;

        // cout << steps << endl << endl;
    
    vector<vector<int>> rondas (steps+1);
    for (int i = 1; i <= N; i++) rondas[0].push_back(i);

        // for (auto a : rondas[0]) cout << a << " ";
        // cout << endl;

    bool skip = true;
    int inicio;
    int count = 0;

    for (int s = 1; s <= steps; s++)
    {
        // cout << skip << " - ";
        if (skip && rondas[s-1].size() != 1) 
        {
            inicio = 1;
        }
        else inicio = 0;

        for (int i = 0; i < rondas[s-1].size(); i++)
        {
            if (i % 2 == inicio) ret.push_back(rondas[s-1][i]);
            else rondas[s].push_back(rondas[s-1][i]);
        }

        // for (int b = 0; b < rondas[s].size(); b++) cout << rondas[s][b] << " ";
        // cout << "A";

        
        if (rondas[s-1].size() % 2 == 1) skip = !skip;

        // cout << "- " << skip;
        // cout << endl;

        
    }

    for (int a : ret) cout << a << " ";
}