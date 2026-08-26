class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int zeros = 0;
        int ans = 0;
        while(right < n){
            ans = max(ans, right - left);

            if(nums[right] == 0) zeros++;

            while(zeros > k){
                if(nums[left] == 0) zeros--;
                left++;
            }

            right++;
        }

        ans = max(ans, right - left);

        return ans;
    }
};