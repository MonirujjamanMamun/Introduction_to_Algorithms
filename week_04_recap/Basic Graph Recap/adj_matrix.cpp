#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    int adj[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            adj[i][j] = 0;
            if (i == j)
                adj[i][j] = 1;
        }
    }

    while (m--)
    {
        int node, edge;
        cin >> node >> edge;
        adj[node][edge] = 1;
        adj[edge][node] = 1;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}