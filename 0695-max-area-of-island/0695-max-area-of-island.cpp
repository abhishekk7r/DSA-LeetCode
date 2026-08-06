class Solution {
    int dir[5] = {0, 1, 0, -1, 0};
public:
    int dfs(int i, int j, int row, int col, vector<vector<int>>& grid){
        int count = 1;
        grid[i][j] = 0;
        for(int k=0; k<4; k++){
            int newX = i + dir[k];
            int newY = j + dir[k+1];

            if(newX >= 0 && newY >= 0 && newX < row && newY < col && grid[newX][newY] == 1){
                count += dfs(newX, newY, row, col, grid);
            }
        }

        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();

        //DFS will return the area connected from the i & j
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    count = max(count, dfs(i, j, row, col, grid));
                }
            }
        }
        
        return count;
    }
};