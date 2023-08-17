#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
int level[N];
int visited[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        // cout << "Visiting :" << p << endl;

        for (int i : adj[p])
        {
            if (visited[i] == true)
                continue;
            q.push(i);
            visited[i] = true;
            level[i] = level[p] + 1;
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

    bfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Leve " << i << " : " << level[i] << endl;
    }
    return 0;
}