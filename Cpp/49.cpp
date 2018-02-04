class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,multiset<string>> ansmap;
        for (auto s:strs){
            string tmp = s;
            sort(tmp.begin(),tmp.end());
            ansmap[tmp].insert(s);
        }
        vector<vector<string>> ans;
        for (auto str:ansmap){
            vector<string> anstmp(str.second.begin(),str.second.end());
            ans.push_back(anstmp);
        }
        return ans;
        
    }
};
/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int prime[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
        vector<vector<string>> result;
        unordered_map<unsigned long, vector<string>> map1;
        for(int i = 0; i< strs.size(); i++)
        {
            unsigned long long id = 1;
            for(int j = 0; j<strs[i].length(); j++)
            {
                id *= prime[strs[i][j] - 'a'];
            }
            map1[id].push_back(strs[i]);
        }
        for(auto iter = map1.begin(); iter != map1.end(); iter++)
        {
            result.push_back(iter->second);
        }
        return result;
    }
};*/