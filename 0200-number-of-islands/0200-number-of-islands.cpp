class Solution {
public:
    vector<int> dir{0, 1, 0, -1, 0};

    void dfs(int i, int j, vector<vector<char>>& grid, int row, int col){
        //we make 0 if we find any 1 in any direction
        for(int k=0; k<4; k++){
            int newX = i + dir[k];
            int newY = j + dir[k+1];

            if(newX >= 0 && newY >= 0 && newX < row && newY < col && grid[newX][newY] == '1'){
                grid[newX][newY] = '0';
                dfs(newX, newY, grid, row, col);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();

        //We will start from an index and then do search in each direction from that

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    count++;
                    dfs(i, j, grid, row, col);
                }
            }
        }


        return count;
    }
};