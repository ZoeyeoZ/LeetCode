class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int> tmp;
        for (int i=0; i<matrix.size()/2; i++)
            swap(matrix[i],matrix[matrix.size()-i-1]);
        for (int i=0; i<matrix.size(); i++){
            for (int j=i+1; j<matrix[i].size(); j++)
                swap(matrix[i][j],matrix[j][i]);
        }
        
        for (auto i:matrix){
            for (auto j:i)
                cout << j <<",";
            cout << endl;
        }
    }
};

/*
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int bound = matrix.size() - 1;
        for (int i = 0; i < ceil(matrix.size()/2.0); i++)
        {
            for (int j = i; j < bound-i; j++)
            {
                auto tmp = matrix[i][j];
                matrix[i][j] = matrix[bound-j][i];
                matrix[bound-j][i] = matrix[bound-i][bound-j];
                matrix[bound-i][bound-j] = matrix[j][bound-i];
                matrix[j][bound-i] = tmp;
            }
        }
    }
};
*/