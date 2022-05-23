//    https://onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=0&problem=382&mosmsg=Submission+received+with+ID+27512733
//    6 loop Brute Force

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
	ll t,i,n;
	bool fl=0;

	while(cin>>n && n) {
		ll a[n+1];
		for(i=0; i<n; i++) {
			cin>>a[i];
		}
		if(fl)cout<<endl;
    
		for(i=0; i<n-5; i++) {
			for(int j=i+1; j<n-4; j++) {
				for(int k=j+1; k<n-3; k++) {
					for(int l=k+1; l<n-2; l++) {
						for(int m=l+1; m<n-1; m++) {
							for(int z=m+1; z<n; z++) {
								cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[l]<<" "<<a[m]<<" "<<a[z]<<endl;
							}
						}
					}
				}
			}
		}
		fl=1;
//		cout<<endl;


	}
}
