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
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty())
            return {};
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        int end = intervals[0].end, beg = intervals[0].start;
        vector<Interval> ans;
        for (int i=1; i<intervals.size(); i++){
            if (intervals[i].start<=end)
                end = max(end,intervals[i].end);
            else {
                ans.push_back(Interval(beg,end));
                beg = intervals[i].start;
                end = intervals[i].end;
            }
            
        }
        if (beg!=-1)
            ans.push_back(Interval(beg,end));
        return ans;
    }
};