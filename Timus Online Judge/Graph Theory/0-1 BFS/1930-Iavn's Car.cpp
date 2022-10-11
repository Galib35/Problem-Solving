// Balsal Code 
// Normally Dijkstra er moto kore korsi.


#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  fo(i,n)  for(i=0;i<n;i++)
#define  deb(x)  cout<< #x << "=" << x <<endl;
#define  deb2(x,y)  cout<< #x <<"="<< x<<","<< #y << "=" <<y<<endl;
#define  pb push_back
#define  ff first
#define  ss second
#define  pii pair<int,int>
#define  pll  pair<ll,ll>
#define  all(v) v.begin(),v.end()
#define  mem(x) memset(x,0,sizeof(x))
#define  itr(it,a) for(auto it=a.begin(); it!=a.end(); it++)

const int INF = 1e7;
std::vector<int>graph[200000];
int cost[200000];
map<pii, int>mp;
int direction[200000];  // 1->forward , 0-> reverse, 2-> both



void Dijkstra(int src) {

	cost[src] = 0;
	direction[src] = 2;
	priority_queue<pii, vector<pii>, greater<pii> >q; // { edge_cost,node}

	q.push({0, src});

	while (!q.empty()) {

		pair<int, int>current_edge;

		current_edge = q.top();
		q.pop();

		int u = current_edge.ss;
		int u_cost = current_edge.ff;

		for (auto v : graph[u] ) {


			if (direction[u] == mp[ {u, v}]) {


			}


			if ((cost[u] + 1) == cost[v]) {

				if (direction[u] == 0 && mp[ {u, v}] == 1) {

					direction[v] = 2;

					cost[v] = cost[u] + 1;

				}

				else if (direction[u] == 1 && mp[ {u, v}] == 0) {

					direction[v] = 2;

					cost[v] = cost[u] + 1;

				}


				else cost[v] = cost[u];

				direction[v] = 2;

				q.push({cost[v], v});

			}


			if ((cost[u] + 1) < cost[v]) {

				if (direction[u] == 1 && mp[ {u, v}] == 0) {
					cost[v] = cost[u] + 1;
					direction[v] = mp[ {u, v}];
				}

				else if (direction[u] == 0 && mp[ {u, v}] == 1) {
					cost[v] = cost[u] + 1;
					direction[v] = mp[ {u, v}];
				}


				else	cost[v] = cost[u];

				direction[v] = mp[ {u, v}];

				/*	deb2(u,v);
				deb2(direction[u],direction[v]);
					deb2(cost[u],cost[v]);*/



				q.push({cost[v], v});

			}

/*
			deb2(u, v);
			deb2(direction[u], direction[v]);
			deb2(cost[u], cost[v]);*/



		}
	}


}


int main()
{
	int town, road, i;

	for (i = 0; i < 200000; i++) {
		cost[i] = INF;
		direction[i] = -1;
	}

	cin >> town >> road;

	for (i = 0; i < road; i++) {

		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);

		mp[ {u, v}] = 1;

	}

	int start_node ;
	int destination_node;


	cin >> start_node >> destination_node;

	Dijkstra(start_node);

	/*for (i = 1; i <= town; i++) {

		deb(cost[i]);

	}*/


	cout << cost[destination_node];
}
