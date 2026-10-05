class Solution {
    public int longestOnes(int[] nums, int k) {
        int left = 0;
        int right = 0;
        int len = Integer.MIN_VALUE;

        while(right < nums.length){

            if(nums[right] == 0) k--;

            while(k < 0){
                if(nums[left] == 0) k++;
                left++;
            }

            len = Math.max(len, right - left + 1);
            right++;
        }

        return len;
    }   
}