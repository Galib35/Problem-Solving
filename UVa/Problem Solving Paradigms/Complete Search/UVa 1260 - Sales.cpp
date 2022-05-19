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

	ll t,i,n,j;
	cin>>t;
	while(t--) {
		cin>>n;
		ll a[n+1];
		vector<ll>v;
		for(i=0; i<n; i++) {
			cin>>a[i];
		}
		for(i=1; i<n; i++) {
			ll cnt=0;
			for(j=0; j<i; j++) {
				if(a[i]>=a[j]) {
					cnt++;
				}
			}
			v.pb(cnt);
		}
		ll sum=0;
		for(i=0; i<n-1; i++) {
			sum+=v[i];
		}
		cout<<sum<<endl;
	}
}
