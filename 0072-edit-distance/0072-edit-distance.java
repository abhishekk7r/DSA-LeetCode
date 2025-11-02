class Solution {
    private int f(int i, int j, String word1, String word2, int[][] memo) {

        //If string 1 runs out
        if (i < 0)
            return j + 1;

        //If string 2 runs out
        if (j < 0)
            return i + 1;

        if (memo[i][j] != -1)
            return memo[i][j];

        //If Both S1[i] & S2[j] matches
        //We can move the i & j together
        if (word1.charAt(i) == word2.charAt(j)) {
            return f(i - 1, j - 1, word1, word2, memo);
        }

        //Insert -> Move J, as we have matched with inserted character
        //Delete -> Move I, as we have deleted one charð
        return 1 + Math.min(f(i - 1, j, word1, word2, memo),
                Math.min(f(i, j - 1, word1, word2, memo), f(i - 1, j - 1, word1, word2, memo)));
    }

    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();

        /*int[][] memo = new int[n + 1][m + 1];

        // for(int i=0; i<n; i++) Arrays.fill(memo[i], -1);
        //return f(n-1, m-1, word1, word2, memo);   

        for (int i = 0; i <= n; i++)
            memo[i][0] = i;
        
        
        memo[0][0] = 0;
        */
        
        int [] curr = new int[m + 1];
        int [] prev = new int[m + 1];

        for (int j = 0; j <= m; j++) prev[j] = j;

        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                char a = word1.charAt(i - 1);
                char b = word2.charAt(j - 1);

                if (a == b) {
                    curr[j] = prev[j-1];
                } else {
                    //memo[i][j] = 1 + Math.min(memo[i - 1][j], Math.min(memo[i][j - 1], memo[i - 1][j - 1]));
                    curr[j] = 1 + Math.min(prev[j], Math.min(curr[j-1], prev[j-1]));
                }

                
            }
            prev = Arrays.copyOf(curr, curr.length);
        }

        return prev[m];
    }
}