class Solution {
public:
    
    
    
    void Letter_Combination_Of_A_Phone_Number(string s, string res,vector<string>&ans, int idx, map<int,string>&mp){

	if(s.size()==res.size()){

		ans.push_back(res);
		return;
	}

		string dig=mp[s[idx]-'0'];

		for(int i=0;i<dig.size();i++){

			res.push_back(dig[i]);

				Letter_Combination_Of_A_Phone_Number(s,res,ans,idx+1,mp);
			res.pop_back();
		}


}
    
    
    
    
    vector<string> letterCombinations(string s) {
        char ch='a';

	map<int,string>mp;

	for(int i=2;i<=9;i++){
		string str="";
		str+=ch;
		ch++;
		str+=ch;
		ch++;
		str+=ch;
		ch++;

		if(i==9 || i==7){
			str+=ch;
			ch++;

		}

		mp[i]=str;

		if(i==9)break;

	}

	std::vector<string> ans;
	string res="";
        
    if(s.size()==0)return ans;    

	Letter_Combination_Of_A_Phone_Number(s,res,ans,0,mp);
        
    return ans;

    }
};
