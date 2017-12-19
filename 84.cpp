class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	if (heights.empty())
    		return 0;
    	vector<int> ret; //store all heights (lefter && h<=it)
    	int ans = 0;
    	heights.push_back(0);
    	for (int i=0; i<heights.size(); i++){
    		
	    	int h;
	    	while (!ret.empty() && (h=heights[ret.back()])>heights[i]){
	    		ret.pop_back();
	    		int l = ret.empty()? i:i-ret.back()-1;
	    		ans = max(ans,h*l);
	    	}
	    	
	    		ret.push_back(i);
	    		
    	}
    	return ans;
    }
};