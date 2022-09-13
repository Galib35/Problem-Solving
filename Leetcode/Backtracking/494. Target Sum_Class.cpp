class Solution {
public:
  
    
    
    
    void Target_Sum(vector<int>&nums,int n,int i,int target,int &ans, int sum){


 if(i>=nums.size())
        {
            if(sum==target)
                ans++;
            return ;
        }
        
        

//  Addition-----
		sum+=nums[i];

	Target_Sum(nums,n,i+1,target,ans,sum);

		sum-=nums[i];
//   -------


// Subtraction----		

		sum-=nums[i];
Target_Sum(nums,n,i+1,target,ans,sum);

		sum+=nums[i];
// -----

	
}
    
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n=nums.size();
        
        int ans=0,sum=0;
        
        Target_Sum(nums,n,0,target,ans,sum);
        
        return ans;
        
    }
};
