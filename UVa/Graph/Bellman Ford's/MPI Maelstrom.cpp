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

std::vector<pii> Graph[10009];
ll dist[10009];
int node;
bool negative_weight_cycle = 0;
int INF=1e6;


void BellmenFord(int src) {

	dist[src] = 0;

	for (int i = 0; i < node; i++) {

		for (int u = 1; u <= node; u++) {

			for (pair<int,int> edge_cost : Graph[u]) {

				int v = edge_cost.first;
				int cost = edge_cost.second;

				if ((dist[u] + cost) < dist[v]) {

					dist[v] = dist[u] + cost;
				}
			}
		}

  
	}

	// Check whether Negative Weight cycle exist or not


	for (int u = 0; u < node; u++) {

		for (pii edge_cost : Graph[u]) {

			int v = edge_cost.first;
			int cost = edge_cost.second;

			if ((dist[u] + cost) < dist[v]) {

				dist[v] = dist[u] + cost;

				negative_weight_cycle = 1;
			}
		}
	}




}

int main()
{
	int  i;

	cin >> node;

	for(i=1;i<=node;i++)dist[i]=INF;

	for(i=2;i<=node;i++){
		for(int j=1;j<i;j++){

			string s,s1="x";
			stringstream ss;

			cin>>s;

			if(s==s1)continue;

			ss<<s;

			int p;
		ss>>p;

		Graph[i].pb({j,p});
		Graph[j].pb({i,p});


		}
	}


	BellmenFord(1);

	
	ll ans=0;

		for(i=1;i<=node;i++){
//			cout<<i<<" : "<<dist[i]<<endl;

			ans=max(ans,dist[i]);


		
	}

	cout<<ans<<endl;

}
