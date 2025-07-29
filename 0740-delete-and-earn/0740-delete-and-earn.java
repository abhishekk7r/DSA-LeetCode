class Solution {
    public int solve(int n, int[] arr, int[] dp){

        if(n == 0) return arr[0];
        if(n == 1) return Math.max(arr[0], arr[1]);

        if(dp[n] != -1) return dp[n];
        
        int first = Integer.MIN_VALUE;

        if(n > 1) first = solve(n - 2, arr, dp) + arr[n];
        int second = solve(n - 1, arr, dp);

        dp[n] = Math.max(first, second);
        return dp[n];

    }
    public int deleteAndEarn(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        int max = Arrays.stream(nums).max().orElse(Integer.MIN_VALUE);

        for(int i : nums){
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }

        int[] arr = new int[max + 1];
        int[] dp = new int[max + 1];
        Arrays.fill(dp, -1);

        for(Integer i : mp.keySet()){
            int ele = mp.get(i) * i;
            arr[i] = ele;
        }

        return solve(max, arr, dp);
    }
}