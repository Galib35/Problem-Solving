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

int N=55;
int dist[55][55][55];
int vis[55][55][55];

int dx[]= {0,0,0,0,-1,1};
int dy[]= {0,0,-1,1,0,0};
int dz[]= {-1,1,0,0,0,0};

bool fl;
bool BFS(string str1,string str2)
{
	fl=0;
	if(vis[str1[0]-'a'][str1[1]-'a'][str1[2]-'a']==-1) {
		return 0;
	}
	if(str1==str2) {
		return 1;
	}
	vis[str1[0]-'a'][str1[1]-'a'][str1[2]-'a']=1;

	dist[str1[0]-'a'][str1[1]-'a'][str1[2]-'a']=0;
	queue<pair<int,pair<int,int> > >q;
	q.push({str1[0]-'a',{str1[1]-'a',str1[2]-'a'}});

	while(!q.empty()) {
		int x1=q.front().ff;
		int x2=q.front().ss.ff;
		int x3=q.front().ss.ss;

		//	deb2(x1,x2);
//		deb(x3);
		q.pop();

		for(int i=0; i<6; i++) {
			int nextX=(x1+dx[i])%26;
			int nextY=(x2+dy[i])%26;
			int nextZ=(x3+dz[i])%26;

			if(nextX<0) {
				nextX+=26;
			}
			if(nextY<0) {
				nextY+=26;
			}
			if(nextZ<0) {
				nextZ+=26;
			}

			if(vis[nextX][nextY][nextZ]==0) {
				vis[nextX][nextY][nextZ]=1;
				dist[nextX][nextY][nextZ]=dist[x1][x2][x3]+1;
				q.push({nextX,{nextY,nextZ}});
				if( vis[str2[0]-'a'][str2[1]-'a'][str2[2]-'a']==1) {
					fl=1;
					return 1;
				}

//				deb(dist[nextX][nextY][nextZ]);
			}
		}
	}
	return fl;
}




int main()
{
	int t,i,j,k,n,m,cs=0;
	cin>>t;
	while(t--) {
		cs++;
		fl=0;
		string str1,str2,s1,s2,s3;
		cin>>str1>>str2;
//		deb2(str1,str2);
		cin>>n;
//		deb(n);
		for(i=0; i<n; i++) {
			cin>>s1>>s2>>s3;
			for(j=0; j<s1.size(); j++) {
				for(k=0; k<s2.size(); k++) {
					for(m=0; m<s3.size(); m++) {
						vis[s1[j]-'a'][s2[k]-'a'][s3[m]-'a']=-1;
					}
				}
			}
		}
		/*	if(str1==str2) {
				cout<<"Case "<<cs<<": "<<0<<endl;
				continue;
			}
		*/
		fl=BFS(str1,str2);

		if(fl) {
			cout<<"Case "<<cs<<": "<<dist[str2[0]-'a'][str2[1]-'a'][str2[2]-'a']<<endl;;
		} else {
			cout<<"Case "<<cs<<": "<<-1<<endl;
		}
		mem(dist);
		mem(vis);
	}
}
