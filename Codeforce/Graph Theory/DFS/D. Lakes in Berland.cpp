//  https://codeforces.com/problemset/problem/723/D

#include<bits/stdc++.h>
using namespace std;
#define ll long long
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

int n, m, k, ck = 0;
char ch[60][60];
int vis [60][60];
set<vector<pii> > s;
vector<pii>v;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};



void DFS(int x, int y) {
  vis[x][y] = 1;
  if (x == 0 || x == n - 1 || y == 0 || y == m - 1)ck = 1;

  for (int i = 0; i < 4; i++) {
    int x1 = x + dx[i];
    int y1 = y + dy[i];

    if (!vis[x1][y1] && x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && ch[x1][y1] == '.') {
      v.pb({x1, y1});
      DFS(x1, y1);
    }
  }
}




int main()
{
  int i, j;
  cin >> n >> m >> k;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> ch[i][j];
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      v.clear();
      ck = 0;
      if (!vis[i][j] && ch[i][j] == '.') {
        v.pb({i, j});
        DFS(i, j);
        if (!ck) {
          s.insert(v);
        }
      }
    }
  }

  vector<pii>vv;
  map<int, int>mp;
  int need = s.size() - k;
  int pos = 0;
  itr(it, s) {
    pos++;
    vector<pii>kk;
    kk = *it;
    vv.pb({kk.size(), pos});

  }


  sort(all(vv));
  for (i = 0; i < need; i++)mp[vv[i].ss]++;

  pos = 0;
  int ans = 0;


  itr(it, s) {
    pos++;
    vector<pii>kk;
    kk = *it;
    if (mp[pos]) {
      for (i = 0; i < kk.size(); i++) {
        ch[kk[i].ff][kk[i].ss] = '*';
        ans++;
      }
    }



  }

  cout << ans << endl;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cout << ch[i][j];
    }
    cout << endl;
  }

}
