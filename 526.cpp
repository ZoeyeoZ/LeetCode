class Solution {
public:
	int helper(vector<int>& v, int N){
		if (N<=0)
			return 1;
		int ans = 0;
		for (int i=0; i<N; i++)
			if (v[i]%N==0 || N%v[i]==0){
				swap(v[i],v[N-1]);
				ans += helper(v,N-1);
				swap(v[i],v[N-1]);
			}
		return ans;
	}
    int countArrangement(int N) {
    	vector<int> v(N,0);
    	for (int i=0;i<N;i++)
    		v[i] = i+1;
    	return helper(v,N);
    }
};