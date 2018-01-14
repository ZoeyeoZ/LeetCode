class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> M;
        int tmp;
        for (auto w:wall){
        	tmp = 0;
        	for (auto b:w)
        		M[(tmp+=b)]++;
        }
        int ans = 0;
        for (auto it=M.begin(); it!=M.end(); it++)
        	if (it->first!=tmp && it->second>ans)
        		ans = it->second;
        return wall.size()-ans;
    }
};
/**53
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> edges;
        auto min_bricks = wall.size();
        for(auto row : wall){
            for(auto i = 0, width = 0; i < row.size()-1;++i)
                min_bricks = min(min_bricks,wall.size()-(++edges[width+= row[i]]));
        }
        return min_bricks;
    }
};/