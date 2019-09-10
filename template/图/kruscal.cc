#include<cstdio>

#define N 100100
#define M 1000100  

int n, m;
int father[N];
int x[M], y[M], c[M];
int aa;char ch;int getInt() {
	while (ch = getchar(), ch < 48 || ch>57);aa = ch - 48;
	while (ch = getchar(), ch > 47 && ch < 58)aa = aa * 10 + ch - 48;
	return aa;
}
int find(int x)
{
	return father[x] == x ? x : father[x]=find(father[x]);
}

void swap(int &x, int &y)
{
	int t = x; x = y;y = t;
}
void quickSort(int l, int r)
{
	int i = l, j = r;
	int mid = c[(l + r) / 2];

	while (i < j)
	{
		while (c[i] < mid)++i;
		while (c[j] > mid)--j;
		if (i <= j)
		{
			swap(c[i], c[j]);
			swap(x[i], x[j]);
			swap(y[i], y[j]);
			++i;--j;
		}
	}
	if (i < r) quickSort(i,r);
	if (l < j)quickSort(l, j);
}
int main()
{
	n = getInt();
	m = getInt();
	
	int cost = 0, count = 0;
	
	int i;
	for (i = 1;i <= n;++i)
		father[i] = i;

	for (i = 0;i < m;++i)
	{
		x[i] = getInt();
		y[i] = getInt();
		c[i] = getInt();
	}

	quickSort(0,m-1);

	int m1, m2;
	for (i = 0;i < m;++i)
	{
		m1 = find(x[i]);
		m2 = find(y[i]);
		if (m1 != m2)
		{
			father[m1] = m2;
			cost += c[i];
		   if (++count == n - 1)break;
		}
	}

	printf("%d", cost);
	return 0;
}

