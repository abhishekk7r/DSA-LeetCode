class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;

        int maxLen = 0;
        int n = nums.size();
        int allowedFlip = 0;

       while(right < n){
         if(nums[right] == 0){
            allowedFlip++;
         }

         if(allowedFlip <= k){
            maxLen = max(maxLen, right - left + 1);
         } 

         while(allowedFlip > k){
            if(nums[left] == 0) allowedFlip--;
            left++; 
         }
         right++;
       }

       return maxLen;
    }
};