#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<bool>> vis;
vector<pair<int, int>> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int cI, int cJ)
{
    return (cI >= 0 && cI < n && cJ >= 0 && cJ < m);
}

int cnt;

void dfs(int si, int sj, vector<vector<char>> &grid)
{
    vis[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + path[i].first;
        int cj = sj + path[i].second;
        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci, cj, grid);
        }
    }
}

int findMinComponentArea(vector<vector<char>> &grid)
{
    n = grid.size();
    m = grid[0].size();
    vis.assign(n, vector<bool>(m, false));

    int minArea = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                cnt = 0;
                dfs(i, j, grid);
                minArea = min(cnt, minArea);
            }
        }
    }
    return minArea;
}

int main()
{
    int numRows, numCols;
    cin >> numRows >> numCols;

    vector<vector<char>> grid(numRows, vector<char>(numCols));
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            cin >> grid[i][j];
        }
    }

    int result = findMinComponentArea(grid);

    if (result == INT_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}
