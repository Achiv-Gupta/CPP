#include <algorithm>
#include <bitset>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <memory.h>
 
using namespace std;
 
int a[11];
int b[11];
int d[11];
int c[11];
int n;
int m;
 
int res[1010];
int nres[1010];
 
void solve(int i)
{
	memset(nres, 0, sizeof(nres));
	for (int x = 0; x <= n; ++x)
	{
		for (int j = 0; j * b[i] <= a[i] && x + c[i] * j <= n; ++j)
		{
			nres[x + c[i] * j] = max(nres[x + c[i] * j], res[x] + j * d[i]);
		}
	}
	memcpy(res, nres, sizeof(nres));
}
 
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
 
 
	scanf("%d %d %d %d", &n, &m, &c[0], &d[0]);
	for (int i = 1; i <= m; ++i)
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	for (int i = 0; i <= m; ++i)
		solve(i);
	int ans = 0;
	for (int i = 0; i <= n; ++i)
		ans = max(ans, res[i]);
	cout << ans;
 
	
 
	return 0;
}