/*
O(n^2) -> distances
for every distance -> C(k,2)
*/
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
    	int ans = 0;
    	int n = points.size();
    	for (int i=0; i<n; i++){
    		unordered_map<long,int> dis(n);
    		for (int j=0;j<n;j++){
    			if (i==j)
    				continue;
    			long dx = points[i].first-points[j].first, dy = points[i].second-points[j].second;
    			dis[dx*dx+dy*dy]++;
    		}
    		for (auto d:dis)
    			if (d.second>1)
    				ans += d.second*(d.second-1);
    	}
        return ans;
    }
};
//213
/*103
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int result = 0, n = points.size();
        int dis[n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){ 
                int x = points[i].first - points[j].first;
                int y = points[i].second - points[j].second;
                dis[j] = x*x + y*y;
            }
            reverse(dis, dis+n);
            sort(dis, dis+n);
            
            int k=1;
            for(int j=1;j<n;j++){
                if(dis[j]==dis[j-1]) k++;
                else {
                    result += k*(k-1);
                    k = 1;
                }
            }
            result += k*(k-1);
        }
        return result;
    }
};
//store n distances, and sort, caculate the same disatance -> C(k,2)
*/
