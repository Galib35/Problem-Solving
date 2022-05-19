//        https://onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=0&problem=2183&mosmsg=Submission+received+with+ID+27503192
//        Brute Force



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
int main()
{

	ll t,i,n,j,cs=0,m;

	while(cin>>n && n) {
		vector<double>v;
		cin>>m;
		int a[n+1];
		int b[m+1];
		for(i=0; i<n; i++) {
			cin>>a[i];
		}
		for(i=0; i<m; i++) {
			cin>>b[i];
		}
		double dr;
		for(i=0; i<m; i++) {
			for(j=0; j<n; j++) {
				dr=b[i]/(1.0*a[j]);
				v.pb(dr);
			}
		}
		sort(all(v));
		vector<double>v2;
		for(i=1; i<v.size(); i++) {
			v2.pb((v[i]*1.0)/v[i-1]);
		}
		sort(all(v2));
		cout<<fixed<<setprecision(2)<<v2[v2.size()-1]<<endl;
	}
}
