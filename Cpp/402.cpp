class Solution {
public:
    string removeKdigits(string num, int k) {
    	if (k==0)
    		return num;
    	int l = num.length();
    	if (l==k)
    		return "0";
    	int id=1;
    	for (int i=1;i<l;i++){
    		//if smaller => num[i-1] is the peak number, replace it
    		while (k>0 && id>=1 && num[i]<num[id-1]){
    			id--;
    			k--;
    		}
    		num[id] = num[i];
    		id++;
    		//if done, copy the rest
    		if (k==0){
    			i++;
    			for (;i<l;i++)
    				num[id++] = num[i];
    			break;
    		}
    		//cout<<num.substr(0,id)<<endl;
    	}
    	//remove '0'
    	int begid = 0;
    	while (num[begid]=='0' && begid<id-k-1)
    		begid++;
    	return num.substr(begid,id-begid-k);
        
    }
};