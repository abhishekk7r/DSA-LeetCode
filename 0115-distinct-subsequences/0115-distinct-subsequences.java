class Solution {
    private int f(int i, int j, String s, String t, int [][] memo){

        if(j < 0) return 1; 
        if(i < 0) return 0; 

        if(memo[i][j] != -1) return memo[i][j];
        //Case Where Strings Match
        if(s.charAt(i) == t.charAt(j)){
            //Either move both pointers to the left
            //Ignore one Element & Move the pointer
            memo[i][j] = f(i-1, j-1, s, t, memo) + f(i-1, j, s, t, memo);
            return memo[i][j];
        }

        return memo[i][j] = f(i-1, j, s, t, memo);
    }

    public int numDistinct(String s, String t) {
        int n = s.length();
        int m = t.length();

        int [][] memo = new int[n + 1][m + 1];

        for(int i = 0; i<n; i++) Arrays.fill(memo[i], -1);

        return f(n-1, m-1, s, t, memo);
    }
}