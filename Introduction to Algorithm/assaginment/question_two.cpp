#include <bits/stdc++.h>
using namespace std;
void find_target(vector<int> v, int t)
{
    int l = 0;
    int h = v.size() - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (v[mid] == t)
        {
            cout << mid << endl;
            return;
        }
        else if (v[mid] < t)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    cout << "Not Found" << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    int t;
    cin >> t;
    find_target(v, t);

    return 0;
}
