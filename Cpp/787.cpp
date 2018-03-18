/*
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
       	vector<vector<long>> dis(n, vector<long>(n, INT_MAX));
       	for (int i = 0; i < n; i++)
       		dis[i][i] = 0;
       	for (auto e : flights)
       		dis[e[0]][e[1]] = e[2];
       	bool flag = true;
       	while (--K >= 0){
       		for (int i = 0; i < n; ++ i)
       			for (int j = 0; j < n; ++ j)
       				for (auto e : flights){
       					long tmp = dis[i][e[0]] + e[2] + dis[e[1]][j];
       					if (tmp < dis[i][j]){
                            dis[i][j] = tmp;
                            flag = false;
                        }
       				}
       		if (flag)
       			break;
       	}
       	return dis[src][dst] == INT_MAX ? -1:dis[src][dst];
    }
};
//TLE
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
       	vector<long> dis(n, INT_MAX);
       	dis[src] = 0;
       	for (auto e : flights)
       		if (e[0] == src)
       			dis[e[1]] = e[2];
       	while (--K >= 0){
       		for (auto e : flights){
       			dis[e[1]] = min(dis[e[1]], dis[e[0]] + e[2]); 
       		}
       	}
       	return dis[dst] == INT_MAX ? -1:dis[dst];
    }
};
