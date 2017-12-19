class Solution {
public:
	vector<string> unit = {"Hundred", "Thousand", "Million", "Billion"};
    vector<string> lower = {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> higher = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string helper(int n){
    	if (n>=1000000000)
    		return helper(n/1000000000)+ " Billion" + helper(n%1000000000);
    	else if (n >= 1000000) 
    		return helper(n/1000000) + " Million" + helper(n%1000000);
    	else if (n >= 1000) 
    		return helper(n/1000) + " Thousand" + helper(n%1000);
    	else if (n >= 100) 
    		return helper(n/100) + " Hundred" + helper(n%100);
    	else if (n >= 20) 
    		return " " +higher[n/10-2] + helper(n%10);
    	else if (n >= 1)
    		return " "+lower[n-1];
    	else return "";
    }	

    string numberToWords(int num) {
    	if (num==0)
    		return "Zero";
    	else return helper(num).substr(1);
    }
};
/*
3ms
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string result;
        int i = 0;
        while (num) {
            if (num % 1000) {
                result = convert(num % 1000) + thousands[i] + " " + result;
            }
            num /= 1000;
            i++;
        }
        while (result.back() == ' ')
            result.pop_back();
        return result;
    }
private:
    const static string less_then_twenty[];
    const static string tens_place[];
    const static string thousands[];
    string convert(int num) {
        if (num == 0)
            return "";
        if (num < 20)
            return less_then_twenty[num] + " ";
        if (num < 100) {
            return tens_place[num / 10] + " " + convert(num % 10);
        }
        return less_then_twenty[num / 100] + " Hundred " + convert(num % 100);
    }
};
const  string Solution::less_then_twenty[] = {"", "One", "Two", "Three", "Four", "Five",
                                            "Six", "Seven", "Eight", "Nine", "Ten",
                                            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                                            "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const  string Solution::tens_place[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
                                      "Seventy", "Eighty", "Ninety"};
const  string Solution::thousands[] = {"", "Thousand", "Million", "Billion", "Trillion"};
*/