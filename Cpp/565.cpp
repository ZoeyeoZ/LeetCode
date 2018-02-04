/*
Find longest circle
sol1
Union-Find / DFS

sol2
reset cycle => nums[i]=i
A = [5,4,0,3,1,6,2], i=0
  =>[0,4,0,3,1,6,2], i=5
  =>[0,4,0,3,1,5,2], i=6
  =>[0,4,0,3,1,5,6], i=2
  =>[0,4,2,3,1,5,6], i=0
*/
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
    	int ans = 1, cnt=0;
        for(int i=0; i<nums.size(); cnt=0,i++){
            while (i!=nums[i]){
                swap(i,nums[i]); 
                cnt++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};
/*
sample 32 ms submission
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            int cnt = 0, j = i;
            //while (cnt == 0 || j != i) {
            while (!visited[j]) {
                visited[j] = true;
                j = nums[j];
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};*/
