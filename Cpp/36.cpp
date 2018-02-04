class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<short> row(9,0),col(9,0),block(9,0);
        int x;
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
                if (board[i][j]!='.'){
                    x = 1<<(board[i][j]-'0');
                    if ((row[i] & x)||(col[j] & x)||(block[i/3*3+j/3] & x))
                        return false;
                    row[i] |= x;
                    col[j] |= x;
                    block[i/3*3+j/3] |= x;
                }
        return true;
    }
};


