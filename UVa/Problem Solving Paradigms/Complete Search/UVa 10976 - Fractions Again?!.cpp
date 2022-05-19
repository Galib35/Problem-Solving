//    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1917
//    Brute Force

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

	while(cin>>n) {
		vector<pair<ll,ll> >v;
		for(i=n+1; i<=2*n; i++) {

			ll lcm;

			lcm=(i/(__gcd(i,n)))*n;

			if( lcm%(lcm/n-lcm/i)==0 ) {
				v.pb({lcm/(lcm/n-lcm/i),i});
			}


		}
		cout<<v.size()<<endl;
		for(int k=0; k<v.size(); k++) {
			cout<<"1/"<<n<<" = "<<"1/"<<v[k].ff<<" + "<<"1/"<<v[k].ss<<endl;
		}
	}
}


*/
    /** 1/k = 1/x + 1/y
            When x and y are equal, they are both 2k.
            
            1/k = 1/(2k) + 1/(2k)
            
            if x is larger than 2k, then y must be smaller than 2k.
            Since y can't be k, we only need to check y in [k+1, 2k]. 
            But how to compute x?
            1/x = 1/k - 1/y
                = (y-k) / (k*y)
            
            So if y-k divides k*y, then x = (k*y) / (y-k).
        */
  
 */
