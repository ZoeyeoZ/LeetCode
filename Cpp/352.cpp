/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
private:
	struct cmp{
		bool operator()(Interval a, Interval b){
			return a.start<b.start;
		}
	};
	//unordered_set基于哈希表，是无序的。set:红黑树的平衡二叉检索树
	set<Interval, cmp> s;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
    	int st = val, ed = val;
    	auto i = s.lower_bound(Interval(val, val));

    	//!st-ed-val
    	if (i!=s.begin() && (--i)->end+1<val)
    		i++;

    	//val-st-ed, st-val-ed, st-ed-val
    	while(i!=s.end() && i->start<=val+1 && val-1<=i->end){
    		st = min(st,i->start);
    		ed = max(ed,i->end);
    		i = s.erase(i);
    	}
    	s.insert(i,Interval(st,ed));
    }
    
    vector<Interval> getIntervals() {
    	vector<Interval> ints;
    	for (auto i:s)
			ints.push_back(i);
		return ints;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

//binary search
/*
class SummaryRanges {
    struct cmp {
        bool operator() (const Interval a, const Interval b) {
            return a.end < b.start;
        }
    };
private:
    // set<Interval, cmp> dict;
    vector<Interval> res;
    // bool modified = false;
    int bsearch(int val) {
        int start = 0, end = res.size(), mid;
        while(start < end) {
            mid = (start + end) / 2;
            if(res[mid].end == val - 1)
                return mid;
            else if(res[mid].end < val - 1)
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }
    
public:
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        // auto b = dict.equal_range({val - 1, val + 1});
        // int start = val, end = val;
        // for(auto it = b.first; it != b.second; ) {
        //     start = min(it->start, start);
        //     end = max(it->end, end);
        //     it = dict.erase(it);
        // }
        // dict.insert(Interval(start, end));
        // modified = true;
        int pos = bsearch(val);
        if(pos == res.size())
            res.push_back(Interval(val, val));
        else if(res[pos].start > val + 1)
            res.insert(res.begin() + pos, Interval(val, val));
        else if(res[pos].start == val + 1)
            res[pos].start = val;
        else if(res[pos].end == val - 1) {
            res[pos].end = val;
            if(pos + 1 < res.size() && res[pos + 1].start == val + 1) {
                res[pos].end = res[pos + 1].end;
                res.erase(res.begin() + pos + 1);
            }
        }
    }
    
    vector<Interval> getIntervals() {
        // if(modified) {
        //     modified = false;
        //     res = vector<Interval> (dict.begin(), dict.end());
        // }
        return res;
    }
};
*/