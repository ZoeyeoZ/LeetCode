class Solution {
public:
    bool checkRecord(string s) {
        int cnta = 0, cntl = 0;
        for (char ch:s){
        	if (ch=='A')
        		cnta++;
        	if (ch=='L')
        		cntl++; 
        	else
        		cntl = 0;
        	if (cnta>1 || cntl>2)
        		return false;
        }
        return true;
    }
};