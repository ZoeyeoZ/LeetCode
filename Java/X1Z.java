package com.company;

import javax.swing.tree.TreeNode;
import java.util.*;
import java.util.stream.Collectors;

public class X1Z{
    /*
    658. Find K cloest Elements
    Sorted array, find the k closest elements to x in the array.
    */
    public static List<Integer> findClosestElements(int[] arr, int k, int x) {
        int n;
        //corner case
        if (arr == null || (n = arr.length) == 0){
            return null;
        }
        //special case
        if (x <= arr[0]){
            return Arrays.stream(Arrays.copyOfRange(arr, 0, k)).boxed().collect(Collectors.toList());
        }
        if (x >= arr[n-1]){
            return Arrays.stream(Arrays.copyOfRange(arr, n - k, n)).boxed().collect(Collectors.toList());
        }

        //binary search
        int index = Arrays.binarySearch(arr, x);
        if (index < 0){
            index = -(index+1); // number next to x
        }
        int low = Math.max(0, index - k - 1), high = Math.min(n - 1, index + k + 1);
        while (high - low > k-1){
            if (low < 0 || (x - arr[low]) <= (arr[high] - x)) {
                high--;
            } else if (high > n - 1 || (x - arr[low]) > (arr[high] - x)) {
                low++;
            } else {
                System.out.println("unhandled case: " + low + " " + high);
            }
        }
    	/*
    	List<Integer> l = new ArrayList<>();
    	int[] newArr = Arrays.copyOfRange(arr, low, high + 1);
    	for (int i = 0; i < newArr.length; i++)
    		l.add(newArr[i]);
    	*/
        return Arrays.stream(Arrays.copyOfRange(arr, low, high + 1)).boxed().collect(Collectors.toList());
    }

    /*
    加锁
    270. Closest Binary Search Tree Value
    Min(left's most right, right's most left)
    time:
    N : number of nodes in the tree
    average O(logN), worst O(N), best O(1)
    */
    public int cloestValue(TreeNode root, double target){
        int ret = root.val;
        while (root != null){
            double diff = Math.abs(target - root.val);
            if (diff < 1e-10) {
                return root.val;
            }
            if (diff < Math.abs(target - ret)){
                ret = root.val;
            }
            root = root.val > target ? root.left : root.right;
        }
        return ret;
    }

    /*
    加锁
    272. Closest Binary Search Tree Value II
    find k values in BST, closest to target
    1. Inorder Traversal
    2. keep a slide windows, until no need(dif2>dif1) to move head out

    time:
    worst O(N), best O(K), average

    test case: corner case + average case
    target on the left
    k < N

    Iterative
     */
    public List<Integer> closestKValues(TreeNode root, double target, int k){
        LinkedList<Integer> res = new LinkedList<>();
        collect(root, target, k, res);
        return res;
    }
    private void collect(TreeNode root, double target, int k, LinkedList<Integer> res){
        if (root = null){
            return;
        }
        collect(root.left, target, k, res);
        if (res.size()==k){
            if (Math.abs(target - root.val) >= Math.abs(target - res.peekFirst())){
                return;
            }
            res.removeFirst();
        }
        res.add(root.val);
        collect(root.right, target, k, res);
    }

    public List<Integer> closestKValues2(TreeNode root, double target, int k) {
        LinkedList<Integer> res = new LinkedList<>();
        if (root == null) {
            return res;
        }
        Stack<TreeNode> s = new Stack<>();
        TreeNode current = root;
        while (true){
            if (current != null){
                s.push(current);
                current = current.left;
                continue;
            }
            if (s.empty()){
                break;
            }
            current = s.pop();
            if (res.size() == k){
                if (Math.abs(target - current.val) >= Math.abs(target - res.peekFirst())){
                    return res;
                }
                res.removeFirst();
            }
            res.add(current.val);
            current = current.right;
        }
        return res;
    }


}
/*
19ms
public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> res = new ArrayList<Integer>();
        if(arr == null || arr.length == 0 || k == 0){
            return res;
        }

        int l = 0;
        int r = arr.length-k;
        while(l<r){
            int mid = l+(r-l)/2;
            if(x - arr[mid] > arr[mid+k]-x){
                l = mid+1;
            }else{
                r = mid;
            }
        }

        for(int i = l; i<l+k; i++){
            res.add(arr[i]);
        }
        return res;
    }
*/