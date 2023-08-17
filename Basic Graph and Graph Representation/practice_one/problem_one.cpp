#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        // cout << v << " ";
        if (visited[v] == true)
            continue;
        dfs(v);
        cout << v << " ";
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    cout << 1 << " ";

    return 0;
}