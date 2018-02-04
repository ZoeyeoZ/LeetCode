class Solution {
public:
    int climbStairs(int n) {
        long a = 1, b = 1;
        if (n<=1)
            return n;
        n--;
        while (n--){
            b += a;
            swap(a,b);
        }
        return a;
            
    }
};