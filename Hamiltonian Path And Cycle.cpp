# pep-graph_foundation#include<bits/stdc++.h>
using namespace std;

class graph
{
	list<pair<int, int>> *l;
	int v;
public:
	graph(int v)
	{
		this->v = v;
		l = new list<pair<int, int>>[v];

	}

	void addedge(int x, int y, int wt)
	{
		l[x].push_back(make_pair(y, wt));
		l[y].push_back(make_pair(x, wt));
	}

	void paths(int src, string psf, set<int> &s, int osrc)
	{

		if (s.size() == v - 1)
		{


			bool flag = false;

			for (auto z : l[src])
			{
				int f = z.first;
				if (f == osrc)
				{
					flag = true;
					break;
				}
			}

			if (flag)
			{
				cout << psf << "*" << endl;
			}
			else
			{
				cout << psf << "." << endl;
			}
		}

		s.insert(src);
		for (auto x : l[src])
		{
			int nbr = x.first;
			if (s.find(nbr) == s.end())
			{
				paths(nbr, psf + to_string(nbr), s, osrc);
			}
		}
		s.erase(src);
	}
};

int main()
{


	int v, e;
	cin >> v >> e;
	graph g(v);
	for (int i = 0; i < e; i++)
	{
		int a, b, wt;
		cin >> a >> b >> wt;
		g.addedge(a, b, wt);
	}
	int src;
	cin >> src;

	set<int>s;

	g.paths(src, to_string(src)+"", s, src);
}
