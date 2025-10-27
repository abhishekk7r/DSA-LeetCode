class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        //First Create LCS
        //Then Append all the elements from both the string that are left;

        //DP table
        int n = str1.length();
        int m = str2.length();

        int [][] dp = new int[n + 1][m + 1];


        //Create the DP table
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                char a = str1.charAt(i - 1);
                char b = str2.charAt(j - 1);

                //If Characters match, we add them into our subsequnce
                if(a == b){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    //else we take whatever was maximum common before this
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        StringBuilder sb = new StringBuilder();

        while(n > 0 && m > 0){
            char a = str1.charAt(n - 1);
            char b = str2.charAt(m - 1);

            if(a == b){
                sb.append(a);
                n--;
                m--;
            } else if(dp[n-1][m] > dp[n][m-1]){
                sb.append(a);
                n--;
            } else {
                sb.append(b);
                m--;
            }
        }

        while(n > 0){
            sb.append(str1.charAt(n - 1));
            n--;
        }

        while(m > 0){
            sb.append(str2.charAt(m - 1));
            m--;
        }


        return sb.reverse().toString();

    }
}