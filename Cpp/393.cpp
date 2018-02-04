/*
1...1XXXX, followed by n-1 * 10XXXX
 |n|
0XXX
*/
class Solution {
public:
    bool validUtf8(vector<int>& data) {
    	int cnt = 0;
    	for (int d:data)
    		if (cnt==0) {
    			if ((d >> 5) == 0b110)//start with 110
                	cnt = 1;
                else if ((d >> 4) == 0b1110)
                	cnt = 2;
                else if ((d >> 3) == 0b11110)
                	cnt = 3;
                else if ((d >> 7)) //!=0, not 0XXXXXXX, invalid 1 byte
                	return false;
            } else {
                if ((d >> 6) != 0b10) //not start with 10
                	return false;
                cnt--;
            }
        return cnt==0;
    }
};
//15
/*12
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (const int val: data) {
            if (count == 0) {
                // if ((val >> 5) == 0b110) {
                //     count = 1;
                // }
                if ((val & 224) == 192) {
                    count = 1;
                }
                else if ((val & 240) == 224) {
                    count = 2;
                }
                else if ((val & 248) == 240) {
                    count = 3;
                }
                else if ((val & 128)) {
                    return false;
                }
            }
            else {
                if ((val >> 6) != 0b10) {
                    return false;
                }
                count--;
            }
        }
        return count == 0;
    }
};
*/