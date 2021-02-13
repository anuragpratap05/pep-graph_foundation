# pep-graph_foundation#include<bits/stdc++.h>
using namespace std;

void path(int**a, bool** visited, int i, int j, int n, int m)
{

	if (i<0 or j<0 or i >= n or j >= m or a[i][j] == 1 or visited[i][j])
	{
		return;
	}

	visited[i][j] = true;

	path(a, visited, i, j + 1, n, m);
	path(a, visited, i, j - 1, n, m);
	path(a, visited, i + 1, j, n, m);
	path(a, visited, i - 1, j, n, m);
}

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n, m;
	cin >> n >> m;
	int** a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	bool** visited = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = new bool[m];
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = false;
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0 and visited[i][j] == false)
			{
				path(a, visited, i, j, n, m);
				cnt++;
			}
		}
	}
	cout << cnt;





}



/*for (int i = 0; i <= n; i++)
{
	for (int j = 0; j <= n; j++)
	{
		cout << dp[i][j] << " ";
	}
	cout << endl;
}*/
//cout << maxi;








