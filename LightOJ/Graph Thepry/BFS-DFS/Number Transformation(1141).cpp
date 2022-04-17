#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  fo(i,n) for(i=0;i<n;i++)
#define  deb(x) cout<< #x << "=" << x <<endl;
#define  deb2(x,y) cout<< #x <<"="<< x<<","<< #y << "=" <<y<<endl;
#define  pb push_back
#define  ff first
#define  ss second
#define  pii pair<int,int>
#define  pll pair<ll,ll>
#define  all(v) v.begin(),v.end()
#define  mem(x) memset(x,0,sizeof(x))
#define  itr(it,a) for(auto it=a.begin(); it!=a.end(); it++)
int m;
vector<ll>v[1009];
int dist[10005];
int vis[1005];
void primeFactor(int nn)
{
	int n=nn;
	for(int  i=2; i*i<=n; i++) {
		int add=0;
		while(n%i==0) {
			
			add=i;
			n/=i;
		}
		if(add) {
			v[nn].pb(add);
		}
		
	}
	if(n!=1 && n!=nn) {
		
		v[nn].pb(n);
	}

}
int   BFS(int source)
{

	vis[source]=1;
	dist[source]=0;
	queue<int>q;
	q.push(source);
	int next=0;
	while(!q.empty()) {
		int node=q.front();
//		deb(node);

		q.pop();
		for(int i=0; i<v[node].size(); i++) {
//                     deb(node);
			next=node+v[node][i];
//		deb2(v[node][i],next);
			if(vis[next]==0 && next<=m) {
				vis[next]=1;
				dist[next]=dist[node]+1;
//				deb2(node,next);
//				deb2(dist[node],dist[next]);
				q.push(next);
				if(next==m) {
					return dist[next];
				}
//				deb(m);
			}

		}
	}


	return -1;
}



int main()
{
	ll t,i,ca=0,n;
	cin>>t;
	for(i=2; i<=1005; i++) {
		primeFactor(i);
	}
//	primeFactor(8);
	while(t--) {
		ca++;
		cin>>n>>m;


		if(n==m) {
			cout<<"Case "<<ca<<": "<<0<<endl;
			continue;
		}

		cout<<"Case"<<" "<<ca<<": "<< BFS(n)<<endl;
		mem(vis);
		mem(dist);

	}
}
