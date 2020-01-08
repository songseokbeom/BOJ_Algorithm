#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int card[100], check[100], result, m, n;

void dfs(int, int, int);

int main()
{
	scanf("%d %d", &n, &m);

	result = 987654321;
	for (int i = 0; i < n; i++)
		scanf("%d", &card[i]);

	dfs(0, 0, 0);

	printf("%d\n", result);

	return 0;
}

void dfs(int cnt, int idx, int sum)
{
	if (cnt == 3)
	{
		if (sum > m) return;
		if (abs(m - sum) < abs(m - result))
			result = sum;
		return;
	}
	if (idx >= n) return;

	for (int i = idx; i < n; i++)
		dfs(cnt + 1, i + 1, sum + card[i]);
}