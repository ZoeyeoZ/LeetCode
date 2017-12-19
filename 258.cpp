/*
https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
10^n ≡ 1 (mod 9), so  a_n*10^n + ... + a_1*10 + a_0 ≡ a_n + ... + a_1 + a_0 (mod 9).
=>  int res = num % 9;
    return (res != 0 || num == 0) ? res : 9;
*/
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};