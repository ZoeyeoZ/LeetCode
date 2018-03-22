/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//similar to 252, 253
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
    	vector<int> starts, ends;
    	for (auto s:schedule)
    		for (auto i:s){
	    		starts.push_back(i.start);
	    		ends.push_back(i.end);
    		}
    	sort(starts.begin(),starts.end());
    	sort(ends.begin(),ends.end());
    	vector<Interval> ans;
    	for (int i = 0; i < starts.size() - 1; ++i)
    		if (ends[i] < starts[i+1])
    			ans.push_back(Interval(ends[i],starts[i+1]));
    		// ==> starts[ends[i].index] < starts[i+1]
    		// ==> there is i starts and they have already ended
    		// ==> there is free interval x before next i+1 start
    	return ans; 
    }
};