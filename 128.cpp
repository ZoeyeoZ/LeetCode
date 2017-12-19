/*
neither i+1 nor i-1 has been seen: m[i]=1;
both i+1 and i-1 have been seen: extend m[i+m[i+1]] and m[i-m[i-1]] to each other;
only i+1 has been seen: extend m[i+m[i+1]] and m[i] to each other;
only i-1 has been seen: extend m[i-m[i-1]] and m[i] to each other.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int l = 0;
        for (int i:nums){
        	if (m[i]) //duplicate
        		continue;
        	l = max(l, m[i] = m[i+m[i+1]] = m[i-m[i-1]] = m[i+1]+m[i-1]+1);
        	/*
        	cout << i<<"="<<m[i]<<endl;
        	cout << i+m[i+1]<<"="<<m[i+m[i+1]]<<endl;
        	cout << i-m[i-1]<<"="<<m[i-m[i-1]]<<endl;
        	cout <<endl;
        	*/
        }
        return l;
    }
};
/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> S(nums.begin(),nums.end());
        int ans = 0;
        for(int i:nums){
            if(S.find(i)==S.end()) continue;
            S.erase(i);
            int next = i+1, prev = i-1;
            while(S.find(next)!=S.end()) S.erase(next++);
            while(S.find(prev)!=S.end()) S.erase(prev--);
            ans = max(ans,next-prev-1);
        }
        return ans;
    }
};*/
