class Solution {
public:
    bool isPowerOfFour(int num) {
        // num &(num-1) == 0 <=> power of 2 <=> 2^n
        //4^m = 2^2m
        //3k+1,4,
        return ((num-1)&num)==0 && (num-1)%3==0;
    }
};