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

int failure[1000009];
std::vector<int> ans;
void failure_function(string pattern) {

	int i, j;
	int n = pattern.size();
	failure[0] = 0;

	for (i = 1; i < n; i++) {

		j = failure[i - 1];

		while (j > 0  &&  pattern[i] != pattern[j])j = failure[j - 1];

		if (pattern[i] == pattern[j])j++;

		failure[i] = j;


	}


}

void KMP(string s, string pattern)
{
	int n = s.size();
	int m = pattern.size();

	int i = 0, j = 0;

	failure_function(pattern);

	while (i < n) {

		if (s[i] == pattern[j]) {
			i++;
			j++;

			if (j == m){
				ans.push_back(i-m+1);
			};
		}

		else {

			if (j == 0)i++;

			else j = failure[j - 1];

		}


	}

//	return false;
}





int main()
{
	int t, i;

	cin >> t;
	while (t--) {

		string s, pattern;


		cin >> s >> pattern;


		int n=pattern.size();

		for(i=0;i<=n;i++){

			failure[i]=0;
		}

		KMP(s,pattern);

		if(ans.size()){

			cout<<ans.size()<<endl;

			for(i=0;i<ans.size();i++){
				cout<<ans[i]<<" ";
			}

			cout<<endl;
		}

			else cout << "Not Found" << endl;

			ans.clear();

			if(t)cout<<endl;
	}

}
