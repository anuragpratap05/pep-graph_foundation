#include<bits/stdc++.h>
using namespace std;

//
class  graph
{
public:
	list<pair<int, int>> *l;
	int v;

	graph(int n)
	{
		v = n;
		l = new list<pair<int, int>>[n];
	}

	void addedge(int x, int y, int wt)
	{
		l[x].push_back(make_pair(y, wt));
		l[y].push_back(make_pair(x, wt));
	}

	void print()
	{
		for (int i = 0; i < v; i++)
		{
			cout << i << "->";
			for (auto x : l[i])
			{
				cout << x.first << " " << x.second << " , ";
			}
			cout << endl;
		}
	}

	void has_path(int src, int dest, bool* visited, string psf)
	{
		if (src == dest)
		{
			cout << psf << endl;
			return ;
		}




		visited[src] = true;
		for (auto x : l[src])
		{
			int nbr = x.first;
			if (!visited[nbr])
			{
				has_path(nbr, dest, visited, psf + to_string(nbr));

			}
		}
		visited[src] = false;


		//return false;

	}



};

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif

	int v, e;
	cin >> v >> e;
	graph g(v);

	for (int i = 0; i < e; i++)
	{
		int x, y, wt;
		cin >> x >> y >> wt;
		g.addedge(x, y, wt);
	}
	//g.print();
	int src, dest;
	cin >> src >> dest;

	bool* visited = new bool[v]();

	g.has_path(src, dest, visited, "0");









}
