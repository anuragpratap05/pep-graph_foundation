# pep-graph_foundation#include<bits/stdc++.h>
using namespace std;

void path(int**a,  int i, int j, int n, int move )
{

	if (i<0 or j<0 or i >= n or j >= n or a[i][j] > 0 )
	{
		return;
	}

	if (move == n * n)
	{
		a[i][j] = move;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		a[i][j] = 0;
		return;


	}
	a[i][j] = move;
	path(a,  i - 2, j + 1, n, move + 1);
	path(a,  i - 1, j + 2, n, move + 1 );
	path(a,  i + 1, j + 2, n, move + 1);
	path(a,  i + 2, j + 1, n, move + 1);
	path(a,  i + 2, j - 1, n, move + 1);
	path(a,  i + 1, j - 2, n, move + 1);
	path(a,  i - 1, j - 2, n, move + 1);
	path(a,  i - 2, j - 1, n, move + 1);
	a[i][j] = 0;
}

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	cin >> n ;

	int row, col;
	cin >> row >> col;
	int** a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}

	path(a, row, col, n, 1);









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








