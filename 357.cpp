/*
n=0,[0,1),1
n=1,[0,1)+[1,10),1+9
n=2,[0,1)+[1,10)+[10,100),..+任选两位A(10,2)-0在前面A(9,1)=..+9*A(9,1)
n=3,...+A(10,3)-A(9,2)=..+9*A(9,2)
n=k,...+9*A(9,k-1);
..n=10
*/class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
    	if (n==0)
    		return 1;
    	if (n>10)
    		n = 10;
    	int pro = 1,ans = 10;
    	for (int i=9;i>10-n;i--){
    		pro *= i;
    		ans += 9*pro;
    	}
    	return ans;     
    }
};