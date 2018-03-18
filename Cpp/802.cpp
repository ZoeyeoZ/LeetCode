//from out-degree = 0, remove all egdes, repeat
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> d(n,0);
        vector<vector<int>> gT(n,vector<int>());
        for (int i = 0; i < n; ++ i){
            //gT[i].push_back(new vector<int>);
            for (int j = 0; j < graph[i].size(); ++ j){
                gT[graph[i][j]].push_back(i);
                ++ d[i];
            }
        }
        for (int i = 0; i < n; ++ i)
            if (d[i] == 0)
                ans.push_back(i);
        if (ans.size() == n)
            return ans;
        int j = 0;
        while (j < ans.size()){
            for (int i = 0; i < gT[ans[j]].size(); ++ i){
                -- d[gT[ans[j]][i]];
                if (d[gT[ans[j]][i]] == 0)
                     ans.push_back(gT[ans[j]][i]);
            }
            ++ j;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};