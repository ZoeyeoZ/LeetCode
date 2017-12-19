//
/*
sol1: h[mostL...mostR]
sol2:
maintain a PQ <height,end time>
cur = 0,
nexT = PQ top end time;
if cur.begT > next // it ends before others coming
	pop all the buildings in Pq whose enttime <= nextT;
else{
	push all the buildings at the same time,cur++
	nexT = cur.beg
}
//nexT = PQ's heightest building's end time
curH = PQ's heightest or 0;
if != last height 
	add curH,nexT

*/

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    	vector<pair<int,int>> ans;
    	priority_queue<pair<int,int>> aliveB;
    	int cur = 0, nexT = 0, curH = 0, len = buildings.size();
    	while (!aliveB.empty() || (cur<len)){
    		if (aliveB.empty())
    			nexT = buildings[cur][0];
    		else 
    			nexT = aliveB.top().second;
    		if ((cur>=len)||(buildings[cur][0]>nexT))
    			while (!aliveB.empty() && aliveB.top().second<= nexT)
    				aliveB.pop();
    		else{
    			nexT = buildings[cur][0];
    			while ((cur<len)&&(buildings[cur][0]==nexT)){
    				aliveB.push(make_pair(buildings[cur][2],buildings[cur][1]));
    				cur++;
    			}
    		}
    		if (aliveB.empty())
    			curH = 0;
    		else 
    			curH = aliveB.top().first;
    		if ((ans.empty())||(ans.back().second!=curH))
    			ans.push_back(make_pair(nexT, curH));
    	}
    	return ans;
    }
};