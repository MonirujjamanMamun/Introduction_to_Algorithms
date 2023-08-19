#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
int visited[N];
int level[N];
int parents[N];

void bfs(int s)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    parents[s] = -1;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (int v : adj[p])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[p] + 1;
            parents[v] = p;
        }
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
    int s, d;
    cin >> s >> d;
    bfs(s);
    cout << "Level : " << level[d] << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "parents of " << i << " : " << parents[i] << endl;
    // }

    vector<int> path;
    int current = d;
    while (current != -1)
    {
        path.push_back(current);
        current = parents[current];
    }
    reverse(path.begin(), path.end());

    for (int a : path)
    {
        cout << a << " ";
    }

    return 0;
}
