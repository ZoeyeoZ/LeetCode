class Solution {
public:
    vector<string> findWords(vector<string>& words) {
    	vector<int> le(26);
    	le[16] = le[22] = le[4] = le[17] = le[19] = le[24] = le[20] = le[8] = le[14] = le[15] = 1;//001
    	le[0] = le[18] = le[3] = le[5] = le[6] = le[7] = le[9] = le[10] = le[11] = 2;//010
    	le[25] = le[23] = le[2] = le[21] = le[1] = le[13] = le[12] = 4;//100
    	vector<string> ans;
    	for (auto w:words){
    		int tmp = 7;
    		for (char ch:w){
    			tmp &= le[toupper(ch)-'A'];
    			if (tmp==0)
    				break;
    		}
    		if (tmp) ans.push_back(w);
    	}
    	return ans;
    }
};