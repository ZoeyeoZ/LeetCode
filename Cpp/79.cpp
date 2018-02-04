class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	m = board.size();
    	n = board[0].size();
    	l = word.size();
    	for (int i=0;i<m;i++)
    		for (int j=0;j<n;j++){
    			if (helper(board,word,0,i,j))
    				return true;
    		}
    	return false;    
    }
private:
	int m, n, l;
	bool isvalid(int x, int y){
		if (x>=0 && y>=0 && x<m && y<n)
			return true;
		else 
			return false;
	}
	bool helper(vector<vector<char>>& board, string word, int k, int x, int y){
		cout << x<<","<<y<<endl;
		if (!isvalid(x,y)){
			cout <<"FFFFF"<<endl;
			return false;
		}
		cout << x<<","<<y<<":"<<board[x][y]<<"?"<<word[k]<<endl;
		if (board[x][y]!=word[k])
			return false;
		if (k==word.size()-1)
			return true;
		char tmp = board[x][y];
		cout <<tmp<<endl;
		board[x][y] = '\0';
		if (helper(board,word,k+1,x+1,y)||helper(board,word,k+1,x-1,y)||helper(board,word,k+1,x,y+1)||helper(board,word,k+1,x,y-1))
			return true;
		board[x][y] = tmp;
		return false;
	}
};