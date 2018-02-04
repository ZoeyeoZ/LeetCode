class Solution {
public:
    int countSegments(string s) {
    	stringstream iss(s);
    	int ans = 0;
    	while (iss >> s)
    		ans++;
    	return ans;
        
    }
};
/*
istringstream iss(s);
while (getline(iss,s,' '))
if there are a lot of space, there will be mistake.
such as "                "
*/