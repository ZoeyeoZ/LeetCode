class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    	struct Fac{
    		int p, q;
    		float f;
    		Fac(int p, int q): p(p), q(q), f(p*1.0/q){};
    	};
    	auto comp = [](const Fac &a, const Fac &b){
    		return a.f < b.f;
    	};
    	priority_queue<Fac, vector<Fac>, comp> pq;
    	int n = A.size();
    	for (int i = 0; i < n; ++ i)
    		for (int j = 0; j < n; ++ j)
    			if (i!=j){
	    			int p = A[i];
	    			int q = A[j];
	    			Fac fac = new Fac(p, q);
	    			pq.push_back(fac)
	    		}
	    while (--K){
	    	pq.pop_back();
	    }
        return {pq.front().p, pq.front().q};
    }
};