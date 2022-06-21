//  https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1626


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

//int parent[300009];

map<string, ll>mp;
map<string, string>parent;
std::vector<string> v;

void make_set(string v) {
	parent[v] = v;
}

string find_set(string v) {
	if (parent[v] == v)return v;

	return parent[v] = find_set(parent[v]);
}

void union_sets(string a, string b) {
	a = find_set(a);
	b = find_set(b);

	if (a != b) {

		parent[b] = a;
	}

}


int main()
{
	ll n, m, i, q;
	while (cin >> n >> m) {
		if (n == 0 && m == 0)break;

		for (i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.pb(s);
			make_set(s);
			//mp[s] = -1;
		}
		for (i = 0; i < m; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			union_sets(s1, s2);
		}

		ll mx = 1;
		for (auto x : v) {
			string w = find_set(x);
			mp[w]++;
			mx = max(mx, mp[w]);

		}

		cout << mx << endl;

		mp.clear();
		v.clear();
		parent.clear();


	}

}
