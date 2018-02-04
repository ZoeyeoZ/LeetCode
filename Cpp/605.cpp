class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    	int r = flowerbed.size()-1;
        for (int i = 0; i <= r && n > 0; i ++)
        	if (!flowerbed[i] && (i==0||!flowerbed[i-1]) && (i==r||!flowerbed[i+1])){
        		flowerbed[i] = 1;
        		n--;
        	}
        return n==0;
    }
};