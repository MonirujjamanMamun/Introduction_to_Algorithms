// #include <iostream>
// #include <vector>
// #include <bitset>

// using namespace std;
// const int N = 1e3 + 5;
// vector<int> adj[N];
// bool visited[N];
// void dfs(int s)
// {
//     visited[s] = true;

//     for (int v : adj[s])
//     {
//         if (!visited[v])
//         {
//             dfs(v);
//         }
//     }
// }

// int main()
// {
//     int n, m, k;
//     cin >> n >> m;

//     for (int i = 0; i < m; ++i)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//     }

//     dfs(K, adjacencyList, visited);

//     int reachableHouses = visited.count();
//     cout << reachableHouses << endl;

//     return 0;
// }

// void dfs(int currentHouse, const vector<vector<int>> &adjacencyList, bitset<1000> &visited)
// {
//     visited[currentHouse] = true;

//     for (int neighbor : adjacencyList[currentHouse])
//     {
//         if (!visited[neighbor])
//         {
//             dfs(neighbor, adjacencyList, visited);
//         }
//     }
// }

// int main()
// {
//     int N, E, K;
//     cin >> N >> E >> K; // Input the number of houses, roads, and Kamal's house number

//     vector<vector<int>> adjacencyList(N);
//     bitset<1000> visited; // Bitset to keep track of visited houses

//     for (int i = 0; i < E; ++i)
//     {
//         int u, v;
//         cin >> u >> v; // Input the two houses connected by a road
//         adjacencyList[u].push_back(v);
//     }

//     dfs(K, adjacencyList, visited);

//     int reachableHouses = visited.count();
//     cout << reachableHouses << endl;

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
int N = 20;
vector<int> adj[N];
vector<bool> visited(N, false);
void dfs(int house)
{
    visited[house] = true;
    for (int neighbor : adj[house])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor);
        }
    }
}

int main()
{
    int N, E;
    cin >> N >> E;

    vector<vector<int>> adj(N);
    for (int i = 0; i < E; ++i)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }

    int K;
    cin >> K;

    // vector<bool> visited(N, false);
    dfs(K);

    int reachableHouses = 0;
    for (bool isReachable : visited)
    {
        if (isReachable)
        {
            ++reachableHouses;
        }
    }

    cout << reachableHouses - 1 << endl;

    return 0;
}
