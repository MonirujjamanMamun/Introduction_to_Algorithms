#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    while (m--)
    {
        int node, edge;
        cin >> node >> edge;
        adj[node].push_back(edge);
        adj[edge].push_back(node);
    }
    for (int i = 0; i <= n; i++)
    {
        cout << "Index " << i << " : ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}