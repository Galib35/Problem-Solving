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

void Generate_Parentheses(int n, char ch[], int open, int close, vector<string>&ans, string res) {


	if (close > open || open > n)return;

	if (open == n && close == n) {
		ans.push_back(res);
		
return;
	}



	for (int i = 0; i < 2; i++) {

		res.push_back(ch[i]);

		if (ch[i] == '(')open++;
		else close++;

		Generate_Parentheses(n, ch, open, close, ans, res);

		if (res.back() == '(')open--;
		else close--;

		res.pop_back();
	}
}
int main()
{
	int n;
	cin >> n;

	int open = 0, close = 0;
	char ch[] = {'(', ')'};

	std::vector<string> ans;
	string res;
	Generate_Parentheses(n, ch, open, close, ans, res);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}
