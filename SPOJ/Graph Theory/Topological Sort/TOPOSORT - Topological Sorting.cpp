//  Find lexographically minimum topological array

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


#define white  0
#define gray 1
#define black 2


//const int N = 1e5;


std::vector<int> graph[20000];
int color[20000];
int cycle;
vector<int>result;


void DFS(int u) {

	color[u] = gray;

	sort(all(graph[u]));

	for (int i=graph[u].size()-1;i>=0;i--) {

		int v=graph[u][i];

		if (color[v] == white) {
			DFS(v);
		}

		else if (color[v] == gray) {
			cycle = 1;
			return;
		}
	}

	color[u] = black;
	result.pb(u);
}

int main()
{
	int i, n, m;
	cin >> n >> m;

	for (i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].pb(y);
	}

	for (i = n; i > 0; i--) {

		if (color[i] == white)DFS(i);
	}

	if (cycle)cout << "Sandro fails." << endl;
	else {
		for (i = result.size() - 1; i >= 0; i--) {
			cout << result[i] << " ";
		}
		cout << endl;
	}
}
