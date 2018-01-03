/*
1..n=L=>2(1..n/2)=R=>2(..n/2-3,n/2-1)
L(n)+R(n)=1+n
L(n/2)+R(n/2)=1+n/2
R(n/2)=1+n/2-L(n/2)
*/class Solution {
public:
    int lastRemaining(int n) {
        return n==1 ? 1:2*(1+n/2-lastRemaining(n/2));
    }
};
//62
/*32
class Solution {
public:
    int lastRemaining(int n) {
        int step = 1, result = 1, remainNum = n;
        bool leftToRight = true;
        while (remainNum > 1) {
            if (leftToRight || remainNum % 2 == 1) {
                result += step;
            }
            step = step * 2;
            remainNum = remainNum / 2;
            leftToRight = !leftToRight;
        }
        return result;
    }
};
*/