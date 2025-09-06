class Solution {
    private int countWays(String s, int i, int dp[]) {
        if (i == s.length()) return 1; // reached end successfully
        if (s.charAt(i) == '0') return 0; // leading zero → invalid

        if (dp[i] != -1) return dp[i];

        // Take one digit
        int ans = countWays(s, i + 1, dp);

        // Take two digits if valid
        if (i + 1 < s.length()) {
            if (s.charAt(i) == '1' || 
               (s.charAt(i) == '2' && s.charAt(i + 1) <= '6')) {
                ans += countWays(s, i + 2, dp);
            }
        }

        return dp[i] = ans;
    }

    public int numDecodings(String s) {
        int[] dp = new int[s.length()];
        Arrays.fill(dp, -1);
        return countWays(s, 0, dp);
    }
}