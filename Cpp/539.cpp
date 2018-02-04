class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int h1 = stoi(timePoints[timePoints.size()-1].substr(0,2));
        int m1 = stoi(timePoints[timePoints.size()-1].substr(3,2));
        int h2 = stoi(timePoints[0].substr(0,2));
        int m2 = stoi(timePoints[0].substr(3,2));
        int tmp = abs((h2-h1)*60+(m2-m1));
        int ans = min(tmp,1440-tmp);

        for (int i=1; i<timePoints.size();i++){
        	h1 = stoi(timePoints[i-1].substr(0,2));
       		m1 = stoi(timePoints[i-1].substr(3,2));
        	h2 = stoi(timePoints[i].substr(0,2));
       		m2 = stoi(timePoints[i].substr(3,2));
        	tmp = abs((h2-h1)*60+(m2-m1));
        	ans = min(min(ans,tmp),1440-tmp);
        }

        return ans;
    }
};