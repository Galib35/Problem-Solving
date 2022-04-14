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
int N=1100,M=1100;
int a,b; //N=row M=collum
bool vis[1100][1100];
int dist[1100][1100];
// ch[1001][1001];

bool isValid (int x,int y)
{
	if(x<1 || x>N || y<1 || y>M) {
		return false;
	}

	if(vis[x][y]==1) {
		return false;
	}

	return true;
}


int dx[]= {1,1,-1,-1,2,-2,2,-2};
int dy[]= {2,-2,2,-2,1,1,-1,-1};


void BFS(int sourceX, int sourceY)
{
	int d;
	vis[sourceX][sourceY]=1;
	dist[sourceX][sourceY]=0;
	queue<pair<int,int> >q;
	q.push({sourceX, sourceY});

	while(!q.empty()) {

		int nodeX=q.front().first;
		int nodeY=q.front().second;
		q.pop();

		for(int i=0; i<8; i++) {
			if (isValid (nodeX+dx[i], nodeY+dy[i])) {
				int nextX=nodeX+dx[i];
				int nextY=nodeY+dy[i];
				//	if(vis[next]==0){
				vis[nextX][nextY]=1;
				dist[nextX][nextY]=dist[nodeX][nodeY]+1;

				//			if(vis[a][b])return dist[a][b];
				q.push({nextX, nextY});
				//     	   }
			}
		}
	}
//	return max(d1,max(d2,d3));
}
int main()
{
	BFS(1,1);
	int t,j,i;
	cin>>t;
	int ce=1;
	while(t--) {

		cin>>a>>b;
		cout<<dist[a][b]<<endl;

	}
}
