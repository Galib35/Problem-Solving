//  https://lightoj.com/problem/discover-the-web

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
	ll t, n, i, cs = 0;
	cin >> t;
	while (t--) {
		cs++;
		cout << "Case " << cs << ":" << endl;


		string s1, s2;
		stack<string>backward;
		stack<string>forward;

		backward.push("http://www.lightoj.com/");

		while (1) {
			cin >> s1;

			if (s1 == "QUIT")break;
			else if (s1 == "FORWARD") {
				if (forward.empty())cout << "Ignored" << endl;
				else {
					cout << forward.top() << endl;
					backward.push(forward.top());
					forward.pop();
				}
			}

			else if (s1 == "BACK") {
				if (backward.top() == "http://www.lightoj.com/")cout << "Ignored" << endl;
				else {
					forward.push(backward.top());
					backward.pop();
					cout << backward.top() << endl;
				}
			}

			else if (s1 == "VISIT") {
				cin >> s2;

				backward.push(s2);
				/*
				  However ,the 'VISIT' query is a bit different. We will have
				 to take a new url as input and empty the FORWARD stack ,
				 then push the inputted url to the forward stack*/


				while (!forward.empty()) {
					forward.pop();
				}

				cout << s2 << endl;
			}


		}


	}

}
