package com.company;

public class P349 {
    public int[] intersection(int[] nums1, int[] nums2) {
        if (nums1 == null || nums2 == null)
            return null;
        if (nums1.length == 0 || nums2.length == 0)
            return new int[0];
        Set<Integer> hs = new HashSet<Integer>();
        for (int i = 0; i < nums1.length; i++) {
            hs.add(nums1[i]);
        }
        Set<Integer> res = new HashSet<Integer>();
        for(int i = 0;i < nums2.length;i++){
            if (hs.contains(nums2[i])) {
                res.add(nums2[i]);
                hs.remove(nums2[i]);
            }
        }
        int[] res_ = new int[res.size()];
        int i = 0;
        for (Integer num : res) {
            res_[i++] = num;
        }
        return res_;
    }
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        ArrayList<Integer> res = new ArrayList<Integer>();
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
}
