class Solution {
    private int solve(int index1, int index2, String text1, String text2, int [][] memo){

        if(index1 < 0 || index2 < 0) return 0;

        char a = text1.charAt(index1);
        char b = text2.charAt(index2);

        if(memo[index1][index2] != -1) return memo[index1][index2];
        if(a == b) return 1 + solve(index1 - 1, index2 - 1, text1, text2, memo);

        //Take index1 or index2
        int takeIndex1 = solve(index1 - 1, index2, text1, text2, memo);
        int takeIndex2 = solve(index1, index2 - 1, text1, text2, memo);

        memo[index1][index2] = Math.max(takeIndex1, takeIndex2);
        return memo[index1][index2];
    }
    public int longestCommonSubsequence(String text1, String text2) {
        
        int [][] memo = new int[1001][1001];

        for(int i=0; i<1001; i++){
            Arrays.fill(memo[i], -1);
        }

        return solve(text1.length() - 1, text2.length() - 1, text1, text2, memo);
    }
}