/*
buy[i] means before day i what is the maxProfit for any sequence end with buy.
sale[i] means before day i what is the maxProfit for any sequence end with sale.
rest[i] means before day i what is the maxProfit for any sequence end with rest.

buy[i]  = max(rest[i-1]-price, buy[i-1]) 
sale[i] = max(buy[i-1]+price, sale[i-1])
rest[i] = max(sale[i-1], buy[i-1], rest[i-1]) 

since buy[i]<=rest[i] => rest[i] = max(sale[i-1], rest[i-1])
since sale[i]>=buy[i-1]+price>=rest[i-1]-price+price>=rest[i-1] => rest[i]=sale[i-1]

buy[i]  = max(sale[i-2]-price, buy[i-1]) 
sale[i] = max(buy[i-1]+price, sale[i-1])
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int buy = INT_MIN, sale = 0, pre_sale = 0, pre_buy;
    	for (int p:prices){
    		pre_buy = buy;
    		buy = max(pre_sale-p,buy);
    		pre_sale = sale;
    		sale = max(pre_buy+p,sale);
    	}
    	return sale;
    }
};