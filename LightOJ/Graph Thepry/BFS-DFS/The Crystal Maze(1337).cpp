#include<bits/stdc++.h>
using namespace std;
#define  ll  long long
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


//vector<int>graph[100001];
int N,M;
int a,b; //N=row M=collum
bool vis[505][505];
int dist[505][505];
char ch[505][505];
int crystal[505][505];
vector<pair<int,int>>v;

bool isValid (int x,int y)
{
	if(x<1 || x>N || y<1 || y>M) {
		return false;
	}
	if(ch[x][y]=='#') {
		return false;
	}

	if(vis[x][y]==1) {
		return false;
	}

	return true;
}


int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};


int  BFS(int sourceX, int sourceY)
{
//   deb2(sourceX,sourceY);
	v.pb({sourceX,sourceY});
	int d=0;
	vis[sourceX][sourceY]=1;
	dist[sourceX][sourceY]=0;
	queue<pair<int,int> >q;
	q.push({sourceX, sourceY});

	while(!q.empty()) {

		int nodeX=q.front().first;
		int nodeY=q.front().second;
		q.pop();

		for(int i=0; i<4; i++) {
			if (isValid (nodeX+dx[i], nodeY+dy[i])) {

				int nextX=nodeX+dx[i];
				int nextY=nodeY+dy[i];
				//             deb2(nextX,nextY);
				//	if(vis[next]==0){
				vis[nextX][nextY]=1;
				dist[nextX][nextY]=dist[nodeX][nodeY]+1;

				if(ch[nextX][nextY]=='C') {
					d++;
//               deb(d);
				}
				v.pb({nextX,nextY});
				q.push({nextX, nextY});
				//     	   }
			}
		}
	}
	return d;
}
int main()
{
	int i,t,cs=1,q,j;
	cin>>t;
	while(t--) {
		cin>>N>>M>>q;
		for(i=1; i<=N; i++) {
			for(j=1; j<=M; j++) {
				cin>>ch[i][j];
			}
		}
		for(i=1; i<=N; i++) {
			for(j=1; j<=M; j++) {
				if(vis[i][j] || ch[i][j]=='#' || ch[i][j]=='C') {
					continue;
				} else {
					int d=BFS(i,j);
					//               int Size=v.size();
					for(int k=0; k<v.size(); k++) {
						//			                   deb2(v[k].ff,v[k].ss);
						crystal[v[k].ff][v[k].ss]=d;
						//				deb(d);
						vis[v[k].ff][v[k].ss]=1;
					}
//					cout<<endl;
					v.clear();
				}
			}
		}

		cout<<"Case "<<cs<<":"<<endl;
		while(q--) {
			int x,y;
			cin>>x>>y;
			cout<<crystal[x][y]<<endl;
		}
		mem(vis);
		mem(dist);
		mem(crystal);
		mem(ch);
		cs++;
	}
}

