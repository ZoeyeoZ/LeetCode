class Solution {
public:
    bool canCross(vector<int>& stones) {
    	int n = stones.size();
    	unordered_map<int,unordered_set<int>> dp;
    	dp[0].insert(0);
    	for (int s:stones)
    		for (int step:dp[s]){
    			if (step-1>0)
    				dp[s+step-1].insert(step-1);
    			dp[s+step].insert(step);
    			dp[s+step+1].insert(step+1);
    		}
    	return !dp[stones.back()].empty();
    }
};
//166
/*39DFS
class Solution {
public:
    unordered_set<int> set;
    bool dfs(int k, int pos, int destination)
    {
        if (pos>destination || set.find(pos) == set.end())
        {
            return false;
        }
        if (pos==destination)
        {
            return true;
        }
        for (int i=1;i>=-1;i--)
        {
            if (k+i>0 && dfs(k+i,pos+k+i,destination))
            {
                return true;
            }
        }
        return false;
    }
    bool canCross(vector<int>& stones)
    {
        int n=stones.size();
        if(n<=1)
        {
            return true;
        }
        set.insert(0);
        for(int i=1;i<n;i++)
        {
            set.insert(stones[i]);
            if(stones[i]-stones[i-1] > i)
            {
                return false;
            }
            
        }
        return dfs(1,1,stones[n-1]);
    }
};
*/