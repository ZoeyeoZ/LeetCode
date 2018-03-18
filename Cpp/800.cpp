class Solution {
public:
    string similarRGB(string color) {
    	vector<int> map(255,0);
    	for (int i = 0; i < 10; ++i)
    		map[48+i] = i;
    	for (int i = 0; i < 6; ++i)
    		map['a'+i] = 10+i;
    	string ans = "#";
    	for (int i = 1; i < 7; i += 2)
    		if (color[i] == color[i+1]){
    			ans += color[i];
    			ans += color[i];
    		}
    		else{
    			//cout<< color[i] << map[color[i]]<<endl;
    			int tmp = map[color[i]]*16+map[color[i+1]];
    			int tmp1 = map[color[i]]*16+map[color[i]];
	    		int tmp2 = tmp1 - 17;
	    		int tmp3 = tmp1 + 17;
	    		//cout<<ans<<endl;
	    		//cout << tmp<<"<"<<tmp1<<"<"<<tmp2<<"<"<<tmp3<<endl;
	    		if (color[i] == '0'){
	    			if (abs(tmp-tmp1)<abs(tmp-tmp3)){
	    				ans += color[i];
	    				ans += color[i];
	    			}
	    			else {
	    				ans += color[i]+1;
	    				ans += color[i]+1;
	    			}
	    		}
	    		else if (color[i] == 'f'){
	    			if (abs(tmp-tmp1)<abs(tmp-tmp2)){
	    				ans += color[i];
	    				ans += color[i];
	    			}
	    			else if (color[i]!='a'){
	    				ans += color[i]-1;
	    				ans += color[i]-1;
	    			}
	    			else{
	    				ans += '9';
	    				ans += '9';
	    			}
	    		}
	    		else{
	    			if (abs(tmp-tmp1)<abs(tmp-tmp2)){
	    				if (abs(tmp-tmp1)<abs(tmp-tmp3)){
		    				ans += color[i];
		    				ans += color[i];
		    			}
		    			else if (color[i]!='9'){
		    				ans += color[i]+1;
		    				ans += color[i]+1;
		    			}
		    			else{
		    				ans += 'a';
		    				ans += 'a';
		    			}
		    		}
		    		else {
	    				if (abs(tmp-tmp2)<abs(tmp-tmp3))
	    					if (color[i]!='a'){
			    				ans += color[i]-1;
			    				ans += color[i]-1;
			    			}
			    			else{
			    				ans += '9';
			    				ans += '9';
			    			}
		    			else if (color[i]!='9'){
		    				ans += color[i]+1;
		    				ans += color[i]+1;
		    			}
		    			else{
		    				ans += 'a';
		    				ans += 'a';
		    			}
		    		}
	    		}
    		}
    	return ans;
    }
};