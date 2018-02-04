class Solution {
public:
    bool detectCapitalUse(string word) {
    	if (word.size()<=1)
    		return true;
    	bool c1 = (word[0]<='Z');
    	bool c2 = (word[1]<='Z');
    	if (!c1 && c2) //aA
    		return false;
    	if (c1 && c2){ //AA
    		for (int i=2;i<word.size();i++)
    			if (word[i]>'Z')
    				return false;
    	}
    	else{ //Aa,aa
    		for (int i=2;i<word.size();i++)
    			if (word[i]<='Z')
    				return false;
    	}
    	return true;
    }
};

/*
6ms
class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i = 1; i < word.size(); i++)
        {
            if(isupper(word[i]) && islower(word[i-1]))
                return false;
            if(islower(word[i]) && isupper(word[i-1]) && i!=1)
                return false;
        }
        return true;
    }
};
*/