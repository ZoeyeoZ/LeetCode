class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, spa = s.length()-1;
        while ((spa>=0)&&(s[spa]==' '))
            spa --;
        while ((spa>=0)&&(s[spa]!=' ')){
            len ++;
            spa --;
        }
        return len;
    }
};