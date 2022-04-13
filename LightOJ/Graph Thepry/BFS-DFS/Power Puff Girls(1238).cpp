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
int N,M; //N=row M=collum
bool vis[101][101];
int dist[101][101];
char ch[101][101];

bool isValid (int x,int y)
{
	if(x<0 || x>=N || y<0 || y>=M) {
		return false;
	}
	if(ch[x][y]=='#' || ch[x][y]=='m') {
		return false;
	}
	if(vis[x][y]==1) {
		return false;
	}

	return true;
}


int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};


int BFS(int sourceX, int sourceY)
{
	int d1,d2,d3;
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
				//	if(vis[next]==0){
				vis[nextX][nextY]=1;
				dist[nextX][nextY]=dist[nodeX][nodeY]+1;
				if(ch[nextX][nextY]=='a' ) {
					d1=dist[nextX][nextY];
				}
				if(ch[nextX][nextY]=='b' ) {
					d2=dist[nextX][nextY];
				}
				if( ch[nextX][nextY]=='c' ) {
					d3=dist[nextX][nextY];
				}
				q.push({nextX, nextY});
				//     	   }
			}
		}
	}
	return max(d1,max(d2,d3));
}
int main()
{
	int t,j,i;
	cin>>t;
	int ce=1;
	while(t--) {

		cin>>N>>M;
		for(i=0; i<N; i++) {
			for(j=0; j<M; j++) {
				cin>>ch[i][j];
			}
		}
		int d=100;
		for(i=0; i<N; i++) {
			for(j=0; j<M; j++) {
				if(ch[i][j]=='h') {
					d= BFS(i,j);
				}
			}
		}
		cout<<"Case "<<ce<<": "<<d<<endl;
		mem(dist);
		mem(vis);
		mem(ch);
		ce++;
	}
}
