//DP
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount+1);
        dp[0] = 0;
        for (int i=1; i<=amount; i++) 
            for (int j=0; j<coins.size(); j++) 
                if (coins[j]<=i) {
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
        return dp[amount]>amount ? -1 : dp[amount];
    }
};
/*
3ms
//two ways, 
//recursive, less space and less time;
class Solution {
private:
    void hp(vector<int>& coins, int amount, int start,int c,int &r){
        if(c+ceil(amount*1.0/coins[start]) >=r) return;
        if(amount==0) r=min(r,c);
        for(int i=start;i<coins.size();i++){
            if(coins[i]<=amount)
                hp(coins,amount-coins[i],i,c+1,r);
        }
    }
public:  
    int coinChange(vector<int>& coins, int amount){
        sort(coins.begin(), coins.end(), greater<int>());
        int  r= amount+1;
        hp(coins,amount,0,0,r);
        return (r==amount+1)?-1:r;
    }
};
//29ms
*/
//dynamic programming , more space and more time, but easy to understand
/*class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> a(amount+1, amount+1);
        a[0] = 0;
        for(auto c:coins){
            for(int i=c;i<=amount;i++){
               a[i]=min(a[i],a[i-c]+1); 
            }
        }
        return a[amount]==amount+1?-1:a[amount];
    }
};*/
