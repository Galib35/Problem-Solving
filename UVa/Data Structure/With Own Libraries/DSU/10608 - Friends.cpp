//  https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1549

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

ll mod = 1000000007;

int parent[400000];
int size[400000];

void make_set(int v) {
	parent[v] = v;
}
int find_set(int v) {
	if (parent[v] == v)return v;
	return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if (a != b) {
		parent[b] = a;
	}
}

int main()
{
	ll n, m, i, t;
	cin >> t;
	while (t--)
	{

		cin >> n >> m;

		for (i = 1; i <= n; i++)make_set(i);
		for (i = 0; i < m; i++) {
			ll u, v;
			cin >> u >> v;
			//	make_set(u);
			//	make_set(v);

			union_set(u, v);

		}
		map<ll, ll>mp;
		ll ans = 1;

		for (i = 1; i <= n; i++) {
			//	ll k = parent[i];
			ll k = find_set(i);
			mp[k]++;
			ans = max(ans, mp[k]);

		}

		cout << ans << endl;

		mem(parent);
	}
}
