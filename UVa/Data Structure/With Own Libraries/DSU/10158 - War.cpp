//    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1099

//-----------------Solution-1------------------------------------
/*
    The first way, let A be divided into two parts, namely (A) and (A's enemy).
    As long as the same representatives as p[A] are friends, and the same as p[A's enemy] are the enemies of A.
    Since it is divided into two different numbers, operations such as union can be performed directly on them.
    
    if, parent of set(A)  ->  5
    parent of set(A's enemy)  ->  n+5

*/

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

int parent[200000];
int size[200000];
int n;

int enemy(int x) {
	return x + n;
}

void make_set(int v) {
	parent[v] = v;
	size[v] = 1;
}



int  find_set(int  v) {
	if (parent[v] == v)return v;

	return parent[v] = find_set(parent[v]);
}




void union_sets(int  a, int  b) {
	int c, d;
	c = find_set(a);
	d = find_set(b);

	if (c != d) {
		if (size[c] < size[d])swap(c, d);
		parent[d] = c;
		size[c] += size[d];

	}

}

bool set_friends(int x, int y) {
	int ex = find_set(enemy(x));
	int ey = find_set(enemy(y));
	x = find_set(x);
	y = find_set(y);

	if (x == ey || y == ex) {
		return false;  // They are already enemies.
	}

	union_sets(x, y);
	union_sets(ex, ey); // Enenmies
	return true;

}

bool set_enemies(int x, int y) {
	int ex = find_set(enemy(x));
	int ey = find_set(enemy(y));
	x = find_set(x);
	y = find_set(y);

	if (x == y) {
		return false;  //  They are already friends.
	}

	union_sets(x, ey);
	union_sets(ex, y);
	return true;
}

bool are_friends(int x, int y) {
//	int ex = find_set(enemy(x));
//	int ey = find_set(enemy(y));
	x = find_set(x);
	y = find_set(y);

	if (x == y)return true;
	else return false;
}

bool are_enemies(int x, int y) {
	int ex = find_set(enemy(x));
	int ey = find_set(enemy(y));
	x = find_set(x);
	y = find_set(y);

	if (x == ey || y == ex)return true;
	else return false;
}




int main()
{

	int  c, u, v, i;
	cin >> n;

	for (i = 0; i <= 2 * n + 5; i++)make_set(i);
	while (cin >> c) {
		if (c == 0)break;
		if (c == 1) {
			cin >> u >> v;

			if (set_friends(u, v) == false)cout << -1 << endl;

		}

		if (c == 2) {
			cin >> u >> v;

			if (set_enemies(u, v) == false)cout << -1 << endl;
		}

		if (c == 3) {
			int a, b;
			cin >> u >> v;

			if (are_friends(u, v))cout << 1 << endl;
			else cout << 0 << endl;

		}

		if (c == 4) {
			int a, b;
			cin >> u >> v;
			if (are_enemies(u, v))cout << 1 << endl;
			else cout << 0 << endl;
		}

	}
}


//---------------  Solution-02 ---------------------

//    http://naivered.github.io/2018/05/26/Problem_Solving/UVa/UVa-10158-War/
