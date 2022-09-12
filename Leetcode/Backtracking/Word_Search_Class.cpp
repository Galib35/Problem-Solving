// Mile nai, onk try korsi

int dirX[]={1,-1,0,0};
int dirY[]={0,0,1,-1};
int n,m;
int vis[20][20];

class Solution {
public:

    

bool isSafe(int x, int y, int pos, string s, vector<vector<char>>& arr) {
	if (x >= 0 && y >= 0 && x < n && y < m && s[pos] == arr[x][y] && vis[x][y]==0)return true;
	return false;
	}

bool Word_Search_2D_Grid(int i,int j,int pos,string s,vector<vector<char>>& arr){

	if(pos==s.size() && s[s.size()-1]==arr[i][j])return true;

		for(int k=0;k<4;k++){

			int nextX=i+dirX[k];
			int nextY=j+dirY[k];

			if(isSafe(nextX,nextY,pos, s,arr)){
                
                vis[nextX][nextY]=1;
                
				if(Word_Search_2D_Grid(nextX,nextY,pos+1,s,arr))return true;
                
                else vis[nextX][nextY]=0;
			}
		}

		return false;
}

    
    
    bool exist(vector<vector<char>>& arr, string s) {
        int yes = 0;

        n=arr.size();
        m=arr[0].size();
        int i,j;
        
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {

			if (arr[i][j]==s[0] && Word_Search_2D_Grid(i,j,1,s,arr)) {
				return true;
			}
		}
		
	}
    return false;
	
	
    }
};
