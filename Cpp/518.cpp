class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount==0)
            return 1;
        if (coins.size()==0)
            return 0;
        vector<int> dp(amount+1,0);
        dp[0] = 1;
        for (auto c:coins)
            for (int j=c; j<=amount; j++) // since every coin can be used several times
            //for (int j=amount; j>=c; j--)
                dp[j] += dp[j-c];
        return dp[amount];
    }
};