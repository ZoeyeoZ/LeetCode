class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int,int> NM;
        for (int i=0; i<nums.size(); i++)
        	NM[nums[i]] = i;
        vector<string> ans(NM.size(),"");
        int cnt =1;
        for (auto it = NM.rbegin(); it!=NM.rend(); it++, cnt++){
        	if (cnt == 1) 
        		ans[it->second] = "Gold Medal";
            else if (cnt == 2) 
            	ans[it->second] = "Silver Medal";
            else if (cnt == 3) 
            	ans[it->second] = "Bronze Medal";
            else 
            	ans[it->second] = to_string(cnt);
        }
        return ans;
    }
};
/*9ms
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector <pair <int, int> > scoreIdx;
        for (int i = 0; i < nums.size(); ++i) {
            scoreIdx.emplace_back(nums[i], i);
        }
        
        sort(scoreIdx.begin(), scoreIdx.end());
        reverse(scoreIdx.begin(), scoreIdx.end());
        
        vector <string> ans (nums.size());
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i==0)
                ans[scoreIdx[i].second] = "Gold Medal";
            else if (i==1)
                ans[scoreIdx[i].second] = "Silver Medal";
            else if (i==2)
                ans[scoreIdx[i].second] = "Bronze Medal";
            else 
                ans[scoreIdx[i].second] = to_string(i+1);
        }
        return ans;
    }
};
*/