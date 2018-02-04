class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX, maxPro = 0;
        for (int p:prices){
            minP = min(minP,p);
            maxPro = max(maxPro,p-minP);
        }
        return maxPro;    
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i=1;i<prices.size();i++)
            ans += max(prices[i]-prices[i-1],0);
        return ans;
        
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //maximum : if we just buy 1st; sale 1st; buy 2nd; sale 2nd
        int b1 = INT_MIN, b2 = INT_MIN, s1 = 0, s2 = 0;
        for (int p:prices){
            s2 = max(s2,b2+p);
            b2 = max(b2,s1-p);
            s1 = max(s1,b1+p);
            b1 = max(b1,-p);
        }
        //since at begin, s2 will at least eauql s1
        return s2;
    }
};