//sort by end, greedy
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
    	if (points.size()<=1)
    		return points.size();
    	auto comp = [](const pair<int,int>& a, const pair<int,int>& b){
    		return a.second<b.second || a.second==b.second && a.first<b.first;
    	};
    	sort(points.begin(),points.end(),comp);
    	int ans = 1, p = points[0].second;
    	for (int i=1;i<points.size();i++){
    		if (points[i].first<=p)
    			continue;
    		p = points[i].second;
    		ans++;
    	}
    	return ans;
    }
};
//82
/*lower-109
//sort by end, greedy
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
    	auto comp = [](const pair<int,int>& a, const pair<int,int>& b){
    		return a.second<b.second || a.second==b.second && a.first<b.first;
    	};
    	sort(points.begin(),points.end(),comp);
    	int ans = 0;
    	long p = LONG_MIN;
    	for (auto point:points){
    		if (point.first<=p)
    			continue;
    		p = point.second;
    		ans++;
    	}
    	return ans;
    }
};
*/