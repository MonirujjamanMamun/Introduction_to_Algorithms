#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int visited[N];
int level[N];

void bfs(int s)
{

    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
}

int main()
{
    int n, m, q;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> q;
    while (q--)
    {
        int s, d;
        cin >> s >> d;
        for (int i = 0; i <= N; i++)
        {
            visited[i] = 0;
            level[i] = 0;
        }
        bfs(s);
        if (visited[d] == 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << level[d] << endl;
        }
    }

    return 0;
}
