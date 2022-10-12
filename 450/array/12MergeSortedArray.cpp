#include <bits/stdc++.h>
using namespace std;
void merge(int *arr1, int *arr2, int n, int m)
{
	int i = n - 1, j = 0;
	while (i >= 0 && j < m)
	{
		if (arr1[i] >= arr2[j])
		{
			swap(arr1[i], arr2[j]);
			i--;
			j++;
		}
		else
			break;
	}

	sort(arr1, arr1 + n);
	sort(arr2, arr2 + m);
}
int main()
{
	int arr1[] = {1, 3, 5, 7, 9};
	int arr2[] = {2, 4, 6, 8};
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);
	merge(arr1, arr2, m, n);
	for (int i = 0; i < m; i++)
		cout << arr1[i] << " ";
	for (int i = 0; i < n; i++)
		cout << arr2[i] << " ";
}