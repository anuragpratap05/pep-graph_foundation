# pep-graph_foundation#include<bits/stdc++.h>
using namespace std;

class trplet
{
public:
	int wt;
	int to;
	int  node;
	trplet()
	{
		wt = 0;
		to = 0;
		node = 0;
	}
};

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

	class LessThanByAge
	{
	public:
		bool operator()(const trplet& lhs, const trplet& rhs) const
		{
			return lhs.wt > rhs.wt;
		}
	};

	void bfs(int src,  bool* visited, int cnt)
	{

		priority_queue<trplet, vector<trplet>, LessThanByAge  > q;
		//visited[src] = true;
		trplet x;
		x.node = 0;
		x.to = -1;
		x.wt = 0;


		q.push(x);

		while (!q.empty())
		{
			auto p = q.top();
			q.pop();
			int node = p.node;
			//cout << node;
			int to = p.to;

			int wt = p.wt;

			if (visited[node] == true)
			{
				continue;
			}

			visited[node] = true;

			cnt++;
			if (p.to != -1)
				cout << "[" << p.node << "-" << p.to << "@" << p.wt << "]" << endl;


			//visited[node] = true;



			for (auto z : l[node])
			{
				if (visited[z.first] == false)
				{
					//visited[z.first] = true;
					trplet y;
					y.node = z.first;
					y.to =  node;
					y.wt = z.second ;
					q.push(y);

				}
			}


		}


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






	//g.paths(src, "0", s, src);

	bool* visited = new bool[v]();



	g.bfs(0,  visited, 0);




}
