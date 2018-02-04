/*
1. 4 meet 1
|--|
|  |
|--十-
   |
2. 5 meet 1
|--|
|  |
|  |
|--|
3. 6 meet 1
|--|
| -十--
|  |  |
|     |
|-----|
rather than 

|--------
|   --- |
|     | |
|     |
|-----|

-------
      |
|--|  |
|  |  |
|  |  |
|     |
|-----|

*/
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
    	int l = x.size();
    	if (l<=3)
    		return false;
    	for (int i=3;i<l;i++){
    		if (x[i]>=x[i-2] && x[i-1]<=x[i-3])
    			return true;
    		if (l>=4 && x[i-1]==x[i-3] && x[i]+x[i-4]>=x[i-2])
    			return true;
    		if (l>=5 && x[i-2]>=x[i-4] && x[i-1]<=x[i-3] &&x[i]+x[i-4]>=x[i-2] && x[i-1]+x[i-5]>=x[i-3])
    			return true;
    	}
    	return false;
    }
};