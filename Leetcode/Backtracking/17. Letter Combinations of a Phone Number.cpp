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


void Letter_Combination_Of_A_Phone_Number(string s, string res, vector<string>&ans, int idx, map<int, string>&mp) {

	if (s.size() == res.size()) {

		ans.push_back(res);
		return;
	}

	string dig = mp[s[idx] - '0'];

	for (int i = 0; i < dig.size(); i++) {

		res.push_back(dig[i]);

		Letter_Combination_Of_A_Phone_Number(s, res, ans, idx + 1, mp);
		res.pop_back();
	}


}
int main()
{
	string s;
	cin >> s;

	char ch = 'a';

	map<int, string>mp;

	for (int i = 2; i <= 9; i++) {
		string str = "";
		str += ch;
		ch++;
		str += ch;
		ch++;
		str += ch;
		ch++;

		if (i == 9 || i == 7) {
			str += ch;
			ch++;

		}

		mp[i] = str;

		if (i == 9)break;

	}

	std::vector<string> ans;
	string res = "";

	Letter_Combination_Of_A_Phone_Number(s, res, ans, 0, mp);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

}
