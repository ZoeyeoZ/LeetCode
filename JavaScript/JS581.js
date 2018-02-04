/**
 * @param {number[]} nums
 * @return {number}
 */
var findUnsortedSubarray = function(nums) {
	var left = 0, l = nums.length, right = l - 1;
	var minN, maxN;
	var ans = 0;
	while (left <= right && nums[left] <= nums[left+1])
		left ++;
	while (left <= right && nums[right-1] <= nums[right])
		right --;
	if (left < right){
		for (var i = left; i <= right; i ++){
			if (minN == undefined || nums[i] < minN)
				minN = nums[i];
			if (maxN == undefined || nums[i] > maxN)
				maxN = nums[i];
		}
		while (left > 0 && nums[left-1] > minN)
			left --;
		while (right < l-1 && nums[right+1] < maxN)
			right ++;
		ans = right - left + 1;
	}
    return ans;
};
console.log(findUnsortedSubarray(Array(1,2,3,4)));
//1,3,2,2,2 -> 4
//2,3,3,2,4 -> 3
// -> 2
