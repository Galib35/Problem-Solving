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

int main()
{
	int i,j,t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		std::vector<int> a(n);
		map<int,int>mp;

		for(i=0;i<n;i++){
			cin>>a[i];
		}

		sort(all(a));

		

		i=0;
		j=n-1;

		int num_bin=0;

		for(i=0;i<n;i++){

			if(mp[i])continue;

			int req=k-a[i];

//			deb(a[i]); 

			int x=upper_bound(a.begin(),a.end(),req)-a.begin();

			x--;

//			deb(a[x]);

			
			
			while(x>=0){

				if(a[x]<=req  &&  mp[x]==0){
					mp[x]=1;
//					deb(a[x]);
					break;

								}

				x--;

			}

			mp[i]=1;
			num_bin++;


		}	

		cout<<num_bin<<endl;
		if(t!=0)cout<<endl;
		
	}
}
