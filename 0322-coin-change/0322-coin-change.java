class Solution {
    public int solve(int[] coins, int amount, int n, int [][] dp){
        if(n == 0 || amount == 0) {
            return (amount == 0) ? 0 : Integer.MAX_VALUE;
        }

        if(dp[n][amount] != -1) return dp[n][amount];

        int res = -1;
        if(coins[n-1] <= amount){
            int takeTheCoin = solve(coins, amount - coins[n-1], n, dp);

            if(takeTheCoin != Integer.MAX_VALUE){
                takeTheCoin += 1;
            }
            int doNotTakeTheCoin = 0 + solve(coins, amount, n - 1, dp);

            res = Math.min(takeTheCoin,doNotTakeTheCoin);
        } else {
            res = solve(coins, amount, n - 1, dp);
        }

        dp[n][amount] = res;
        return dp[n][amount];
    }
    public int coinChange(int[] coins, int amount) {
        int [][] dp = new int[coins.length + 7][amount + 7];
        for(int [] row : dp) Arrays.fill(row, -1);
        int res = solve(coins, amount, coins.length, dp);
        return res == Integer.MAX_VALUE ? -1 : res;
    }
}