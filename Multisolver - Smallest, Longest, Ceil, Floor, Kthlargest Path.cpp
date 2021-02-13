# pep-graph_foundation
#include<bits/stdc++.h>
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

	string spath;
	int spathwt = INT_MAX;
	string lpath;
	int lpathwt = INT_MIN;
	string cpath;
	int cpathwt = INT_MAX;
	string fpath;
	int fpathwt = INT_MIN;



	//priority_queue<pi, vector<pi>, greater<pi> > pq;

	priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>> > pq;

	void has_path(int src, int dest, bool* visited, string psf, int wsf, int a, int k)
	{
		if (src == dest)
		{
			if (wsf < spathwt)
			{
				spathwt = wsf;
				spath = psf;
			}

			if (wsf > lpathwt)
			{
				lpathwt = wsf;
				lpath = psf;
			}

			if (wsf > a and wsf < cpathwt)
			{
				cpathwt = wsf;
				cpath = psf;
			}

			if (wsf<a and wsf>fpathwt)
			{
				fpathwt = wsf;
				fpath = psf;
			}
			if (pq.size() < k)
			{
				pq.push(make_pair(wsf, psf));
			}
			else
			{
				int phla = pq.top().first;
				if (wsf > phla)
				{
					pq.pop();
					pq.push(make_pair(wsf, psf));

				}
			}

			//cout << psf << endl;
			return ;
		}




		visited[src] = true;
		for (auto x : l[src])
		{
			int nbr = x.first;
			int wt = x.second;
			if (!visited[nbr])
			{
				has_path(nbr, dest, visited, psf + to_string(nbr), wsf + wt, a, k);

			}
		}
		visited[src] = false;


		//return false;

	}



};

int main()
{


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

	int a, k;
	cin >> a >> k;

	bool* visited = new bool[v]();

	g.has_path(src, dest, visited, to_string(src) + "", 0, a, k);
	cout <<"Smallest Path = "<< g.spath << "@" << g.spathwt << endl;
	cout <<"Largest Path = "<< g.lpath << "@" << g.lpathwt << endl;

	cout << "Just Larger Path than " << a << " = " << g.cpath << "@" << g.cpathwt << endl;
	cout << "Just Smaller Path than " << a << " = " << g.fpath << "@" << g.fpathwt << endl;
	cout << k << "th largest path = " << g.pq.top().second << "@" << g.pq.top().first;











}
