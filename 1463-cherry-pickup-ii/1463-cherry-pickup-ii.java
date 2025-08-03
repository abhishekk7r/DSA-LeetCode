class Solution {
    public int solve(int i, int j1, int j2, int r, int c, int[][] grid, int [][][] DP){
        //base case : out of bound
        if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c){
            return Integer.MIN_VALUE;
        }

        if(DP[i][j1][j2] != -1) return DP[i][j1][j2];

        if(i == r - 1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        int maxi = Integer.MIN_VALUE; 
        for(int dj1=-1; dj1<= 1; dj1++){
            for(int dj2 = -1 ; dj2 <= 1; dj2++){
                int value = 0;
                if(j1 == j2) value = grid[i][j2];
                else value = grid[i][j1] + grid[i][j2];

                value += solve(i+1, j1+dj1, j2+dj2, r, c, grid, DP);
                maxi = Math.max(maxi, value);
            }
        }

        return maxi;
    }
    public int cherryPickup(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int [][][] DP = new int[r][c][c];

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                Arrays.fill(DP[i][j], 0);
            }
        }

        //return solve(0, 0, c-1, r, c, grid, DP);
        for(int j1 = 0; j1<c; j1++){
            for(int j2 = 0; j2<c; j2++){
                if(j1 == j2) DP[r-1][j1][j2] = grid[r-1][j1];
                else DP[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }

        for(int i=r-2; i>=0; i--){
            for(int j1=0; j1<c; j1++){
                for(int j2=0; j2<c; j2++){
                    int maxi = Integer.MIN_VALUE; 
                    for(int dj1=-1; dj1<= 1; dj1++){
                        for(int dj2 = -1 ; dj2 <= 1; dj2++){
                            int value = 0;
                            if(j1 == j2) value = grid[i][j2];
                            else value = grid[i][j1] + grid[i][j2];
                            if(j1+dj1 >= 0 && j2+dj2 >= 0 && j1+dj1 < c && j2+dj2 < c){
                                value += DP[i+1][j1+dj1][j2+dj2];
                            } else {
                                value = Integer.MIN_VALUE;
                            }
                            
                            maxi = Math.max(maxi, value);
                            DP[i][j1][j2] = maxi;
                        }
                    }
                }
            }
        }

        return DP[0][0][c-1];

    }
}