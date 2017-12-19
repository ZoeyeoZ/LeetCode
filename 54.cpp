class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        vector<int> ans;
        vector<vector<int>> moves ={{0,1},{1,0},{0,-1},{-1,0}};
        int m = matrix.size(), n = matrix[0].size();
        int x =0, y = -1, step = 0;
        int sum = n*m;
        m--;
        while (sum){
            for (int i=0; i<n; i++){
                x += moves[step][0];
                y += moves[step][1]; 
                ans.push_back(matrix[x][y]);
            } 
            sum -=n;
            n--;
            step = (step+1)%4;
            for (int i=0; i<m; i++){
                x += moves[step][0];
                y += moves[step][1]; 
                ans.push_back(matrix[x][y]);   
            }
            sum -= m;
            m--;
            step = (step+1)%4;
            
        }
        return ans;    
    }
};