class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        return max(solve(nums, 0, n-2), solve(nums, 1, n-1));
    }


    int solve(vector<int>& nums, int s, int e){

       int prev = 0;
       int prev2 = 0;

       for(int i=s; i<=e; i++){
        int curr = max(nums[i]+prev2, prev);
        prev2 = prev;
        prev = curr;
       }


        return prev;
    }
};