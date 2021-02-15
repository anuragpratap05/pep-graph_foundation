# pep-graph_foundation
#include<bits/stdc++.h>
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

	int bfs(int src, int t, int* visited, int cnt)
	{
		queue<pair<int , int>> q;
		//visited[src] = true;

		q.push(make_pair(src, 1));

		while (!q.empty())
		{
			auto p = q.front();
			q.pop();
			int node = p.first;
			//cout << node;
			int time = p.second;

			if (visited[node] != 0)
			{
				continue;
			}

			visited[node] = time;
			if (time > t)
			{
				break;
			}
			cnt++;
			//cout << node << "@" << s << endl;


			//visited[node] = true;



			for (auto z : l[node])
			{
				if (visited[z.first] == 0)
				{
					//visited[z.first] = true;
					q.push(make_pair(z.first, time + 1));

				}
			}


		}
		return cnt;

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
		int a, b, wt;
		cin >> a >> b >> wt;
		g.addedge(a, b, wt);
	}

	int src, t;
	cin >> src >> t;




	//g.paths(src, "0", s, src);

	int* visited = new int[v]();


	cout << g.bfs(src, t, visited, 0);




}
