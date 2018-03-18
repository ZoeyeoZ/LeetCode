class Solution {
public:
    int rotatedDigits(int N) {
        int a[10] = {0,1,5,-1,-1,2,9,-1,8,6};
        int cnt = 0;
        for (int i = 1; i <= N; i++){
        	bool change = false;
        	bool valid = true;
        	int n = i;
        	while (valid && (n>0)){
        		if (a[n%10]==-1){
        			valid = false;
        		}
        		else if (a[n%10]!=n%10)
        			change = true;
        		n /= 10;
        	}
        	if (valid && change)
        		++ cnt;
        }
        return cnt;
    }
};