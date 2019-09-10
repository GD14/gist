#include<cstdio>
#include<cstdlib>
#include<cstring>
#define INT_MAX 10000000
using namespace std;
int aa;char ch;int getInt() {
	while (ch = getchar(), ch < 48 || ch>57);aa = ch - 48;
	while (ch = getchar(), ch >= 48 && ch <= 57)aa = (aa << 1) * 5 + ch - 48;
	return aa;
}
#define min(x,y)x<y?x:y
const int N = 1100;

int cost[N][N];
int n, m, s, t;
int lest[N],visited[N];

void Dijkstra(){
	int min;	
	int k,i,j;

	for (i = 1;i <=n;++i)
	lest[i] = cost[s][i];
	  
	visited[s] = 1;
	for ( i = 1;i < n;i++)
	{
		min = INT_MAX ;
		for ( j = 1;j <=n;++j)
			if (!visited[j]&&lest[j] < min){
				min = lest[j];
				k = j;
			}
		if (k == t) return;
		visited[k] = 1;
		for (j = 1;j <=n;++j)
		if(!visited[j])lest[j] = min(lest[j], lest[k] + cost[k][j]);
	}
}

int main()
{
	n = getInt();
	m = getInt();
	s = getInt();
	t = getInt();
	int u, v, len;
	
	memset(cost, 0x3f, sizeof(cost));
	memset(cost, 0, sizeof(visited));
	for (int i = 0;i < m;++i)
	{
		u = getInt();v = getInt();len = getInt();
		cost[v][u] = cost[u][v] = min(cost[u][v], len);
	}
	Dijkstra();
	printf("%d", lest[t]);
	return 0;
}
