/*
2 bits: XY, X for next, Y for current
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    	int step[8][2]={{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
    	int m = board.size(), n = board[0].size(), cnt, x, y;
    	for (int i=0;i<m;i++)
    		for (int j=0;j<n;j++){
    			cnt = 0;
    			for (int k=0;k<8;k++){
    				x = i+step[k][0];
    				y = j+step[k][1];
    				if (x<0||x>=m||y<0||y>=n)
    					continue;
    				if (board[x][y]&1)
    					cnt++;
    			}
    			if (board[i][j]==0 && cnt==3)
    				board[i][j] = 2; //10
    			else if (board[i][j]==1){
    				if (cnt<2||cnt>3)
    					board[i][j] = 1; //01
    				else
    					board[i][j] = 3; //11
    			}
    		} 
    	for (int i=0;i<m;i++)
    		for (int j=0;j<n;j++)
    			board[i][j] >>=1;
        
    }
};