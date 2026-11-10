class Solution {
    public int climbStairs(int n, int[] costs) {
        int dp[] = new int[n + 7];
        dp[0] = 0;

        for(int j = 1; j <= n; j++){
            dp[j] = Integer.MAX_VALUE;
            for(int i=1; i<=3; i++){
                if(j - i >= 0){
                    dp[j] = Math.min(dp[j], costs[j - 1] + i*i + dp[j - i]);
                } 
            }
        }

        return dp[n];
    }
}