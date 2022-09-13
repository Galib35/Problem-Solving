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


void Target_Sum(vector<int>&nums, int &ans,int n,int i,int target,int sum){

//	deb2(i,sum);

	if(sum==target && i==n)ans++;

	if(i>=n)return;

	


//  Addition-----
		sum+=nums[i];

	Target_Sum(nums,ans,n,i+1,target,sum);

		sum-=nums[i];
//   -------


// Subtraction----		

		sum-=nums[i];
Target_Sum(nums,ans,n,i+1,target,sum);

		sum+=nums[i];
// -----


	
}
int main()
{
	int n,target;
	cin>>n>>target;
	vector<int>nums;
	int ans=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		nums.push_back(x);
	}

	int sum=0;

	Target_Sum(nums,ans,n,0,target,sum);

	cout<<ans;
}
