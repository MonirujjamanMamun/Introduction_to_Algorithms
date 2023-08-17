#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];

int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> n >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "list " << i << " ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}