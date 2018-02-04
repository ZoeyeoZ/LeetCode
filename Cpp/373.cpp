class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    	int n1 = nums1.size(), n2 = nums2.size();
    	vector<pair<int, int>> ans;
    	if (n1==0 || n2==0 || k==0) 
    		return ans;
       	int i = 0, j = 0;
       	vector<int> id2(n1,0);//record lastness n2 pair with n1;
       	while (k-->0){
       		int min = INT_MAX;
       		int id = -1;
       		for (int id1=0;id1<n1;id1++){
       			if (id2[id1]>=n2)
       				continue;
       			if (nums1[id1]+nums2[id2[id1]]<min){
       				min = nums1[id1]+nums2[id2[id1]];
       				id = id1;
       			}
       		}
       		if (id==-1)
       			break;
       		ans.push_back(make_pair(nums1[id],nums2[id2[id]]));
       		id2[id]++;
       	}
       	return ans;
    }
};