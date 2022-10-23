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


struct Node
{
	bool endmark;
	Node* next[20 + 1];


	Node() {

		endmark=false;
		for (int i = 0; i < 11; i++) {
			next[i] = NULL;
		}
	}
}*root;


void insert(string s) {

	int n = s.size();
	Node* cur = root;

	for (int i = 0; i < n; i++) {

		int id = s[i] - '0';

		

		if (cur->next[id] == NULL) {
			cur->next[id] = new Node();
		}

		cur = cur-> next[id];

		
	}

	cur->endmark = 1;
}


bool search(string s) {

	int n = s.size();
	Node* cur = root;
	int ck=0;

	for (int i = 0; i < n; i++) {
		int id = s[i] - '0';

		
		if (cur->next[id] == NULL)return false;
		if(cur->next[id]->endmark)return true;



		cur = cur->next[id];
	}

	return true;


}
