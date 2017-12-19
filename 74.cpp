/*
0...n-1
n...
....mn-1
0 1 2 3 
4 5 6 7
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	int m = matrix.size();
    	if (m==0)
    		return false;
    	int n = matrix[0].size();
    	if (n==0)
    		return false;
    	int l = 0, r = m*n-1, mid;
    	while (l<=r){
    		mid = (l+r)/2;
    		if (target==matrix[mid/n][mid%n])
    			return true;
    		else if (target>matrix[mid/n][mid%n])
    			l = mid+1;
    		else r = mid-1;
    	}
    	return false;
        
    }
};


/*

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int topBoundary=0,rightBoundary=matrix[0].size()-1;
        while(topBoundary<matrix.size()&&rightBoundary>=0){
            if(matrix[topBoundary][rightBoundary]<target)
                ++topBoundary;
            else if(matrix[topBoundary][rightBoundary]>target)
                --rightBoundary;
            else
                return true;
        }
        return false;
    }
};*/
