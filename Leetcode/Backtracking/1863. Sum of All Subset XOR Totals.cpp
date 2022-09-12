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

int arr[20];
int n;
int xor_=0;
int ans=0;

void All_Subset_Sum(int i){
	for(;i<n;i++){

		xor_^=arr[i];

		All_Subset_Sum(i+1);

		ans+=xor_;

		xor_^=arr[i];
	}
}


int main()
{
	
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}


	All_Subset_Sum(0);

	cout<<ans<<endl;
}
