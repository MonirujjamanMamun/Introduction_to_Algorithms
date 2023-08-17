// #include <bits/stdc++.h>

// using namespace std;
// typedef pair<int, int> pii;
// const int N = 1e5 + 10;
// const int INF = 1e9 + 10;
// vector<pii> adj[N];
// vector<bool> visited(N);
// vector<int> dist(N, INF);

// void djikstra(int sourse)
// {
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     dist[sourse] = 0;
//     pq.push({dist[sourse], sourse});
//     while (!pq.empty())
//     {
//         int p = pq.top().second;
//         pq.pop();
//         visited[p] = true;

//         for (pii vparr : adj[p])
//         {
//             int u = vparr.first;
//             int v = vparr.second;
//             if (visited[u])
//                 continue;

//             if (dist[u] > dist[p] + v)
//             {
//                 dist[u] = dist[p] + v;
//                 pq.push({dist[u], u});
//             }
//         }
//     }
// }

// int main()
// {

//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     }
//     djikstra(1);

//     for (int i = 1; i <= n; i++)
//     {
//         cout << "Distence of Node " << i << " : " << dist[i] << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 5;
const int INF = 1e9 + 10;

vector<pii> adj[N];
vector<bool> visited(N);
vector<int> dist(N, INF);

void dijkstra(int source)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        int p = pq.top().second;
        pq.pop();
        visited[p] = true;
        for (pii vpar : adj[p])
        {
            int u = vpar.first;
            int v = vpar.second;
            if (visited[u])
                continue;
            if (dist[u] > dist[p] + v)
            {
                dist[u] = dist[p] + v;
                pq.push({dist[u], u});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Dist of Node " << i << " : " << dist[i] << endl;
    }
    return 0;
}