//   https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=540
/*
Idea:
1.Free node(no edge) ---> Acorn
2. Check cyle
  (i) if cycle-> mark parent
  (ii) else ---->Tree

*/

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



int parent[40];
int size[400000];
int vis[40];
int mark[40];

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
	else mark[parent[a]] = 1;
}

int main()
{
	ll n, m, i, t;
	cin >> t;
	while (t--)
	{


		for (i = 0; i < 26; i++)make_set(i);
		while (1) {
			string s;
			cin >> s;
			ll u, v;
			if (s[0] == '*')break;
			u = s[1] - 'A';
			v = s[3] - 'A';

			vis[u] = 1;
			vis[v] = 1;
			union_set(u, v);

		}

		string ss;
		std::vector<ll> v;
		cin >> ss;
		fo(i, ss.size()) {
			if (ss[i] >= 'A' && ss[i] <= 'Z') {
				v.pb(ss[i] - 'A');
			}
		}

		map<ll, ll>mp;
		ll ans = 1;
		ll acorn = 0, tree = 0;

		for (int j = 0; j < v.size(); j++) {
			//	ll k = parent[i];
			i = v[j];
			if (vis[i] == 0) {
				acorn++; continue;
			}

			if (mark[i])continue;

			ll k = find_set(i);

			mp[k]++;


		}

		tree = mp.size();
		cout << "There are " << tree << " tree(s) " << "and " << acorn << " acorn(s)." << endl;
		mem(parent);
		mem(vis);
		mem(mark);
	}
}
