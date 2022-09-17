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

int INF = 1e8, n;
char graph[109][109];
int vis[109][109];
int dist[109][109];


int dirX[] = { -1, 1, 0, 0};
int dirY[] = {0, 0, 1, -1};


bool isSafe(int x, int y) {

	return (x >= 0 && y >= 0 && x < n && y < n && vis[x][y] == 0 && graph[x][y] != '#');
}



void BFS(int sx, int sy) {

	dist[sx][sy] = 0;
	vis[sx][sy] = 1;

	queue<pair<int, int> >q;

	q.push({sx, sy});


	while (!q.empty()) {

		pair<int, int>p;
		p = q.front();

		int nodex = p.first;
		int nodey = p.second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextx = nodex + dirX[i];
			int nexty = nodey + dirY[i];

			if (isSafe(nextx, nexty)) {

				vis[nextx][nexty] = 1;
				dist[nextx][nexty] = dist[nodex][nodey] + 1;
				q.push({nextx, nexty});
			}
		}
	}
}



int main()
{

	int t;
	cin >> t;
	while (t--) {
		int  i, j;

		int player[2][2];
		int dest[2][2];

		int c1 = 0, c2 = 0;

		cin >> n;

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cin >> graph[i][j];

				if (graph[i][j] == '^') {
					player[c1][0] = i;
					player[c1][1] = j;

					c1++;
				}

				if (graph[i][j] == '*') {
					dest[c2][0] = i;
					dest[c2][1] = j;

					c2++;
				}
			}
		}



		int d1 = INF, d2 = INF, d3 = INF, d4 = INF;

		for (i = 0; i < 2; i++) {

			for (int k = 0; k < 105; k++) {
				for (int l = 0; l < 105; l++) {
					vis[k][l] = 0;
					dist[k][l] = INF;
				}
			}
//			deb2(player[i][0], player[i][1]);

			BFS(player[i][0], player[i][1]);

//			deb2(dist[dest[0][0]][dest[0][1]],dist[dest[1][0]][dest[1][1]]);

			if (dist[dest[0][0]][dest[0][1]] == INF || dist[dest[1][0]][dest[1][1]] == INF)continue;


			if (i == 0) {
				d1 = dist[dest[0][0]][dest[0][1]];
				d2 = dist[dest[1][0]][dest[1][1]];
			}

			else {
				d3 = dist[dest[0][0]][dest[0][1]];
				d4 = dist[dest[1][0]][dest[1][1]];
			}
		}


			int gap1=INF,gap2=INF;

				for (int k = 0; k < 105; k++) {
					for (int l = 0; l < 105; l++) {
						vis[k][l] = 0;
						dist[k][l] = INF;
					}
				}

				BFS(dest[0][0],dest[0][1]);

				gap1=dist[dest[1][0]][dest[1][1]];



		int ans = INF;

		
//		deb(gap1);
//		deb2(d1,d2);
//		deb2(d3,d4);


		if (d1 != INF && d4 != INF)ans = max(d1, d4);

		if (d1 != INF && d2 != INF && gap1!=INF) {

				ans = min(ans, min(d1,d2)+gap1);
			}

		if (d3 != INF && d4 != INF && gap1!=INF) {
				
				ans = min(ans, min(d3,d4)+gap1);
			}

		if (d2 != INF && d3 != INF) {
				ans = min(ans, max(d2, d3));
			}


		if (ans == INF)cout << "No" << endl;
		else {
				cout << "Yes" << endl;
				cout << ans << endl;
			}


		}

	}


/*
Corner Case:

1  
4
.*.*
^...
####
...^


2 ta player e j 2 ta destination e jaite hbe emon na, 1 ta player --2 ta gold mine eo jaite pare

*/
