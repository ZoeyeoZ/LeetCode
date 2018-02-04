/*
zero,one,two,three,four,five,six,seven,eight,nine
0:z,2:w,4:u,6:x,8:g
1:o-0-2-4,3:h-8,5:f-4,7:s-6,9:i-5-6-8
*/
class Solution {
public:
    string originalDigits(string s) {
    	vector<int> ch(10,0);
    	vector<int> le(255,0);
    	for (char c:s)
    		le[c]++;
    	ch[0] = le['z'];
        ch[2] = le['w'];
        ch[4] = le['u'];
        ch[6] = le['x'];
        ch[8] = le['g'];
        ch[1] = le['o'] - ch[0] - ch[2] - ch[4];
        ch[3] = le['h'] - ch[8];
        ch[5] = le['f'] - ch[4];
        ch[7] = le['s'] - ch[6];
        ch[9] = le['i'] - ch[5] - ch[6] - ch[8];
    	string ans;
    	for (int i=0;i<10;i++)
    		if (ch[i]>0)
    			ans += string(ch[i],'0'+i);   
    	return ans; 
    }
};
/*19
16
typedef pair<int,int> pii;
class Solution {
public:
    string originalDigits(string s) {
        int dc[10] = {0};
        int cnt[26] = {0};
        char* number[] = {"zero", "one", "two",   "three", "four", 
                          "five", "six", "seven", "eight", "nine" };
        char* flag  = "zowhufxsgi";
        char* order = "0823456719";
        for (auto c : s) cnt[c-'a']++;
        for (int i=0; i<10; i++) {
            int c = order[i] - '0';
            int n = cnt[ flag[c] - 'a' ];
            if (!n) continue;
            dc[c] += n;
            int j = 0;
            while(number[c][j]) cnt[number[c][j++]-'a'] -= n;
        }
        string ans;
        for (int i=0;i<10;i++) {
            if (!dc[i]) continue;
            ans.append(dc[i], i+'0');
        }
        return ans;
    }
};
*/