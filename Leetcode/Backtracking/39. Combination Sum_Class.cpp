class Solution {
public:
    
   void  Combination_Sum_To_Target(vector<vector<int> >&ans, vector<int>res, vector<int>&v, int i, int n, int target, int sum) {

//deb(sum);
	if (sum > target)return;
	if (sum == target) {
		ans.push_back(res);
		return;
	}

	for (; i < n; i++) {

		res.push_back(v[i]);
		sum += v[i];

//		deb(sum);

		Combination_Sum_To_Target(ans, res, v, i, n, target, sum);

//		deb(sum);
		sum -= res.back();
		res.pop_back();

	}
}
 
    
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        
        	vector<vector<int> >ans;
	vector<int>res;
	int sum = 0;
        int n=v.size();



	Combination_Sum_To_Target(ans, res, v, 0, n, target, sum);
        
        return ans;
        
    }
};
