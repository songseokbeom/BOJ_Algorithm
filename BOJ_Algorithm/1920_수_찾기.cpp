#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int arr[100001], sear[100001];

int main()
{
	int n, m;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &sear[i]);

	sort(arr, arr + n);

	for (int i = 0; i < m; i++)
	{
		bool flag = false;
		int goal = sear[i];
		int left = 0, right = n - 1, mid;

		while (left <= right)
		{
			mid = (left + right) / 2;

			if (arr[mid] == goal)
			{
				flag = true;
				break;
			}
			else if (arr[mid] > goal)
				right = mid - 1;
			else
				left = mid + 1;
		}
		if (flag == false) printf("0\n");
		else printf("1\n");
	}

	return 0;
}