class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        for (int k=0;k<s.length();k++)
            s[k] = tolower(s[k]);
        while (i<j){
            while (i<s.length() && !(s[i]>='a' && s[i]<='z') && !(s[i]>='0' && s[i]<='9')) i++;
            while (j>0 && !(s[j]>='a' && s[j]<='z') && !(s[j]>='0' && s[j]<='9')) j--;  
            if (i<j && s[i]!=s[j])
                return false;
            else 
                i++,j--;
        }
        return true;
    }
};