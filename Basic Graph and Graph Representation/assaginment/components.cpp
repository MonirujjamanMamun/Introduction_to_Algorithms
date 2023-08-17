// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e3 + 5;
// vector<int> adj[N];
// bool visited[N];

// vector<int> a;
// int dfs(int u)
// {
//     int count = 0;
//     visited[u] = true;
//     for (int v : adj[u])
//     {
//         if (visited[v])
//             continue;
//         count++;
//         dfs(v);
//     }
//     // a.push_back(count);
//     cout << count << endl;
//     return count;
// }

// // void bfs(int s)
// // {
// //     queue<int> q;
// //     q.push(s);
// //     visited[s] = true;

// //     while (!q.empty())
// //     {
// //         int u = q.front();
// //         q.pop();

// //         for (int v : adj[u])
// //         {
// //             if (visited[v] == true)
// //                 continue;
// //             q.push(v);
// //             visited[v] = true;
// //         }
// //     }
// // }

// int main()
// {

//     int n, m;
//     cin >> n >> m;

//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     int cc = 0;
//     // vector<int> count(10);
//     for (int i = 1; i <= n; i++)
//     {
//         if (visited[i])
//             continue;
//         cc++;
//         dfs(i);
//         // cc++;
//         // count.push_back(i);
//         // a.push_back(ans);
//     }
//     for (auto i : a)
//     {
//         cout << i << " ";
//     }
//     // for (int i = 0; i < a.size(); i++)
//     // {
//     //     cout << a[i] << " ";
//     // }
//     // cout << cc << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int current, const vector<vector<int>> &graph, vector<bool> &visited, int &size)
{
    visited[current] = true;
    size++;

    for (int neighbor : graph[current])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, graph, visited, size);
        }
    }
}

int main()
{
    int N, E;
    cin >> N >> E; // Input the number of nodes and edges

    vector<vector<int>> graph(N);
    vector<bool> visited(N, false);

    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v; // Input the two nodes connected by an edge
        graph[u].push_back(v);
        graph[v].push_back(u); // Since the graph is undirected
    }

    vector<int> componentSizes;

    for (int node = 0; node < N; ++node)
    {
        if (!visited[node])
        {
            int size = 0;
            dfs(node, graph, visited, size);
            if (size > 1)
            {
                componentSizes.push_back(size);
            }
        }
    }

    sort(componentSizes.begin(), componentSizes.end());

    for (int s : componentSizes)
    {
        cout << s << " ";
    }

    cout << endl;

    return 0;
}
