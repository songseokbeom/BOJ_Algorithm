#include <stdio.h>
#include <deque>
#include <memory.h>
using namespace std;

int truck[1001];

int main()
{
	int n, w, l, sum=0, t=0;
	deque<int> dq;

	scanf("%d %d %d", &n, &w, &l);

	for (int i = 1; i <= n; i++)
		scanf("%d", &truck[i]);

	for (int i = 1; i <= w; i++)
		dq.push_back(0);

	int idx = 1;
	while (1)
	{
		int fr = dq.front();
		dq.pop_front();
		t++, sum -= fr;

		if (truck[idx] + sum <= l)
		{
			sum += truck[idx];
			dq.push_back(truck[idx]);
			idx++;
		}

		else
			dq.push_back(0);

		if (idx > n)
		{
			t = t + w;
			break;
		}
	}

	printf("%d\n", t);

	return 0;
}