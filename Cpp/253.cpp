/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
sort with start & sort with end
i, j <= i
if si < ej <=> i==j | when i comes, j is not end
=> overlap && ej<=i.end 
=> since ej<=i.end, add another room -> i, next i
ele next j 
*/
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
    	vector<int> starts, ends;
    	for (auto i:intervals){
    		starts.push_back(i.start);
    		ends.push_back(i.end);
    	}
    	sort(starts.begin(),starts.end());
    	sort(ends.begin(),ends.end());
    	int ans = 0, j = 0;
    	for (int i = 0; i < intervals.size(); ++i)
    		if (starts[i] < ends[j])
    			++ ans;
    		else 
    			++ j;
    	return ans;
    }
};