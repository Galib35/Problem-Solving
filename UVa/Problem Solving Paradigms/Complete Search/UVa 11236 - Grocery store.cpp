//  Brute Force
//  Hard

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
int main(){
	int a, b, c;

	for (a = 1; 4 * a <= 2000; a++) {
		for (b = a; a + 3 * b <= 2000; b++) {
			for (c = b; a + b + 2 * c <= 2000; c++) {
				long long p = (a * b * c);
				long long s = (a + b + c);

				if (p <= 1000000)
					continue;

				long long d = (1000000 * s) / (p - 1000000);

				if (d < c || s + d > 2000)
					continue;

				if (fabs((a + b + c + d) / 100.0 - (a * b * c * d) / 100000000.0) < 1e-9) {
					printf("%0.2lf %0.2lf %0.2lf %0.2lf\n", a / 100.0,
							b / 100.0, c / 100.0, d / 100.0);
				}
			}

		}
	}

	return 0;
}


/*
     https://www.redgreencode.com/equation-solving-is-the-key-to-uva-11236/
*/
