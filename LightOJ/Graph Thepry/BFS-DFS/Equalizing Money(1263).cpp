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

std::vector<int>graph[2000];
vector<int>weight;
int vis[2000];
int sum = 0, cnt_people = 0;

int n, m;

int not_divided = 0;


void DFS(int u) {

	if (!vis[u]) {

		sum += weight[u - 1];
		cnt_people++;
		vis[u] = 1;
	}
	else return;


	for (auto v : graph[u]) {
		if (!vis[v])DFS(v);
	}
}

int main()
{
	ll t, i, j, ca = 0;
	cin >> t;
	while (t--) {

		ca++;

		ll tot = 0;

		cin >> n >> m;

		for (i = 0; i < n; i++) {
			int x;
			cin >> x;
			weight.pb(x);

			tot += x;

			graph[i].clear();
		}



		graph[i].clear();  // For i==n



		for (i = 0; i < m; i++) {

			int x, y;
			cin >> x >> y;

			graph[x].pb(y);
			graph[y].pb(x);


		}

		if (tot % n != 0) {
			cout << "Case " << ca << ": " << "No" << endl;

		}
		else {

			for (i = 1; i <= n; i++) {

				sum = 0;
				cnt_people = 0;


				if (!vis[i]) {
					DFS(i);
					int per_amount = ((tot) / n) * cnt_people;

					if (sum % cnt_people != 0 || sum != per_amount) not_divided = 1;

//				deb2(sum,cnt_people);

				}
			}

			if (not_divided)cout << "Case " << ca << ": " << "No" << endl;
			else cout << "Case " << ca << ": " << "Yes" << endl;
		}

		mem(vis);
		weight.clear();
		not_divided = 0;
	}

}
