//    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=868
//    



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
int vis[200][200];
int main()
{
	int t,i,cs=0,j;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int a[n+1];
		for(i=0; i<=n; i++) {
			cin>>a[i];
		}
		int d,k;
		cin>>d>>k;
		ll cnt=0;
		
//     Main concept		
		for(i=1;; i++) {
			cnt+=i*d;
			ll sum=0;
			for(j=0; j<=n; j++) {
				sum+=a[j]*(ll)(pow(i,j)+.5);
				//		deb2(i,sum);
			}
			if(cnt>=k) {
				cout<<sum<<endl;
				break;
			}
		}
	}
}
/*
For example, in the sample input line '4 3 0 0 0 23', the 4 means that the polynomial goes up to x^4. The following numbers then describe the polynomial in increasing powers.
In the given example, the polynomial is:
3(x^0) + 0(x^1) + 0(x^2) + 0(x^3) + 23(x^4)
The x value represents the previously found kth term. So if the kth term was found to be 3, as it is in the first sample input, you would evaluate the polynomial to
3(3^0) + 0(3^1) + 0(3^2) + 0(3^3) + 23(3^4) = 1866, the correct sample output.

Hope this clears the question up for people.
*/
