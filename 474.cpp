/*
DP[i][j][k] get i*'0' and j*'1', using 1..k strings
decrease space
for k=1..l
	i=m..s0,n..s1
	dp[i][j] = max(dp[i][j],dp[i-s0][j-s1]+1)// not use s or use s
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
    	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    	for (auto s:strs){
    		int s0 = 0, s1 = 0;
    		for (auto ch:s)
    			if (ch=='0')
    				s0++;
    			else 
    				s1++;
    			for (int i=m;i>=s0;i--)
    				for (int j=n;j>=s1;j--)
    					dp[i][j] = max(dp[i][j],dp[i-s0][j-s1]+1);
    	}
    	return dp[m][n];
    }
};
//53
/*
6ms
class Solution {
public:
    template <class T>
    void swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }
    
    int partition(vector<string>& strs, int *zero, int *one, int start, int end, int diff)
    {
        int pivotZero = zero[start];
        int pivotOne = one[start];
        int pivotLen = pivotZero + pivotOne;
        swap(strs[start], strs[end]);        
        swap(zero[start], zero[end]);        
        swap(one[start], one[end]);
        int j = start;
        for(int i = start; i < end; i++)
        {
            if(((diff >  0) && ( one[i] < pivotOne  || ( one[i] == pivotOne  && zero[i] < pivotZero))) 
             ||((diff <  0) && (zero[i] < pivotZero || (zero[i] == pivotZero &&  one[i] < pivotOne )))
             ||((diff == 0) && ( one[i] + zero[i] < pivotLen || (one[i] + zero[i] == pivotLen && one[i] < pivotOne))))
            {
                swap(strs[i], strs[j]);
                swap(zero[i], zero[j]);
                swap(one[i], one[j]);
                j++;
            }
        }
        swap(strs[j], strs[end]);
        swap(zero[j], zero[end]);
        swap(one[j], one[end]);
        return j;
    }
    
    void quickSort(vector<string>& strs, int *zero, int *one, int start, int end, int diff)
    {
        if(start >= end) return;
        int pivot = partition(strs, zero, one, start, end, diff);
        quickSort(strs, zero, one, start, pivot - 1, diff);
        quickSort(strs, zero, one, pivot + 1, end, diff);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        int zero[size];
        int one[size];
        for(int i = 0; i < size; i++)
        {
            int len = strs[i].length();
            zero[i] = 0;
            for(int j = 0; j < len; j++)
            {
                zero[i] += (strs[i][j] == '0');
            }
            one[i] = len - zero[i];
        }
        
        // IMPORTANT! 
        //   In Dynamic Programming, the strings with smaller index will be visited first.
        //   Before that, the order of different strings should be considered.
        //   1. If m > n, in order to save the usage of 1's
        //    - sort the string sequence in ascending order by the number of 1's that every string has.
        //    - when strings have equal number of 1's, sort them in ascending order by the number of 0's that every string has.
        //   2. If m < n, in order to save the usage of 0's
        //    - sort the string sequence in ascending order by the number of 0's that every string has.
        //    - when strings have equal number of 0's, sort them in ascending order by the number of 1's that every string has.
        //   3. If m = n,            
        //    - sort the string sequence in ascending order by string's length.
        //    - when strings have equal length, sort them in ascending order by the number of 0's that every string has.
        
        quickSort(strs, zero, one, 0, size - 1, m - n);
        
        
        //
        // DP:
        // In DP, 3 different arrays are saved.
        // - record[i] : the maximum number of strings containing strs[i] that can be made from strs[0], strs[1],...,strs[i]
        // - restOne[i] : the number of rest 1's after using strs[i] to make the maximum-number-string
        // - restZero[i] : the number of rest 0's after using strs[i] to make the maximum-number-string
        
        int maximum = 0;
        int record[size];
        int restOne[size];
        int restZero[size];
        for(int i = 0; i < size; i++)
        {
            int localMax = 0;
            int localMaxIndex = -1;
            for(int j = 0; j < i; j++)
            {
                // Can strs[j] be attached to record[j] to make the total number of string larger ?
                // the zeros and ones after using record[j] should be larger than those that strs[j] contains 
                if(restZero[j] >= zero[i] && restOne[j] >= one[i])
                {
                    // Among all candidates, always keep the one with maximum record[j] 
                    if(record[j] > localMax)
                    {
                        localMax = record[j];
                        localMaxIndex = j;
                    }
                }
            }
            if(localMax > 0)
            {
                // If maximum record[j] exists 
                record[i] = localMax + 1;                                 // attach strs[i] to the total number 
                restZero[i] = restZero[localMaxIndex] - zero[i];          // save the rest zeros after attaching 
                restOne[i] = restOne[localMaxIndex] - one[i];             // save the rest ones after attaching 
            }else{
                // If maximum record[j] doesn't exist 
                if(m - zero[i] >= 0 && n - one[i] >= 0)
                {
                    // strs[i] can be a single string 
                    record[i] = 1;
                    restZero[i] = m - zero[i];
                    restOne[i] = n - one[i];
                }else{
                    // strs[i] can not be a single string 
                    // Since localMax = 0, the entry will never be visited. 
                    record[i] = 0;
                }
            }
            if(record[i] > maximum) maximum = record[i];
        }
        return maximum;
    }
};
*/
