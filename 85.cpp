class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    	if (matrix.size()==0 || matrix[0].size()==0)
    		return 0;
    	 //store all heights (lefter && h<=it)
    	int ans = 0;
    	int n = matrix[0].size();
    	int m = matrix.size();
    	vector<int> heights(n+1,0);
	    for (int row=0; row<m; row++){
	    	for (int i=0; i<n; i++)
	    		if (matrix[row][i]=='1')
	    			heights[i] += 1;
	    		else heights[i]=0;
	    	vector<int> ret;
	    	for (int i=0; i<=n; i++){    		
		    	int h;
		    	while (!ret.empty() && (h=heights[ret.back()])>heights[i]){
		    		ret.pop_back();
		    		int l = ret.empty()? i:i-ret.back()-1;
		    		ans = max(ans,h*l);
		    	}
		    	
		    		ret.push_back(i);
		    		
	    	}
	    }
    	return ans;
    }
};

/*
DP
row: i = 0~n;
col:
j = left~right
	1:
	height[j]++
	left[j] = max(left[j],rowleft)
	0:
	height[j] = left[j] = 0;
	rowleft = j+1;
j = right~left
	1:
	right[j] = min(right[j],rowright)
	0:
	right[j] = 0;
	rowright = j;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if( matrix.size() ==0 )
        {
            return 0;
        }
        
        int rowNum = matrix.size();
        int colNum = matrix[0].size();
        
        int result = 0;
        
        vector<int> left(colNum, 0);
        vector<int> right(colNum, colNum);
        vector<int> height(colNum, 0);
        
        for(int i=0; i < rowNum; ++i)
        {
            int currentLeftPos = 0;
            int currentRightPos = colNum;
            
            // Update height and left
            for(int j=0; j < colNum; ++j)
            {
                if( matrix[i][j] == '1' )
                {
                    // Update height
                    ++height[j];
                    
                    // Update left
                    left[j] = std::max( left[j], currentLeftPos );
                    
                }
                else
                {
                    height[j] = 0;
                    left[j] = 0;
                    currentLeftPos = j+1;
                }
            }
            
            // Update right, from right to left
            for( int j = colNum-1; j >=0; --j )
            {
                if( matrix[i][j] == '1' )
                {
                    right[j] = std::min( right[j], currentRightPos );
                }
                else
                {
                    right[j] = colNum;
                    currentRightPos = j;
                }
            }
            
            // Calculate result
            for( int j=0; j < colNum; ++j )
            {
                result = std::max( result, (right[j] - left[j])*height[j] );
            }
        }
        return result;
    }
};*/