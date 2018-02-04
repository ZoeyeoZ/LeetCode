class Solution {
public:
    int nthUglyNumber(int n) {
    	vector<int> ans(1,1);
    	int i=0,j=0,k=0;
    	while (ans.size()<n){
    		/*
    		//wrong, since some may the same
    		if (ans[i]*2<ans[j]*3)
    			if (ans[i]*2<ans[k]*5)
    				tmp = ans[i]*2, i++;
    			else 
    				tmp = ans[k]*5, k++;
    		else 
    			if (ans[j]*3<ans[k]*5)
    				tmp = ans[j]*3, j++;
    			else 
    				tmp = ans[k]*5, k++;
    		ans.push_back(tmp);
    		*/
    		ans.push_back(min(ans[i]*2,min(ans[j]*3,ans[k]*5)));
    		if (ans.back()==ans[i]*2) i++;
    		if (ans.back()==ans[j]*3) j++;
    		if (ans.back()==ans[k]*5) k++;
    	}
        return ans[n-1];
    }
};