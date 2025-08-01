class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int [][] DP = new int[m + 7][n + 7];
        
        DP[0][0] = grid[0][0];
        for(int i=1; i<m; i++){
            DP[i][0] = grid[i][0] + DP[i-1][0];
        }

        for(int j=1; j<n; j++){
            DP[0][j] = grid[0][j] + DP[0][j-1];
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                DP[i][j] = Math.min(DP[i-1][j], DP[i][j-1]) + grid[i][j];
            }
        }

        return DP[m-1][n-1];
    }
}