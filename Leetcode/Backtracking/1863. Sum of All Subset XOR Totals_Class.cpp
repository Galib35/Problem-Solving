

class Solution {
public:
    
    void All_Subset_Sum(vector<int>&arr,int n,int i,int xor_,int &ans){
	for(;i<n;i++){

		xor_^=arr[i];

		All_Subset_Sum(arr,n,i+1,xor_,ans);

		ans+=xor_;

		xor_^=arr[i];
	}
}

    int subsetXORSum(vector<int>& arr) {
        
      int  n=arr.size();
        int ans=0;
        
        All_Subset_Sum(arr,n,0,0,ans);
        
        return ans;
        
    }
};
