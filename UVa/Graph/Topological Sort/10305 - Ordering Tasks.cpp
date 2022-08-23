//    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1246

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


const int N = 1000;

std::vector<int>graph[N];
vector<int>result;
int color[N];
int cycle;

void Topological_Sort(int u) {

	color[u] = gray;

	for (int v : graph[u]) {

//		deb2(u,v);

		if (color[v] == white)Topological_Sort(v);

	}

	color[u] = black;
	result.pb(u);
//	deb(u);
}

int main()
{
	int t, i, n, m, x, y;

	while (cin >> n >> m) {
		if (n == 0 && m == 0)return 0;

		for (i = 1; i <= n; i++) {

			graph[i].clear();
			color[i] = white;
		}

		for (i = 0; i < m; i++) {
			cin >> x >> y;
			graph[x].pb(y);
		}

		for (i = 1; i <= n; i++) {
			if (color[i] == white)Topological_Sort(i);
		}

		for (i = result.size() - 1; i >= 0; i--) {
			cout << result[i] << " ";
		}

		cout << endl;

		result.clear();
	}
}

