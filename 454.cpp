class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> ABS;
        for (int a:A)
        	for (int b:B)
        		ABS[a+b]++;
        int cnt = 0;
        for (int c:C)
        	for (int d:D){
        		auto ans = ABS.find(0-c-d);
        		if (ans!=ABS.end())
        			cnt += ans->second;
        	}
        return cnt;
    }
};