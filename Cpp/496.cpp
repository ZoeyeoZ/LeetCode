class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    	unordered_map<int,int> Nmap; // greater
    	stack<int> st; // store current none find nums
    	for (auto num:nums){
    		while (!st.empty() && st.top()<num){
    			Nmap[st.top()] = num;
    			st.pop();
    		}
    		st.push(num);
    	}
    	vector<int> ans;
    	for (auto num:findNums)
    		if (Nmap.count(num)==0)
    			ans.push_back(-1);
    		else ans.push_back(Nmap[num]);
        return ans;
    }
};
//21
/*6ms
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]]=i;
        for(int i=0; i<findNums.size(); i++){
            int newval=-1;
            for(int j=mp[findNums[i]]+1; j<nums.size(); j++){                
                if(findNums[i]<nums[j]) { newval=nums[j]; break; }
            } 
            res.push_back(newval);
        }
        return res;
    }
};
*/