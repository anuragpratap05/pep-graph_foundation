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

void print(stack<int> &st)
{
	if (st.empty())
	{
		return;
	}

	int x = st.top();
	st.pop();

	print(st);
	cout << x << endl;
}

class graph
{
	list<int> *l;
	int v;
public:
	graph(int v)
	{
		this->v = v;
		l = new list<int>[v];

	}



	void addedge(int x, int y)
	{
		l[x].push_back(y);
		//l[y].push_back(x);
	}

	void paths(int src,  bool* visited, stack<int> &st )
	{



		visited[src] = true;


		for (auto nbr : l[src])
		{
			if (visited[nbr] == false)
			{
				paths(nbr,  visited  , st);

			}
		}
		st.push(src);





	}

	class LessThanByAge
	{
	public:
		bool operator()(const trplet& lhs, const trplet& rhs) const
		{
			return lhs.wt > rhs.wt;
		}
	};

	/*void bfs(int src,  bool* visited, int cnt)
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


	}*/
};

int main()
{




	int v, e;
	cin >> v >> e;
	graph g(v);
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b ;
		g.addedge(a, b);
	}








	//g.paths(src, "0", s, src);
	stack<int> st;

	bool* visited = new bool[v]();

	for (int i = 0; i < v; i++)
	{
		if (!visited[i])
			g.paths(i,  visited, st);
	}

	while (!st.empty())
	{ 
		cout << st.top() << endl;
		st.pop();
	}





	//g.paths(src, to_string(src) + "", visited, dest);




}
