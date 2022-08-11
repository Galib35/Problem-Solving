//   https://lightoj.com/problem/histogram
//   Time complexicity: O(n)

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
	ll t, n, i,cs=0;
	cin >> t;
	while (t--) {
		cs++;
		cin >> n;
		std::vector<ll> v(n);

		stack<ll>st;

		vector<ll>left(n);
		vector<ll>right(n);

		for (i = 0; i < n; i++)cin >> v[i];

		for (i = 0; i < n; i++) {
			st.push(i);

			while (!st.empty()) {
				
				if (v[st.top()] >= v[i]) {
					st.pop();
				}

				else {
					left[i] = st.top() + 1;
					break;
				}
			}

			if (st.empty())left[i] = 0;

			st.push(i);
		}

		while(!st.empty()){
			st.pop();
		}

		for (i = n - 1; i >= 0; i--) {
			st.push(i);

			while (!st.empty()) {
				if (v[st.top()] >= v[i]) {
					st.pop();
				}

				else {
					right[i] = st.top() - 1;
					break;
				}
			}

			if (st.empty())right[i] = n-1;

			st.push(i);
		}

		ll ans = 0;

		for (i = 0; i < n; i++) {
//			deb2(left[i],right[i]);
			ans = max((right[i] - left[i] + 1) * v[i], ans);
		}

		cout<<"Case "<<cs<<": ";
		cout << ans << endl;
	}

}
