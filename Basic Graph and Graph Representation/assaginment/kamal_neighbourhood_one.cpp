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

    int house_num;
    cin >> house_num;
    int desta = adjLit[house_num].size();
    cout << desta << endl;

    return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     int N, E, K;
//     cin >> N >> E >> K; // Input the number of houses, roads, and Kamal's house number

//     vector<vector<int>> adjacencyList(N);

//     for (int i = 0; i < E; ++i)
//     {
//         int u, v;
//         cin >> u >> v; // Input the two houses connected by a road
//         adjacencyList[u].push_back(v);
//         adjacencyList[v].push_back(u); // Since roads are two-way
//     }

//     int directlyConnected = adjacencyList[K].size();
//     cout << directlyConnected << endl;

//     return 0;
// }
