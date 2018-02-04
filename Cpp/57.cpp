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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int beg = newInterval.start, end = newInterval.end;
        int i;
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        for (i=0; i<intervals.size(); i++){
        	if (intervals[i].end<beg)
        		ans.push_back(intervals[i]);
        	else if(intervals[i].start>end){
        		ans.push_back(Interval(beg,end));
        		break;
        	}
        	else{
        		beg = min(beg,intervals[i].start);
        		end = max(end,intervals[i].end);
        	}
        }
        if (i<intervals.size()){
        	for (int j=i; j<intervals.size(); j++)
        			ans.push_back(intervals[j]);
        }
        else 
        	ans.push_back(Interval(beg,end));
        return ans;
        
    }
};