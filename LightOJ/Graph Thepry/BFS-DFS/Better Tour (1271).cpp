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

int INF = 1e8;

std::vector<int> graph[60000];
int vis[60000];
int parent[60000];
int source;


void Path_Print(int u) {

	if (u == source) {
		cout << source << " ";
		return;

	}


	Path_Print(parent[u]);

	cout << u << " ";


}


void BFS(int s, int destination) {

	vis[s] = 1;

	queue<int>q;

	q.push(s);

	while (!q.empty()) {

		int node = q.front();
		q.pop();


		for (auto edge : graph[node]) {

			if (!vis[edge]) {

				vis[edge] = 1;
				q.push(edge);

				parent[edge] = min(parent[edge], node);

				if (edge == destination)return;

//				deb2(node,edge);
//				deb2(parent[node],parent[edge]);
			}
		}
	}
}




int main()
{
	int n, ca = 0, i, t;
	cin >> t;
	while (t--) {

		ca++;

		cin >> n;

		vector<int>node;

		int destination;

		for (i = 0; i <= 50000; i++) {

			graph[i].clear();
			parent[i] = INF;
		}



		for (i = 0; i < n; i++) {
			int x;
			cin >> x;

			node.pb(x);

			if (i == 0)source = x;
			if (i == n - 1)destination = x;

			if (i != 0) {
				graph[node[i]].push_back(node[i - 1]);
				graph[node[i - 1]].push_back(node[i]);
			}
		}

		for (i = 0; i < n; i++) {

			sort(all(graph[node[i]]));
		}


		BFS(source, destination);

		cout << "Case " << ca << ":" << endl;

		Path_Print(destination);

		cout << endl;


		mem(vis);
		mem(parent);
	}
}
