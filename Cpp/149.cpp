/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
    	int n = points.size();
    	if (n<=2)
    		return n;
    	int ans = 0, tmp, dup, ver;
    	double k;
    	for (int i=0;i<n;i++){
    		unordered_map<double,int> Kmap;
    		tmp = ver = 1;
    		dup = 0;
    		for (int j=i+1;j<n;j++)
    			//duplicate, same x, k
    			if (points[i].x==points[j].x)
    				if (points[i].y==points[j].y)
    					dup++;
    				else
    					ver++;
    			else {
    				k = (points[j].y-points[i].y)*10.0/(points[j].x-points[i].x);
    				//10.0 is because of Point(0,0),Point(94911151,94911150),Point(94911152,94911151)
    				Kmap[k] = Kmap[k]==0 ? 2: Kmap[k]+1;
    				tmp = max(tmp,Kmap[k]);
                }
    		tmp = max(tmp+dup, dup+ver);
            ans = max(ans,tmp);
    	}
        return ans;
    }
};