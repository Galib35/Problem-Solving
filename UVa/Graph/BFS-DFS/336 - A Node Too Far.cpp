#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
int ttl;
int vis_node_count = 0;

std::vector<int> graph[N];
int vis[N];
int dist[N];



void BFS(int src) {

	vis[src] = 1;
	dist[src] = 0;

	vis_node_count++;

	queue<int>q;
	q.push(src);

	while (!q.empty()) {
		int node = q.front();

		q.pop();

		for (int edge : graph[node]) {

			if (vis[edge] == 0) {

				vis[edge] = 1;
				dist[edge] = dist[node] + 1;
				q.push(edge);

				if (dist[edge] > ttl)return;

				vis_node_count++;

//				cout<<"edge = "<<edge<<endl;
			}
		}
	}

}



int main()
{
	int ca = 0;
	int u, v;
	while (1) {

		int n;
		cin >> n;

		if (n == 0)break;

		set<int>node;
		

		while (n--) {

			cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);

			node.insert(u);
			node.insert(v);
		}

		int tot=node.size();

		while (1) {
			int src;
			cin >> src >> ttl;

			if (src == 0 && ttl == 0)break;

			BFS(src);

			ca++;

			cout << "Case " << ca << ": " <<tot-vis_node_count << " nodes not reachable from node " << src << " with TTL = " << ttl << "." << endl;

			memset(dist, 0, sizeof(dist));
			memset(vis, 0, sizeof(vis));
			vis_node_count = 0;



		}

		for (auto i: node)graph[i].clear();




	}
}
