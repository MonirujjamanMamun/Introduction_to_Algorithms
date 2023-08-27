#include <bits/stdc++.h>

using namespace std;

void divid(int a[], int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    if (left < right)
    {
        int mid = (left + right) / 2;
        divid(a, left, mid);
        divid(a, mid + 1, right);
    }
}

int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    divid(a, 0, n - 1);
    return 0;
}