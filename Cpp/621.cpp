/*
CPU wait for time to do the same task
-> calculate the max number

if tasks.size()<=ans, this proves that an ans-length schedule satisfies.
When tasks.size() > ans, clearly we need at least tasks.size()
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    	if (n == 0)
    		return tasks.size();
        unordered_map<char,int> M;
        int maxcnt = 0;
        for (auto t:tasks)
        	maxcnt = max(maxcnt,++M[t]);
        int ans  = (maxcnt - 1) * (n + 1);
        for (auto it:M)
        	if (it.second == maxcnt)
        		ans ++;
        return max((int)tasks.size(), ans);
    }
};