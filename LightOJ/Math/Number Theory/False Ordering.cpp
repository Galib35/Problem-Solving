#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t,i,j,n,ans,c=0,k=1000,cnt=0;
	vector<pair<ll, pair<ll,ll> > >v;
	for(i=1;i<=1000;i++){
		for(j=1;j*j<=i;j++){
			if(i%j==0)c+=2;
			if(j*j==i)c-=1;
		}
		v.push_back({c,{k,i}});
		c=0;k--;
	}
	sort(v.begin(),v.end());

	cin>>t;
	while(t--){
			cnt++;
		cin>>n;
		cout<<"Case "<<cnt<<": "<<v[n-1].second.second<<endl;
	}
}
