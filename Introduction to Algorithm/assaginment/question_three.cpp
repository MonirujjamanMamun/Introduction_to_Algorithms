#include <bits/stdc++.h>
using namespace std;
bool find_target(vector<int> v, int t)
{
    int l = 0;
    int h = v.size() - 1;
    int firstFound = 0;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (v[mid] == t)
        {
            firstFound = mid;
            h = mid - 1;
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

    l = firstFound + 1;
    h = v.size() - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (v[mid] == t)
        {
            return true;
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

    return false;
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
    if (find_target(v, t))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
