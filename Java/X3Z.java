package com.company;

public class X3Z {

    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     *     int val;
     *     TreeNode left;
     *     TreeNode right;
     *     TreeNode(int x) { val = x; }
     * }
     */
    // 102. Binary Tree Level Order Traversal
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<List<Integer>> res = new LinkedList<>();
        if (root == null)
            return res;
        q.add(root);
        q.add(null);
        while (!q.isEmpty()){
            List<Integer> tmp = new LinkedList<Integer>();
            while ((root = q.poll()) != null){
                tmp.add(root.val);
                if (root.left != null)
                    q.add(root.left);
                if (root.right != null)
                    q.add(root.right);
            }
            res.add(tmp);
            if (!q.isEmpty())
                q.add(null);
        }
        return res;
    }

    // 349. Intersection of Two Arrays
    public int[] intersection(int[] nums1, int[] nums2) {
        if (nums1 == null || nums2 == null)
            return null;
        if (nums1.length == 0 || nums2.length == 0)
            return new int[0];
        Set<Integer> hs = new HashSet<>();
        for (int i = 0; i < nums1.length; i++) {
            hs.add(nums1[i]);
        }
        Set<Integer> res = new HashSet<>();

        for(int i = 0;i < nums2.length;i++){
            if (hs.contains(nums2[i])) {
                res.add(nums2[i]);
                hs.remove(nums2[i]);
            }
        }
        int[] res_ = new int[res.size()];
        int i = 0;
        for (int num : res) {
            res_[i++] = num;
        }
        return res_;
    }

    // 350. Intersection of Two Arrays II
    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map = new HashMap<>();
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < nums1.length; i++){
            if (map.containsKey(nums1[i]))
                map.put(nums1[i],map.get(nums1[i])+1);
            else
                map.put(nums1[i],1);
        }
        for (int i = 0; i < nums2.length; i++){
            if (map.containsKey(nums2[i]) && map.get(nums2[i]) > 0){
                res.add(nums2[i]);
                map.put(nums2[i],map.get(nums2[i])-1);
            }
        }
        int[] res_ = new int[res.size()];
        int i = 0;
        for (Integer num : res)
            res_[i++] = num;
        return res_;
    }

    // 719. Find K-th Smallest Pair Distance
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int low = 0, high = nums[n-1] - nums[0];
        while (low < high){
            int m = low + (high - low) / 2;
            int ct = 0;
            int p = 0;
            for (int i = 0; i < n; i++){
                while (p < i && nums[i] - nums[p] > m)
                    p++;
                ct += i-p;
            }
            if (ct < k)
                low = m + 1;
            else
                high = m;
        }
        return low;
    }

    // 33. Search in Rotated Sorted Array
    public int search(int[] nums, int target) {
        // find the start index
        int n = nums.length;
        int l = 0, r = n-1;
        while (l <= r){
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;
            if (nums[l] <= nums[m]){
                if (target < nums[m] && target >= nums[l])
                    r = m - 1;
                else
                    l = m + 1;
            }
            if (nums[m] <= nums[r]){
                if (target > nums[m] && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return -1;
    }

    // 81. Search in Rotated Sorted Array II
    public boolean search(int[] nums, int target) {
        // find the start index
        int n = nums.length;
        int l = 0, r = n-1;
        while (l <= r){
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return true;
            if (nums[l] == nums[m] && nums[r] == nums[m]){
                l++;
                r--;
            }
            else {
                if (nums[l] <= nums[m]){
                    if (target < nums[m] && target >= nums[l])
                        r = m - 1;
                    else
                        l = m + 1;
                }
                if (nums[m] <= nums[r]){
                    if (target > nums[m] && target <= nums[r])
                        l = m + 1;
                    else
                        r = m - 1;
                }
            }
        }
        return false;

    }

    // 668. Kth Smallest Number in Multiplication Table
    public int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n;
        while (low < high){
            int mid = low + (high - low) /2;
            int cnt = 0;
            for (int i = 1; i <= m; i++)
                cnt += Math.min(mid / i, n);
            if (cnt < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }


}
