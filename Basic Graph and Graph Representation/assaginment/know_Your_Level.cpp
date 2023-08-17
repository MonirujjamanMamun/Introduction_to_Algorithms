#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int levels[N];
bool visited[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

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
            levels[v] = levels[p] + 1;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int l;
    cin >> l;

    if (l == 0)
    {
        cout << "0" << endl;
    }
    else
    {
        bfs(0);

        vector<int> pizzaShopsInLevel;
        for (int i = 0; i <= N; ++i)
        {
            if (levels[i] == l)
            {
                pizzaShopsInLevel.push_back(i);
            }
        }

        if (pizzaShopsInLevel.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            for (int shop : pizzaShopsInLevel)
            {
                cout << shop << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
