class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> Nmap(n,-1); // greater 
    	stack<int> st; // store current none find nums's id
        for (int i=0; i<n*2; i++){
            int num = nums[i%n];
    		while (!st.empty() && nums[st.top()]<num){
    			Nmap[st.top()] = num;
    			st.pop();
    		}
    		if (i<n)
                st.push(i);
    	}
        return Nmap;
    }
};