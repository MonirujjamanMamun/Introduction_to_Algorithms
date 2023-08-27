#include <bits/stdc++.h>

using namespace std;
void merge_sort(int a[], int left, int mid, int right)
{
    int leftSize = (mid - left) + 1;
    int rightSize = right - mid;
    int Left[leftSize], Right[rightSize];
    int k = 0;
    for (int i = left; i <= mid; i++)
    {
        Left[k] = a[i];
        k++;
    }
    k = 0;
    for (int i = mid + 1; i <= right; i++)
    {
        Right[k] = a[i];
        k++;
    }
    int i = 0, j = 0, cur = left;
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
    while (j < leftSize)
    {
        a[cur] = Right[j];
        j++;
        cur++;
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

    merge_sort(a, 0, 3, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}