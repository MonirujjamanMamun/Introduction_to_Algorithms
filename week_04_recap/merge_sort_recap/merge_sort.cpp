#include <bits/stdc++.h>

using namespace std;
void merge(int a[], int l, int mid, int r)
{
    int leftSize = (mid - l) + 1;
    int rightSize = r - mid;
    int Left[leftSize];
    int Right[rightSize];
    int k = 0;
    for (int i = l; i <= mid; i++)
    {
        Left[k] = a[i];
        k++;
    }
    k = 0;
    for (int i = mid + 1; i <= r; i++)
    {
        Right[k] = a[i];
        k++;
    }
    int i = 0, j = 0, cur = l;
    while (i < leftSize && j < rightSize)
    {
        if (Left[i] <= Right[j])
        {
            a[cur] = Left[i];
            i++;
        }
        else
        {
            a[cur] = Right[j];
            j++;
        }
        cur++;
    }
    while (i < leftSize)
    {
        a[cur] = Left[i];
        i++;
        cur++;
    }
    while (j < rightSize)
    {
        a[cur] = Right[j];
        j++;
        cur++;
    }
}
void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, r);
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
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}