class Solution {
public:
    int lengthLongestPath(string input) {
    	vector<int> curL;
        int maxL = 0;
        stringstream ss(input);
        string s;
        while(getline(ss, s,'\n')){        	
            int l = 0;
            while(s[l] == '\t')
            	l++;
            if (l+1>curL.size())
            	curL.push_back(0);
            //last level + cur string length
            curL[l] = (l ? curL[l-1] : 0) + s.size()-l+1;
            //valid path
            if(s.find('.') != string::npos)
            	maxL = max(maxL, curL[l]-1);
        }
        return maxL;
    }
};