//maintain k PQ
class Solution {
public:
    struct compare
    {
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        }
        
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int l = nums.size();
        if (l<k)
            return ans;
        unordered_map<int,int> map;
        for (int i=0;i<l;i++)
            map[nums[i]]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq; 
        for (auto m: map)
            pq.push(m);
        for (int i=0;i<k;i++){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};