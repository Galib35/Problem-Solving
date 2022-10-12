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

int graph[1000][1000];
int cost[1000][1000];
int INF=1e8;
int n,m;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool isValid(int x,int y){

	return (x>=0 && y>=0 && x<n && y<m );

}


void Dijkstra(int srcx,int srcy){

	cost[srcx][srcy]=graph[0][0];

	priority_queue<pair<int,pii>, std::vector<pair<int,pii> > , greater<pair<int,pii> > >pq;

	pq.push({0,{srcx,srcy}});


	while(!pq.empty()){

		int ux=pq.top().ss.ff;
		int uy=pq.top().ss.ss;

		pq.pop();

		for(int i=0;i<4;i++){
			
				int nextx=ux+dx[i];
				int nexty=uy+dy[i];

				if(isValid(nextx,nexty) && (cost[nextx][nexty]>(cost[ux][uy]+graph[nextx][nexty])) ){

					cost[nextx][nexty]=cost[ux][uy]+graph[nextx][nexty];

					pq.push({cost[nextx][nexty],{nextx,nexty}});

//					deb2(nextx,nexty);
//					deb(cost[nextx][nexty]);
				}
			}
		}
	}



int main()
{
	int i,t,j;
	cin>>t;
	while(t--){

	

		cin>>n>>m;

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){

				cin>>graph[i][j];

				cost[i][j]=INF;
			}
		}

		Dijkstra(0,0);

		cout<<cost[n-1][m-1]<<endl;

	}
}

/*

Corner Case: 1st e 0 thakte pare.

1
3 4
3 2 1 1
1 0 4 1
9 9 9 2

*/
