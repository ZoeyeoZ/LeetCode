//C0,k;C1,k;
//Ci,k = Ci-1,k*(k-i+1)/i

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> ans(rowIndex+1,1);
    	for (int i=1; i<=rowIndex/2; i++){
    		ans[i] = ans[rowIndex-i] = (long) ans[i-1]*(rowIndex-i+1)/i;
    	}
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int a[rowIndex+5];
        memset(a, 0, sizeof(a));
        
        a[0] = 1;
        for (int i=1; i<=rowIndex; i++) {
            int prev = a[0];
            for (int j=1; j<=i; j++) {
                int s = a[j];
                a[j] = a[j] + prev;
                prev = s;
            }
        }
        
        vector<int> ans;
        for (int i=0; i<=rowIndex; i++)
            ans.push_back(a[i]);
        
        return ans;
    }
};*/
