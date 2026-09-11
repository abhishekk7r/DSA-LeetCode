class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int> &memo){
        if(n < 0) return 0;

        if(memo[n] != -1) return memo[n];
        
        int first = solve(nums, n-1, memo);
        int second = solve(nums, n-2, memo) + nums[n];
        memo[n] = max(first, second);
        return memo[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return solve(nums, n-1, memo);
    }
};