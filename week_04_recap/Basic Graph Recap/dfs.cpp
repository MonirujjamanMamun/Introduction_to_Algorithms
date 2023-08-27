#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
vector<int> adj[N];
bool visited[N];

void dfs(int sours)
{
    visited[sours] = true;
    for (int child : adj[sours])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int node, edges;
        cin >> node >> edges;
        adj[node].push_back(edges);
        adj[edges].push_back(edges);
    }

    dfs(1);

    return 0;
}