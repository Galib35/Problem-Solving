// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=3678&mosmsg=Submission+received+with+ID+27501665
// Simple Brute force

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
	//ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
	ll t,i,n;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<pair<string,pair<ll,ll> > >v;
		for(i=0; i<n; i++) {
			ll l,h;
			string s;
			cin>>s>>l>>h;
			v.pb({s,{l,h}});
		}
		ll q;
		cin>>q;
		while(q--) {
			ll k,c=0;
			string s;
			cin>>k;

			for(i=0; i<n; i++) {
				if(k<=v[i].ss.ss && k>=v[i].ss.ff) {
					c++,s=v[i].ff;
				}
			}
			if(c==1) {
				cout<<s<<endl;
			} else {
				cout<<"UNDETERMINED"<<endl;
			}
		}
		if(t)cout<<endl;
	}
}

/*
Print extra line, if it is not the last test case:D
*/
