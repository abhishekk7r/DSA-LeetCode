class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        int [][] DP = new int[rows][cols];

        for(int i=0; i<rows; i++) Arrays.fill(DP[i], 1001);

        for(int i=0; i<cols; i++){
            DP[0][i] = matrix[0][i];
        }

        for(int i=1; i<rows; i++){
            for(int j=0; j<cols; j++){
                
                int topleft = Integer.MAX_VALUE;
                int top = topleft;
                int topright = top;
                
                if(j>0){
                    topleft = DP[i-1][j-1] + matrix[i][j]; 
                }

                if(j<cols-1){
                    topright = DP[i-1][j+1] + matrix[i][j];
                }

                top = DP[i-1][j] + matrix[i][j];
                
                DP[i][j] = Math.min(top, Math.min(topright, topleft));
            }
        }

        int ans = Integer.MAX_VALUE;

        for(int i=0; i<cols; i++){
            ans = Math.min(ans, DP[rows-1][i]);
        }

        return ans;
    }
}