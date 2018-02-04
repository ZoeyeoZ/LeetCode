// sum(gas[i]-cost[i])>=0 => there is a start position
// subsum minimual, the remain largest.
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int total = 0, ansD = INT_MAX, ansI = 0, n = gas.size();
    	for (int i=0; i<n; i++){
    		total += gas[i] - cost[i];
    		if (total<ansD){ // ansI..i < 0 => cannot start there
    			ansD = total;
    			ansI = i+1;
    		}
    	}
    	return total<0 ? -1:ansI%n;
    }
};