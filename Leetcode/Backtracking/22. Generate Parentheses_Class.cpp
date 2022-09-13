class Solution {
public:
    
    
    
void Generate_Parentheses(int n, char ch[], int open, int close, vector<string>&ans, string res) {


	if (close > open || open > n)return;

	if (open == n && close == n) {
		ans.push_back(res);
		
return;
	}



	for (int i = 0; i < 2; i++) {

		res.push_back(ch[i]);

		if (ch[i] == '(')open++;
		else close++;

		Generate_Parentheses(n, ch, open, close, ans, res);

		if (res.back() == '(')open--;
		else close--;

		res.pop_back();
	}
}
    
    
    
    vector<string> generateParenthesis(int n) {
       
    int open = 0, close = 0;
	char ch[] = {'(', ')'};

	std::vector<string> ans;
	string res;
	Generate_Parentheses(n, ch, open, close, ans, res);
        
    return ans;
    }
};
