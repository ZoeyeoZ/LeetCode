/*
k-(n-1)!
k=4 -> k--,3
2!=2, 3/2 = 1 => '2', k = 3-1*2 = 1
1!=1, 1/1 = 1 => '3', k = 1-1*1 = 0
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        vector<char> num;
        string ans = "";
        int mul = 1;
        for (int i=1; i<=n; i++){
        	mul *= i;
        	num.push_back('0'+i);
        }
        for (int i=0; i<n; i++){
        	mul /= n-i;
        	ans += char(num[k/mul]);
        	//int j = i+k/f;
        	num.erase(num.begin()+k/mul);
        	k -= k/mul*mul;
        }
        return ans;  
    }
};