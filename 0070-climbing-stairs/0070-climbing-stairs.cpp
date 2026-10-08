class Solution {
public:
    int solve(int n, vector<int> &memo){
        if(n <= 1) return 1;

        if(memo[n] != 0) return memo[n];
        memo[n] = solve(n-1, memo) + solve(n-2, memo);
        return memo[n];
    }

    int climbStairs(int n) {
        vector<int> memo(n+1, 0);
        
        return solve(n, memo);
    }
};