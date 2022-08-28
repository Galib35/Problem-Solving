//   https://algo.codemarshal.org/contests/icpc-dhaka-20-preli/problems/E


#include<bits/stdc++.h>
using namespace std;
#define  ll long long
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
	ll t, i, n, tc = 0;
	cin >> t;
	while (t--) {
		tc++;

		cin >> n;

		std::vector<ll> a(n);

		ll ans1 = 0, ans2 = 0, j = 0, k = -1, p = 0, mx = -1e9;

		int m = 1;

		for (i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
			if (a[i] > 0)ans1 += a[i];

			if (a[i] > 0 && m) {
				p = 0;
				m = 0; continue;
			}

			if (a[i] < 0)p = 1;

			if (a[i] > 0 && p) {
				p = 0;
				ans2++;
			}

		}

		if (ans1 == 0)ans1 = mx;

		cout << "Case " << tc << ": " << ans1 << " " << ans2 << endl;


	}

}
