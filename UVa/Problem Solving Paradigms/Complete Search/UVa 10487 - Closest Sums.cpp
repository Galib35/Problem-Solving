//     https://onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=0&problem=1428&mosmsg=Submission+received+with+ID+27503046
//     Brute Force

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

	ll t,i,n,j,cs=0;

	while(cin>>n && n) {
		set<ll>s;
		cs++;
		ll a[n+1];
		for(i=0; i<n; i++) {

			cin>>a[i];
		}

		for(i=0; i<n; i++) {
			for(j=i+1; j<n; j++) {
				s.insert(a[i]+a[j]);
			}
		}
		int q;
		cout<<"Case "<<cs<<":"<<endl;
		cin>>q;

		while(q--) {

			ll p,ans;
			cin>>p;
			auto it=s.lower_bound(p);
			if(it==s.begin()) {
				ans=*it;
			} else if(it==s.end()) {
				ans=*(--it);
			} else {
				auto it2=it;
				it--;
				if(llabs(p-*it)>llabs(p-*(it2))) {
					ans=*it2;
				} else {

					ans=*it;
				}
			}

			cout<<"Closest sum to "<<p<<" is "<<ans<<"."<<endl;

		}
	}
}
