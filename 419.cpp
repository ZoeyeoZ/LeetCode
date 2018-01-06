class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        if (m==0)
        	return 0;
        int n = board[0].size();
        if (n==0)
        	return 0;
        int cnt = 0;
        for (int i=0; i<m; i++)
        	for (int j=0; j<n; j++)
        		//only consider the upper left as battleship's head
        		cnt += board[i][j]=='X' && (i==0 || board[i-1][j]!='X') && (j==0 || board[i][j-1]!='X');
        return cnt;

    }
};