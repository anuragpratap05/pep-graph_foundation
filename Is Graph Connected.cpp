# pep-graph_foundation#include<bits/stdc++.h>
using namespace std;


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







	vector<int>* has_path(int src,  bool* visited, vector<int>* comp )
	{


		visited[src] = true;
		comp->push_back(src);
		for (auto x : l[src])
		{
			int nbr = x.first;
			//int wt = x.second;
			if (!visited[nbr])
			{
				has_path(nbr, visited, comp);

			}
		}
		//visited[src] = false;


		//return false;
		return comp;

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


	bool* visited = new bool[v]();
	vector<vector<int>> *vec = new vector<vector<int>>();

	for (int i = 0; i < v; i++)
	{
		if (!visited[i])
		{
			vector<int> *comp = new vector<int>();
			vector<int>* x = g.has_path(i, visited, comp);
			vec->push_back(*x);

		}

	}

	if (vec->size() == 1)
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
	/*int r = 0;
	cout << "[";
	for (auto x1 : *vec)
	{
		r++;
		cout << "[";

		for (int i = 0; i < x1.size(); i++)
		{
			if (i == x1.size() - 1)
			{
				cout << x1[i];
			}
			else
			{
				cout << x1[i] << ",";
			}
		}
		if (r != vec->size())
			cout << "],";
		else
			cout << "]";

	}
	cout << "]";*/



}
