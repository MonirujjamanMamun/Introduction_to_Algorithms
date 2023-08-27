#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj;
    while (m--)
    {
        int node, edges;
        cin >> node >> edges;
        adj.push_back({node, edges});
    }
    for (int i = 0; i < adj.size(); i++)
    {
        cout << adj[i].first << " " << adj[i].second << endl;
    }

    return 0;
}