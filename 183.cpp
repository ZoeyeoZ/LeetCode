class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> DNA;
        int i=0;
        string ss;
        vector<string> ans;
        while (i+10<=s.length()){
            ss = s.substr(i,10);
            switch(DNA[ss]){
                case 0: DNA[ss] = 1;
                        break;
                case 1: ans.push_back(ss);
                        DNA[ss] = 2;
                        break;
            }
            i++;
        }
        return ans;
        
    }
};

/*

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        char flag[262144] ={0};
        vector<string> result;
        int len,DNA=0,i;
        if((len=s.length())< 11) return result;
        for(i = 0 ; i < 9; i++)
            DNA = DNA << 2| (s[i] - 'A' + 1) % 5;
        for(i = 9;i<len;i++)
        {
            DNA = (DNA<<2 & 0xFFFFF)|((s[i] - 'A' + 1)%5);
                if(!(flag[DNA>>2]&(1<<((DNA&3) << 1)))) 
                    flag[DNA>>2] |= (1<<((DNA&3) << 1));
                else if(!(flag[DNA>>2]&(2<<((DNA&3) << 1)))) 
                {
                    result.push_back(s.substr(i-9,10));
                    flag[DNA>>2] |= (2<<((DNA&3) << 1));
                }
        }
        return result;
    }
};*/
