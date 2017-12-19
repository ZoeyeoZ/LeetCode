#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int m = nums1.size(), n = nums2.size();
    	if (m < n) return findMedianSortedArrays(nums2,nums1);
    	if (n == 0) return (nums1[(m-1)/2]+nums1[m/2])/2.0;
    	int l1,r1,l2,r2,m1,m2;
    	int l = 0, r = n * 2;
        while (l <= r){
        	m2 = (l+r)/2;
        	m1 = m+n-m2;
        	l1 = (m1 == 0) ? INT_MIN : nums1[(m1-1)/2]; // lower mid
        	l2 = (m2 == 0) ? INT_MIN : nums2[(m2-1)/2];
        	r1 = (m1 == 2*m) ? INT_MAX : nums1[m1/2]; //uppder mid
        	r2 = (m2 == 2*n) ? INT_MAX : nums2[m2/2]; 
        	if (l1>r2) l = m2+1; // more in left B
        	else if (r1<l2) r = m2-1; 
        	else return (max(l1,l2)+min(r1,r2))/2.0;
        }
        return 0;

        /*
    	int l1 = 0, r1 = m-1, l2 = 0, r2 = n-1;
    	int k = 0;
    	if (m == 0)
    		if (n%2 == 1 ) return nums2[n/2];
    		else return (nums2[n/2-1]+nums2[n/2])/2.0;
    	else if (n == 0)
    		if (m%2 == 1 ) return nums1[m/2];
    		else return (nums1[m/2-1]+nums1[m/2])/2.0;
    	while (k<((m+n)/2)-(1-(m+n)%2)){
    		cout << "1:"<<l1<<r1<<l2<<r2<<k<<endl;
    		if (nums1[(l1+r1)/2]<nums2[(l2+r2)/2]){
    			k += (r1-l1)/2+1;
    			l1 = (l1+r1)/2+1;
    		}
    		else {
    			k += (r2-l2)/2+1;
    			l2 = (l2+r2)/2+1;
    		}	
    		cout << "2:"<<l1<<r1<<l2<<r2<<k<<endl;
    		if (l1 > r1) 
    			if ((m+n)%2 == 1 ) return nums2[(m+n)/2-k+1];
    			else 
    				if (k == (m+n)/2) return (nums1[r1]+nums2[(m+n)/2-k])/2.0;
    				else return (nums2[(m+n)/2-k-1]+nums2[(m+n)/2-k])/2.0;
    		if (l2 > r2) 
    			if ((m+n)%2 == 1 ) return nums1[(m+n)/2-k+1];
    			else 
    				if (k == (m+n)/2) return (nums2[r2]+nums1[(m+n)/2-k])/2.0;
    				else return (nums1[(m+n)/2-k-1]+nums1[(m+n)/2-k])/2.0;
    	}
    	if ((m+n)%2 == 1 ) return min(nums1[l1],nums2[l2]);
    	else {
    		int s = 0;
    		if (nums1[l1] < nums2[l2]){
    			s += nums1[l1];
    			if (l1+1>=m) s += nums2[l2];
    			else s += min(nums1[l1+1],nums2[l2]);
    		}
    		else {
    			s += nums2[l2];
    			if (l2+1>=n) s += nums1[l1];
    			else s += min(nums2[l2+1],nums1[l1]);

    		}
    		return s/2.0;
    	}*/
    	
    }
};
int main(){
	Solution s;
	vector<int> nums1;
	vector<int> nums2;
	int x;
	while (cin >>x && x!=-1){
		nums1.push_back(x);
	}
	while (cin >>x && x!=-1){
		nums2.push_back(x);
	}

	cout << s.findMedianSortedArrays(nums1,nums2);

	return 0;
 }