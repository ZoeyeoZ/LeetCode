/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
    	auto comp = [](const Interval& i1, const Interval& i2) {
    		return i1.start<i2.start || i1.start==i2.start && i1.end<i2.end;
    	};
    	sort(intervals.begin(),intervals.end(),comp);
    	int ans = 0, last = 0;
    	for (int i=1; i<intervals.size(); i++)
    		//overlap: last.start--i.start--last.end
    		if (intervals[i].start<intervals[last].end) {
                ans++;
                //save the last end
                if (intervals[i].end<intervals[last].end) 
                	last = i;
            }
            else last = i;
        return ans;

        
    }
};