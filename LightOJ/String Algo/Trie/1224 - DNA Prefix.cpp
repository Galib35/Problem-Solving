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

ll ans=0;

struct Node
{
	int endmark;
	Node* next[6 + 1];


	Node() {
		endmark=0;
		for (int i = 0; i < 6; i++) {
			next[i] = NULL;
		}
	}
}*root;


void insert(string s) {

	int n = s.size();
	Node* cur = root;

	for (int i = 0; i < n; i++) {

		int id;
		
		if(s[i]=='A')id=0;
		else if(s[i]=='C')id=1;
		else if(s[i]=='G')id=2;
		else id=3;

		if (cur->next[id] == NULL) {
			cur->next[id] = new Node();
		}

		cur = cur-> next[id];

		cur->endmark=cur->endmark+1;

//		deb2(i+1,cur->endmark);
	}

//	cur->endmark = 1;
}


void search(string& s) {
	int n = s.size();
	Node* cur = root;

	for (int i = 0; i < n; i++) {
		
		int id;
		if(s[i]=='A')id=0;
		else if(s[i]=='C')id=1;
		else if(s[i]=='G')id=2;
		else id=3;

		if (cur->next[id] == NULL)return ;

		cur = cur->next[id];

//		cur->endmark=cur->endmark+1;

		ans=max((ll)(i+1)*(cur->endmark),ans);
	}

	return ;
}


void del(Node* cur) {

	for (int i = 0; i < 6; i++) {

		if (cur->next[i])del(cur->next[i]);
	}

	delete(cur); // This will delete 1 node with 26 child null nodes
}



int main()
{

	ll t,i,n,ca=0;
	cin>>t;

	while(t--){

		ans=0;
		ca++;
		std::vector<string> v;
		root=new Node();
		cin>>n;

		for(i=0;i<n;i++){

			string s;
			cin>>s;

			insert(s);
			v.pb(s);
		}


		for(i=0;i<n;i++){

			search(v[i]);
		}

		cout<<"Case "<<ca<<": ";

		cout<<ans<<endl;

		del(root);

	}


}
