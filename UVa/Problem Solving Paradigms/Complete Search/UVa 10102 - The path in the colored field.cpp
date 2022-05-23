//       https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1043
//       Iterativr Brute Force

#include<bits/stdc++.h>
using namespace std;
#define ll long long
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



int main()
{
	int i,j,n;
	while(cin>>n) {
		char ch[n+1][n+1];
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				cin>>ch[i][j];
			}
		}
		int mx=0;
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				if(ch[i][j]=='1') {
					int mn=1e9;

					for(int k=0; k<n; k++) {
						for(int l=0; l<n; l++) {
							if(ch[k][l]=='3') {
								mn=min(mn,abs(i-k)+abs(j-l));
							}
						}
					}
					mx=max(mx,mn);
				}
			}
		}
		cout<<mx<<endl;
	}
}
