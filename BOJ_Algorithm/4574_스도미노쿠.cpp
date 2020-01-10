#include <stdio.h>
#include <memory.h>

bool flag;
int n, map[10][10], remain, t, tile[10][10], dx[] = { 1, 0 }, dy[] = { 0, 1 };

void solve();
void dfs(int x, int y, int cnt);
void check_row(int, int *);
void check_col(int, int *);
void check_box(int, int, int *);

int main()
{
	t = 0;
	while (1)
	{
		t++;
		scanf("%d", &n);
		if (n == 0) break;
		memset(map, 0, sizeof(map));
		memset(tile, 0, sizeof(tile));
		flag = false;
		solve();
	}

	return 0;
}

void solve()
{
	for (int i = 0; i < n; i++)
	{
		char x1, x2;
		int n1, n2, y1, y2;
		scanf("%d %c%d %d %c%d", &n1, &x1, &y1, &n2, &x2, &y2);
		map[x1 - 'A' + 1][y1] = n1, map[x2 - 'A' + 1][y2] = n2;
		tile[n1][n2] = 1, tile[n2][n1] = 1;
	}

	for (int i = 1; i <= 9; i++)
	{
		char x;
		int y;
		getchar();
		scanf("%c%d", &x, &y);
		map[x - 'A' + 1][y] = i;
	}
	remain = 36 - n;

	dfs(1, 1, 0);
}

void dfs(int x, int y, int cnt)
{
	int select[10], select2[10];
	if (flag == true) return;
	if (cnt == remain)
	{
		for (int i = 1; i <= 9; i++)
		{
			memset(select, 0, sizeof(select));
			check_row(i, select);
			for (int j = 1; j <= 9; j++)
				if (select[j] == 0 || select[j] == 2) return;
			memset(select, 0, sizeof(select));
			check_col(i, select);
			for (int j = 1; j <= 9; j++)
				if (select[j] == 0 || select[j] == 2) return;
		}

		for (int i = 1; i <= 7; i = i + 3)
		{
			for (int j = 1; j <= 7; j = j + 3)
			{
				memset(select, 0, sizeof(select));
				check_box(i, j, select);
				for (int v = 1; v <= 9; v++)
					if (select[v] == 0 || select[v] == 2) return;
			}
		}
		flag = true;
		printf("Puzzle %d\n", t);
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
				printf("%d", map[i][j]);
			printf("\n");
		}
		return;
	}

	if (map[x][y] != 0)
	{
		if (y == 9) dfs(x + 1, 1, cnt);
		else dfs(x, y + 1, cnt);
		return;
	}

	memset(select, 0, sizeof(select));
	check_row(x, select);
	check_col(y, select);
	check_box(x, y, select);

	for (int c = 1; c <= 9; c++)
	{
		if (select[c] == 1) continue;
		map[x][y] = c;
		for (int i = 0; i < 2; i++)
		{
			int tx = x + dx[i], ty = dy[i] + y;
			if (tx < 1 || tx>9 || ty < 1 || ty>9) continue;
			if (map[tx][ty] != 0) continue;
			memset(select2, 0, sizeof(select2));
			check_row(tx, select2);
			check_col(ty, select2);
			check_box(tx, ty, select2);

			for (int b = 1; b <= 9; b++)
			{
				if (select2[b] == 1 || c == b) continue;
				if (tile[c][b] == 1 || tile[b][c] == 1) continue;
				tile[c][b] = 1, tile[b][c] = 1, map[tx][ty] = b;
				if (y == 9) dfs(x + 1, 1, cnt + 1);
				else dfs(x, y + 1, cnt + 1);
				tile[c][b] = 0, tile[b][c] = 0, map[tx][ty] = 0;
				if (flag == true) return;
			}
		}
		map[x][y] = 0;
	}
}

void check_row(int x, int *select)
{
	for (int i = 1; i <= 9; i++)
		if (map[x][i] != 0) select[map[x][i]] = 1;
}
void check_col(int y, int *select)
{
	for (int i = 1; i <= 9; i++)
		if (map[i][y] != 0) select[map[i][y]] = 1;
}
void check_box(int x, int y, int *select)
{
	int x1 = ((x - 1) / 3) * 3 + 1, y1 = ((y - 1) / 3) * 3 + 1;

	for (int i = x1; i < x1 + 3; i++)
	{
		for (int j = y1; j < y1 + 3; j++)
			if (map[i][j] != 0) select[map[i][j]] = 1;
	}
}