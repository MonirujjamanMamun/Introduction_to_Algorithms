#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int size1, int size2, int mergedArr[])
{
    int L[size1 + 1];
    int R[size2 + 1];
    for (int i = 0, j = 0; i < size1; i++, j++)
        L[j] = arr1[i];
    for (int i = 0, j = 0; i < size2; i++, j++)
        R[j] = arr2[i];
    L[size1] = INT_MIN;
    R[size2] = INT_MIN;
    int lp = 0, rp = 0;
    for (int i = 0; i < size1 + size2; i++)
    {
        if (L[lp] >= R[rp])
        {
            mergedArr[i] = L[lp];
            lp++;
        }
        else
        {
            mergedArr[i] = R[rp];
            rp++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int mergedSize = size1 + size2;
    int mergedArr[mergedSize];

    merge(arr1, arr2, size1, size2, mergedArr);

    for (int i = 0; i < mergedSize; i++)
    {
        cout << mergedArr[i] << " ";
    }

    return 0;
}