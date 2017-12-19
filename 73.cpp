// find last 0-row
// 0->row, and store (col with 0)
// 0->col
// 0->last 0-row

class Solution {
public:
    vector<vector<int>> setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int last0row = -1;
        for (int i=m-1;i>=0 && last0row==-1;i--)
            for (int j=n-1;j>=0;j--)
                if (matrix[i][j]==0){
                    last0row = i;
                    break;
                }
        if (last0row==-1)
            return;
        bool has0row;
        for (int i=last0row-1;i>=0;i--){
            has0row = false;
            for (int j=n-1;j>=0;j--)
                 if (matrix[i][j]==0){
                    matrix[last0row][j] = 0;
                    has0row = true;
                 }
            if (has0row)
                for (int j=n-1;j>=0;j--)
                    matrix[i][j] = 0;
        }
        for (int i=m-1; i>=0; i--)
            for (int j=n-1;j>=0;j--)
                if (matrix[last0row][j]==0)
                    matrix[i][j] = 0;
        for (int j=n-1;j>=0;j--)
            matrix[last0row][j]=0;
        return matrix;
        
    }
};