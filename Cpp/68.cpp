// n letter, n-1 space
// (4)+1+3+(2)+1+3+(2) = 16
// (7)+1+1+(2)+1+0+(4), 16-13-2=1
// (14), 16-14 =2

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	vector<string> ans;
    	for (int i=0, k, l; i<words.size(); i += k+1){
    		for (k=l=0; i+k<words.size() & l+words[i+k].size()+k<=maxWidth; k++)
    			l += words[i+k].size();
    		string tmp = words[i];
    		k--;
    		cout << l<<","<<k<<endl;
    		for (int j =1; j<=k; j++){
    			if(i + k >= words.size()-1) //last line
    				tmp += " ";
    			else 
    				tmp += string((maxWidth-l)/k+((j-1)<(maxWidth-l)%k),' ');
    			tmp += words[i+j];
    		}
    		tmp += string(maxWidth-tmp.size(),' ');
    		ans.push_back(tmp);
    	}
        return ans;
    }
};
