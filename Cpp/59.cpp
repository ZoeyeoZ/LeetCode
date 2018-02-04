class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> moves{{0,1},{1,0},{0,-1},{-1,0}};
        int step = 0;
        vector<vector<int>> ans;
        for (int i=0; i<n; i++){
            vector<int> row(n,0);
            ans.push_back(row);
        }
        int l = 1,x = 0, y = -1;
        int m = n;
        while (l<=n*n){
            for (int i=0;i<m;i++){
                x += moves[step][0];
                y += moves[step][1];
                ans[x][y] = l;
                l++;
            }
            m--;
            step = (step+1)%4;
            for (int i=0;i<m;i++){
                x += moves[step][0];
                y += moves[step][1];
                ans[x][y] = l;
                l++;
            }
            step = (step+1)%4;
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0) return {};
        vector<vector<int>> result(n, vector<int>(n, 0));
        int k = 0;
        int num = 1;
        while(k < (n + 1)/2)
        {
            //cout<< k << ' ' << num << endl;
            for(int i = k; i < n - k; i++) result[k][i] = num++;
            //cout<< k << ' ' << num << endl;
            for(int i = k + 1; i < n - k; i++) result[i][n - k - 1] = num++;
            //cout<< k << ' ' << num << endl;
            for(int i = n - k - 2; i >= k; i--) result[n - k - 1][i] = num++;
            //cout<< k << ' ' << num << endl;
            for(int i = n - k - 2; i > k; i--) result[i][k] = num++;
            //cout<< k << ' ' << num << endl;
            k++;
        }
        return result;
    }
};
*/