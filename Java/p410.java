package com.company;

public class p410 {
    // Binary Search for the valid sum
    public int splitArray(int[] nums, int m) {
        long l = 0; // max of nums, which is the minimal possible res
        long r = 0; // sum of nums, which is the maximal possible res
        for (int num : nums){
            r += num;
            l = Math.max(l,num);
        }
        if (m == 1)
            return (int) r;
        while (l < r){
            long mid = l + ((r - l ) >>> 1);
            if (isValid(mid, nums, m))
                r = mid;
            else
                l = mid +1;
        }
        return (int) r;
    }
    public boolean isValid(long mid, int[] nums, int m){
        int cnt = 1;
        long sum = 0;
        for (int num : nums){
            sum += num;
            if (sum > mid){
                sum = num; // since we get mid, so this num should not be added
                cnt ++;
                if (cnt > m) // should larger && when sum>mid => at least cnt+1, so cnt initialize as 1
                    return false;
            }
        }
        return true;
    }
}
