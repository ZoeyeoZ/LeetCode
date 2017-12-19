// Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> results;
        //快速查找删除，内存占用较高 unorder_map；有序容器稳定，内存少使用平衡二叉树 map
        for (int i = 0; i < nums.size(); i++){
            int cur = target - nums[i];
            if (results.find(cur) != results.end()){
                ans.push_back(results[cur]);
                ans.push_back(i);
                return ans;
            }
            results[nums[i]] = i;
        }
        return ans;

    }
};