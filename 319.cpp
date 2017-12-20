/*
A light will be toggled only during the round of its factors.
If odd, the light is on and if even the light is off.
Since x = ab=cd=ef =..., 
The number of one number's factor is odd if and only if it is a perfect square!
*/
class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);
    }
};
//3ms
/*
0ms
int res = 1;
while(res*res <= n) res++;
return res-1;
*/