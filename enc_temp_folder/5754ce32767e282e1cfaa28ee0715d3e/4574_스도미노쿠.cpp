#include <stdio.h>
#include <deque>
#include <algorithm>
using namespace std;

int map[9][9];
int n;

void solve();

int main()
{
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		solve();
	}

	return 0;
}

void solve()
{
	for (int i = 0; i < n; i++)
	{
		int n1, n2, y1, y2;
		char x1, x2;

		scanf("%d %c%d %d %c%d", &n1, &x1, &y1, &n2, &x2, &y2);
		map[x1 - 'A'][y1] = n1;
		map[x2 - 'A'][y2] = n2;
	}

	for (int i = 0; i < 9; i++)
	{
		char x;
		int y;
		scanf("%c%d", &x, &y);
		map[x - 'A'][y] = i + 1;
	}
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}

}