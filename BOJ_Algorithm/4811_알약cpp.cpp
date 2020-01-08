#include <stdio.h>
#include <memory.h>

long long unsigned int cache[62];
long long unsigned int dp(int);


int main()
{
	memset(cache, -1, sizeof(cache));
	cache[1] = 1;
	while (1)
	{
		int n;
		scanf("%d", &n);
		if (n == 0) break;

		printf("%lld\n", dp(n));
	}
	return 0;
}

long long unsigned int dp(int num)
{
	if (cache[num] != -1) return cache[num];

	return cache[num] = dp(num - 1)*(4 * num - 2) / (num + 1);
}