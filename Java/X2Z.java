package com.company;

import java.util.*;

public class X2Z {
    /*
    215. Kth Largest Element in an Array

    sol1.
    Quick Select, average:O(n), worst:O(n2)
    if <num, swap to left, left++
    num move to left
    if left == k -> found
            <  k -> right part
            >  k -> left part

    sol2.
    PriorityQueue, O(nlgk)
    */
    public int findKthLargest(int[] nums, int k) {
        if (nums == null || nums.length == 0)
            return -1;
        return helperQuickSelect(nums, 0, nums.length-1, nums.length-k);
    }
    public int helperQuickSelect(int[] nums, int bg, int ed, int k) {
        if (bg > ed)
            return -1;
        int left = bg;
        for (int i = bg; i < ed; i++)
            if (nums[i] <= nums[ed])
                swap(nums, left++, i);
        swap(nums, left, ed);
        if (left == k)
            return nums[left];
        else if (left < k)
            return helperQuickSelect(nums, left + 1, ed, k);
        else
            return helperQuickSelect(nums, bg, left - 1, k);
    }
    private void swap(int[] nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    //Another version
    public int findKthLargest1(int[] nums, int k) {
        if (nums == null || nums.length < k || k < 1) {
            return -1;
        }
        return quickSelect(nums, 0, nums.length - 1, nums.length - k);
    }

    private int quickSelect(int[] nums, int start, int end, int k) {
        if (start == end) {
            return nums[start];
        }
        int p = nums[start + (end - start) / 2];
        int i = start;
        int j = end;
        while (i <= j) {
            while (i <= j && nums[i] < p) {
                i++;
            }
            while (i <= j && nums[j] > p) {
                j--;
            }
            if (i <= j) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i++;
                j--;
            }
        }
        if (k <= j) {
            return quickSelect(nums, start, j, k);
        } else if (k >= i) {
            return quickSelect(nums, i, end, k);
        }
        return nums[k];
    }

    public int findKthLargest2(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(k+1);
        for (int num : nums){
            pq.add(num);
            if (pq.size()>k)
                pq.poll();
        }
        return pq.poll();
    }


    /*
    75. Sort Colors

    Follow up:
    A rather straight forward solution is a two-pass algorithm using counting sort.
    First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
    Could you come up with an one-pass algorithm using only constant space?
    =>
    */
    public void sortColors(int[] nums) {
        int k0 = 0, k1 = 0, num;
        for (int k2 = 0; k2 < nums.length; k2++){
            num = nums[k2];
            nums[k2] = 2;
            if (num < 2){
                nums[k1] = 1;
                k1++;
            }
            if (num == 0){
                nums[k0] = 0;
                k0++;
            }
        }
        return;
    }

    /*
    Wiggle Sort
    nums[0] <= nums[1] >= nums[2] <= nums[3]....
    ->
    odd num:  nums[i] >= nums[i-1]
    even num: nums[i] <= nums[i-1]
    */
    public void wiggleSort(int[] nums) {
        for (int i = 1; i < nums.length; i++)
            if (i%2 == 0 && nums[i] > nums[i-1] || i%2 ==1 && nums[i] < nums[i-1])
                swap(nums, i, i-1);
        return;
    }
    /*
    324. Wiggle Sort II
    nums[0] < nums[1] > nums[2] < nums[3]....
    ->
    sort nums;
    for (int i=nums.size()-1, j=0, k=i/2+1; i>=0; i--)
	    nums[i] = sorted[i%2==1 ? k++ : j++];

    Follow Up:
    Can you do it in O(n) time and/or in-place with O(1) extra space?

    Find the median one, left < m < right
    choose from left, choose from right, choose l, chooser r ...
    */
    public void wiggleSort2(int[] nums) {
        int n = nums.length;
        int m = WSquickSelect(nums, 0, n - 1, n / 2);
        int i = (n - 1) / 2 * 2, j = i, k =1;
        for (int id = 0; id < n; id++){
            if (nums[j] < m){
                WSswap(nums,i,j);
                i -= 2;
                j -= 2;
                if (j < 0) j = n / 2 * 2 - 1;
            }
            else if (nums[j] > m){
                WSswap(nums,j,k);
                k += 2;
            }
            else{
                j -= 2;
                if (j < 0) j = n / 2 * 2 - 1;
            }
        }
    }
    private int WSquickSelect(int[] nums, int bg, int ed, int k) {
        if (bg == ed)
            return nums[bg];
        int m = nums[bg + (ed - bg) / 2];
        int i = bg, j = ed;
        while (i <= j){
            while (i <= j && nums[i] < m)
                i++;
            while (i <= j && nums[j] > m)
                j--;
            if (i <= j){
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i++;
                j--;
            }
        }
        if (k <= j)
            return WSquickSelect(nums, bg, j, k);
        else if (k >= i)
            return WSquickSelect(nums, i, ed, k);
        return nums[k];
    }
    private void WSswap(int[] nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    /*
    376. Wiggle Subsequence
    Follow up:
    Can you do it in O(n) time?
     */
    public int wiggleMaxLength(int[] nums) {
        int n;
        if (nums == null || (n = nums.length) == 0)
            return 0;
        int[] dp1 = new int[n];//positive
        int[] dp2 = new int[n];//negative
        dp1[0] = dp2[0] = 1;
        for (int i = 1; i < n; i++)
            if (nums[i-1] < nums[i]){
                dp1[i] = dp2[i-1] + 1;
                dp2[i] = dp2[i-1];
            }
            else if (nums[i-1] > nums[i]){
                dp2[i] = dp1[i-1] + 1;
                dp1[i] = dp1[i-1];
            }
            else{
                dp1[i] = dp1[i-1];
                dp2[i] = dp2[i-1];
            }
        return Math.max(dp1[n-1],dp2[n-1]);
    }
}
