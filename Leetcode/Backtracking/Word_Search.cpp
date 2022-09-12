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

string s;
char arr[20][20];
int vis[20][20];
int n, m;

int dirX[]={1,-1,0,0};
int dirY[]={0,0,1,-1};

bool isSafe(int x, int y, int pos) {
	if (x >= 0 && y >= 0 && x < n && y < m && s[pos] == arr[x][y] && vis[x][y]==0)return true;
	return false;
	}

bool Word_Search_2D_Grid(int i,int j,int pos){

	if(pos==s.size() && s[s.size()-1]==arr[i][j])return true;

		for(int k=0;k<4;k++){

			int nextX=i+dirX[k];
			int nextY=j+dirY[k];

			if(isSafe(nextX,nextY,pos)){

				vis[nextX][nextY]=1;

				if(Word_Search_2D_Grid(nextX,nextY,pos+1))return true;

				vis[nextX][nextY]=0;
			}
		}

		return false;
}


int main()
{

	int i, j;

	cin >> n >> m;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {

			cin >> arr[i][j];
		}
	}

	cin >> s;

	int yes = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {

			if (arr[i][j]==s[0] && Word_Search_2D_Grid(i,j,1)) {
				cout << "Yes" << endl; yes = 1;
				break;
			}
		}
		if(yes)break;
	}

	
	if(!yes)	cout << "No" << endl;
	

}

/*
  
  Corner case:
    3 4
a b c e
s f c s
a d e e

-> aba : No
-> e    : Yes
    
*/
