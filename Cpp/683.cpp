/*
flowers[i] = x : the unique flower that blooms at day i+1 will be at position x
=> day[x-1] = i+1

x1 = f[i], x2 = f[j], x1 < x2
sum( x1 < f[max(i,j)+1...N-1] < x2) == k
=>
sliding window
left = x, right = x+k+1
day[x+1]...day[x+k] > max(day[left],day[right])
*/
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
    	int ans = INT_MAX;
    	int n = flowers.size();
    	vector<int> days(n,0);
    	for (int i = 0; i < n; ++i)
    		days[flowers[i]-1] = i + 1;
    	int left = 0, right = k+1;
    	int day = max(days[left],days[right]);
    	for (int i = 1; right < n; ++i){
    		if (days[i] > day)
    			continue;
    		if (i == right) // find one
    			ans = min(ans,day);
    		left = i;
    		right = i+k+1;
    		day = max(days[left],days[right]);
    	}
    	return ans == INT_MAX ? -1 : ans;    
    }
};