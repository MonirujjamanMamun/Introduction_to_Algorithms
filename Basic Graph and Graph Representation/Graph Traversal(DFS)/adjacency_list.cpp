#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector<int> adjLit[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjLit[u].push_back(v);
        adjLit[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "List- " << i << ": ";
        for (int j : adjLit[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}