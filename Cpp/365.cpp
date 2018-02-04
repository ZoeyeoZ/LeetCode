/*
https://leetcode.com/problems/water-and-jug-problem/discuss/
GCD，greatest common divisor
(x,y)=1,z can be [0,x+y]
Proof:
y%x = 1, 2y%x = 2, ...(x-1)y%x = x-1
*/
class Solution {
public:
	int gcd(int x, int y){
		return y==0 ? x : gcd(y,x%y);
	}
    bool canMeasureWater(int x, int y, int z) {
        return z==0 || z<= (long) x+y && z%gcd(x,y)==0;
    }
};