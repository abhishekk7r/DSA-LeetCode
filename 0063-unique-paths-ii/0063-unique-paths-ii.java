class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int [][] dp = new int[m + 7][n + 7];
        
        if(obstacleGrid[0][0] == 1) return 0;
        dp[0][0] = 1;
        boolean encountered = false;
        for(int i=1; i<n; i++){
            if(obstacleGrid[0][i] == 1) encountered = true;

            if(!encountered){
                dp[0][i] = 1;
            } else {
                dp[0][i] = 0;
            }
        }

        encountered = false;
        for(int j=1; j<m; j++){
            if(obstacleGrid[j][0] == 1) encountered = true;

            if(!encountered){
                dp[j][0] = 1;
            } else {
                dp[j][0] = 0;
            }
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
}