#include <bits/stdc++.h>

using namespace std;

// // const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
// // const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
//  vector<pair<int, int>> path = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
// int n, m;
// // vector<bool> visited(N, false) ;
// bool visited[100][100];
// // vector<vector<bool>> visited(100, vector<bool>(100, false));

// bool isValid(int cI, int cJ)
// {
//     if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
//         return true;
//     else
//         return false;
// }

// int bfs(int N, int M, int knightRow, int knightCol, int queenRow, int queenCol)
// {
//     // vector<vector<bool>> visited(N, vector<bool>(M, false));
//     queue<pair<int, int>> q;

//     q.push({knightRow, knightCol});
//     visited[knightRow][knightCol] = true;

//     int steps = 0;
//     while (!q.empty())
//     {
//         int parents = q.size();
//         for (int i = 0; i < parents; ++i)
//         {
//             int x = q.front().first;
//             int y = q.front().second;
//             q.pop();

//             if (x == queenRow && y == queenCol)
//             {
//                 return steps;
//             }

//             for (int j = 0; j < 8; ++j)
//             {
//                 int newX = x + path[j].first;
//                 int newY = y + path[j].second;
//                 if (isValid(newX, newY) && !visited[newX][newY])
//                 {
//                     q.push({newX, newY});
//                     visited[newX][newY] = true;
//                 }
//             }
//         }
//         steps++;
//     }

//     return -1; // Queen cannot be reached
// }

// int main()
// {
//     int T;
//     cin >> T;
//     for (int i = 0; i < 100; i++)
//     {
//         for (int j = 0; j < 100; j++)
//         {
//             visited[i][j] = false;
//         }
//     }

//     while (T--)
//     {
//         int knightRow, knightCol, queenRow, queenCol;
//         cin >> n >> m >> knightRow >> knightCol >> queenRow >> queenCol;

//         int minSteps = bfs(n, m, knightRow, knightCol, queenRow, queenCol);
//         cout << minSteps << endl;
//     }

//     return 0;
// }

// vector<pair<int, int>> path = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
// vector<vector<bool>> visited(100, vector<bool>(100, false));

// int bfs(int N, int M, int knightRow, int knightCol, int queenRow, int queenCol)
// {

//     queue<pair<int, int>> q;

//     q.push(make_pair(knightRow, knightCol));
//     visited[knightRow][knightCol] = true;

//     int steps = 0;
//     while (!q.empty())
//     {
//         int numCells = q.size();
//         for (int i = 0; i < numCells; ++i)
//         {
//             int x = q.front().first;
//             int y = q.front().second;
//             q.pop();

//             if (x == queenRow && y == queenCol)
//             {
//                 return steps;
//             }

//             for (int j = 0; j < 8; ++j)
//             {
//                 int newX = x + path[j].first;
//                 int newY = y + path[j].second;
//                 if (newX >= 0 && newX < N && newY >= 0 && newY < M && !visited[newX][newY])
//                 {
//                     q.push(make_pair(newX, newY));
//                     visited[newX][newY] = true;
//                 }
//             }
//         }
//         ++steps;
//     }

//     return -1; // Queen cannot be reached
// }

#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
const int N = 1005;
bool vis[N][N];
int dis[N][N];
// int n, m;
vector<pi> path = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
bool isValid(int cI, int cJ, int N, int M)
{
    if (cI >= 0 && cI < N && cJ >= 0 && cJ < M)
        return true;
    else
        return false;
}
void bfs(int si, int sj, int N, int M, bool *vis, int *dis)
{
    queue<pi> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;
    while (!q.empty())
    {
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pi p = path[i];
            int cI = pI + p.first;
            int cJ = pJ + p.second;
            if (isValid(cI, cJ, N, M) && !vis[cI][cJ])
            {
                vis[cI][cJ] = true;
                q.push({cI, cJ});
                dis[cI][cJ] = dis[pI][pJ] + 1;
            }
        }
    }
}
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M, si, sj, di, dj;
        cin >> N >> M >> si >> sj >> di >> dj;
        bool vis[N][M];
        int dis[N][M];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                vis[i][j] = false;
                dis[i][j] = -1;
            }
        }
        bfs(si, sj, N, M, (bool *)vis, (int *)dis);
        cout << dis[di][dj] << endl;
    }

    return 0;
}