/*
4 C++ Solutions using Partition, Max-Heap, priority_queue and multiset respectively
https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309

3 C++ solutions (O(NlogN) sort, O(klogN) heapsort, O(n) average quicksort-kind )
https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60564
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	//min_heap / priorityqueue
    	priority_queue<int, vector<int>, greater<int>> q;
    	for (auto n:nums){
    		q.push(n);
    		if (q.size()>k)
    			q.pop();
    	}
    	return q.top();
    }
};