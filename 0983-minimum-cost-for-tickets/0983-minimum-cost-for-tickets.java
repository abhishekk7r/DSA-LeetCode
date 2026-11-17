class Solution {
    public int mincostTickets(int[] days, int[] cost) {
        var st = new HashSet<Integer>();

        for(var i : days) st.add(i);

        int [] dp = new int[366];
        for(int i = 1; i<366; i++){
            if(!st.contains(i)){
                dp[i] = dp[i-1];
            } else {
                dp[i] = Math.min(dp[Math.max(0, i-1)] + cost[0],
                    Math.min(dp[Math.max(0, i-7)] + cost[1], dp[Math.max(0, i-30)] + cost[2])
                );
            }
        }

        return dp[365];
    }
}