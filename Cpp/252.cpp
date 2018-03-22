/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
// sort with start time, itv[i].end>itc[i+1].start -> overloap
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
    	int n = intervals.size();
    	if (n == 0)
    		return true;
    	auto comp = [](Interval& a, Interval& b){
    		return a.start < b.start;
    	};
    	sort(intervals.begin(),intervals.end(),comp);
        for (int i = 0; i < n-1; ++i)
        	if (intervals[i].end > intervals[i+1].start)
        		return false;
        return true;
    }
};