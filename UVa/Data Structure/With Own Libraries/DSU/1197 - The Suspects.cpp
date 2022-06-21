//    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3638

/*
  If 0 is presest in a group, make 0 parent of the whole group.
  
  */
//--------Solution-1 ------------


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

int parent[30009];

void make_set(int v)
{
	parent[v] = v;
}

int find_set(int v)
{
	if (parent[v] == v) {
		return v;
	}

	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);

	if (a != b) {
		if(a==0 ) {
			parent[b]=0;
		} else if(b==0) {
			parent[a]=0;
		} else {
			parent[b] = a;
		}
	}
}


int main()
{
	int t, n, m, i;
	while (cin >> n >> m) {

		if (n == 0 && m == 0) {
			break;
		}

		for (i = 0; i < n; i++) {
			make_set(i);
		}

		int c = 0, p;

		for (int cs = 0; cs < m; cs++) {
			int k;
			cin >> k;

			for (i = 0; i < k; i++) {
				ll x;
				cin >> x;
			//	x++;

				if (i != 0) {
					union_sets(x, p);
				}
				p = x;
			}
		}

		for (i = 0; i < n; i++) {
			int r=find_set(i);
		//	deb2(i,r);
			if (r==0) {
				c++;
			}

		}
		cout << c << endl;
		mem(parent);
	}
}


//--------Solution-2 -------------	  

// Increase every node by 1.  0->1 , 1->2.......

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

int parent[30009];

void make_set(int v)
{
	parent[v] = v;
}

int find_set(int v)
{
	if (parent[v] == v) {
		return v;
	}

	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);

	if (a != b) {
		if(a==1 ) {
			parent[b]=1;
		} else if(b==1) {
			parent[a]=1;
		} else {
			parent[b] = a;
		}
	}
}


int main()
{
	int t, n, m, i;
	while (cin >> n >> m) {

		if (n == 0 && m == 0) {
			break;
		}

		for (i = 1; i <= n; i++) {
			make_set(i);
		}

		int c = 0, p;

		for (int cs = 0; cs < m; cs++) {
			int k;
			cin >> k;

			for (i = 0; i < k; i++) {
				ll x;
				cin >> x;
				x++;

				if (i != 0) {
					union_sets(x, p);
				}
				p = x;
			}
		}

		for (i = 1; i <= n; i++) {
			int r=find_set(i);
		//	deb2(i,r);
			if (r==1) {
				c++;
			}

		}
		cout << c << endl;
		mem(parent);
	}
}
