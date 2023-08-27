#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
vector<int> adj[N];
int visited[N];
int diste[N];
void bfs(int sourse)
{
    queue<int> q;
    q.push(sourse);
    visited[sourse] = true;
    diste[sourse] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child : adj[parent])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                diste[child] = diste[parent] + 1;
            }
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
        adj[edges].push_back(node);
    }
    bfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Distenst " << i << " : ";
        cout << diste[i] << endl;
    }
    return 0;
}