#include<cstdio>
#include<cstring>
#define min(x,y)x<y?x:y
const int  N = 110;
int cost[N][N];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	int u, v, w;
	memset(cost, 0x36, sizeof(cost));
	for (int i = 0;i < m;i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		cost[u][v] = cost[v][u] = min(cost[v][u], w);
	}

	for (int k = 1;k <= n;++k)
		for (int i = 1;i <= n;++i)
			for (int j = 1;j <= n;++j)
				if (k != i&&i!=j&&j!= k)
					cost[i][j] = min(cost[i][k] + cost[k][j], cost[i][j]);

	for (int i = 1;i <= n;++i)
	{
		cost[i][i] = 0;
		for (int j = 1;j <= n;++j)
			printf("%d ", cost[i][j]);
		printf("\n");
	}
	return 0;
}