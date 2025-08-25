class Solution {
    public int solve(int i, int amount, int[] coins, int [][] memo){
        if(i == 0){
            return amount%coins[0] == 0 ? 1 : 0;
        }
        if(memo[i][amount] != -1) return memo[i][amount];
        int notTake = solve(i-1, amount, coins, memo);
        int take = 0;
        if(coins[i] <= amount){
            take = solve(i, amount - coins[i], coins, memo);
        }

        memo[i][amount] = take + notTake;
        return memo[i][amount];
    }
    public int change(int amount, int[] coins) {
        int [][] memo = new int[5001][5001];

        for(var i : memo) Arrays.fill(i, -1);

        return solve(coins.length - 1, amount, coins, memo);
    }
}