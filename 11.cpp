// Container With Most Water
/*
since it's a container, s = |(j-i)*(aj-ai)| 

the Proof:
	if there is So(>S), we can prove one of the side must be same.

*/

class Solution {
public:
 	int maxArea(vector<int>& height){
 		int l = 0, r = height.size()-1;
 		int maxS = 0;
 		while (l<r){
 			maxS = max(maxS,(r-l)*min(height[l],height[r]));
 			if (height[l] < height[r])
 				l++;
 			else 
 				r--;
 		}
 		return maxS;
	}
};