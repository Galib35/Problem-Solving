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

int INF=1e6;
vector<pair<int, int> >graph[1001];
int dist[10001];



void Dijkstra(int source)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int > > >pq;

	pq.push({0, source});
	dist[source] = 0;

	while (!pq.empty()) {
		int u = pq.top().second;
		int curr_d = pq.top().first;
		pq.pop();

		for (pair<int, int>edge : graph[u]) {

			int v=edge.first;
			int edge_cost=edge.second;

			

			if((dist[u]+edge_cost)<dist[v]){

				dist[v]=dist[u]+edge_cost;
				pq.push({dist[v],v});
			}
		}
	}

}



int main()
{
	ll tc,i;
	cin>>tc;
	while(tc--){

		ll n,m,e,t;

//		fflush(stdin);

		cin>>n>>e>>t>>m;

		

		for(i=0;i<=3*n;i++){
			dist[i]=INF;
			graph[i].clear();
		}

		for(i=0;i<m;i++){

			ll u,v,w;
			cin>>u>>v>>w;

//			graph[u].push_back({v,w});
			graph[v].push_back({u,w});
		}

		Dijkstra(e);

		ll ans=0;

		for(i=1;i<=n;i++){
			if(dist[i]<=t)ans++;
		}

		cout<<ans<<endl;

	if(tc!=0)cout<<endl;


	}
}

/*
Those who are getting wa are running dijkstra from target to destination but running this from u -> v :P :P but the graph should be v -> u :P :P so please reverse the input graph then run your dijkstra :P :P


*/
