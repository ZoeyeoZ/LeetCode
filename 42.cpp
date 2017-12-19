class Solution {
public:
    int trap(vector<int>& height) {
    	vector<int> bin;
    	int maxh = 0;
    	int ans = 0;
    	for (int i=0; i<height.size();i++){
    		while (maxh<height[i]){
    			bin.push_back(-1);
    			maxh++;
    		}
    		int j = 0;
    		while (j<height[i]){
    			if (bin[j]==-1)
    				bin[j]=i;
    			else 
    				if (i-bin[j]==1)
    					bin[j]++;
    				else{
	    				ans += i-bin[j]-1;
	    				//cout << i<<","<<bin[j]<<"="<<i-bin[j]-1<<endl;
	    				bin[j]=i;
	    			}
	    			j++;
	    		}
    	}
    	return ans;     
    }
};
/*

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int water = 0;
        int lheight = 0, rheight = 0;
        while(l < r) {
            if (height[l] <= height[r]) {
                if (lheight <= height[l]) lheight = height[l];
                else water += lheight - height[l];
                ++l;
            } else {
                if (rheight <= height[r]) rheight = height[r];
                else water += rheight - height[r];
                --r;
            }
        }
        return water;
    }
};
*/