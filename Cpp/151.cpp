class Solution {
public:
    void reverseWords(string &s) {
    	// the sky is blue
    	//reverse every word -> eht yks si eulb
    	//reverse whole string -> blue is..
    	int len = s.length();
    	int i = 0, j = 0, pre, k;
    	int words = 0;
    	char ch;
    	while (true){
    		//move front space
    		while (i<len && s[i]==' ') i++;
    		if (i==len)
    			break;
    		if (words>0){
    			s[j] = ' ';
    			j++;
    		}
    		pre = j;
    		while (i<len && s[i]!=' '){
    			s[j] = s[i];
    			i++,j++;
    		}
    		//reverse word
    		words++;
    		k = j-1;
    		while (pre<k){
    			ch = s[pre];
    			s[pre] = s[k];
    			s[k] = ch;
    			pre++,k--;
    		}
    	}
    	s.resize(j);
    	pre = 0, k =j-1;
    	while (pre<k){
    		ch = s[pre];
    		s[pre] = s[k];
    		s[k] = ch;
   			pre++,k--;
    	}
    }
};