#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }

    for (int i = 0; i < n; i++)
    {
        int p = pq.top().first;
        int q = pq.top().second;
        pq.pop();
        cout << p << " " << q << endl;
    }

    return 0;
}
