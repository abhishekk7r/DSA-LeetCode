class Solution {
public:
    int dir[5] = {0, 1, 0, -1, 0};
    int dfs(int i, int j, int r, int c, vector<vector<int>> &dp, vector<vector<int>>& matrix){
        if(dp[i][j] != 0) return dp[i][j];
        dp[i][j] = 1;

        for(int k = 0; k<4; k++){
            int newX = dir[k] + i;
            int newY = dir[k + 1] + j;

            if(newX >= 0 && newY >=0 && newX < r && newY < c && matrix[newX][newY] > matrix[i][j]){
               dp[i][j] = max(dp[i][j], dfs(newX, newY, r, c, dp, matrix) + 1);
            }
        }

        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int> (m, 0));

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans = max(ans, dfs(i, j, n, m, dp, matrix));
            }
        }

       
        return ans;
    }
};