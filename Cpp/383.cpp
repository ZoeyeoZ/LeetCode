class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> le(26, 0);
        for (int i=0; i<magazine.size(); i++)
            le[magazine[i] - 'a']++;
        for (int j=0; j<ransomNote.size(); j++)
            if (--le[ransomNote[j] - 'a'] < 0)
                return false;
        return true;
    }
};