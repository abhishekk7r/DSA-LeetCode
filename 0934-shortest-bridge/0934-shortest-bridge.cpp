class Solution {
public:
    int dir[5] = {0, 1, 0, -1, 0};
    void dfs(int i, int j, int r, int c, vector<vector<int>>& grid, queue<pair<int, int>> &q){
        grid[i][j] = 2;

        for(int k=0; k<4; k++){
            int newX = i + dir[k];
            int newY = j + dir[k + 1];

            //Post Idenitfiying the first Island, We need to figure out which cells are connected to 0.
            if(newX >= 0 && newY >= 0 && newX < r && newY < c && grid[newX][newY] == 0) {
                q.push({i, j});
            }

            if(newX >= 0 && newY >= 0 && newX < r && newY < c && grid[newX][newY] == 1){
                dfs(newX, newY, r, c, grid, q);
            }
        }

    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        bool found = false;
        //Identify & Mark the First Island.
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, n, m, grid, q); //Mark 1's to 2.
                    found = true;
                    break;
                }  
            }
            if(found) break;
        }

        int distance = 0;
        //Q will contain all the cell that are connected to 0 in the first island. 
        while(!q.empty()){
            int size = q.size();

            for(int k = 0; k<size; k++){
                auto [x, y] = q.front();
                q.pop();

                for(int i = 0; i<4; i++){
                    int newX = dir[i] + x;
                    int newY = dir[i + 1] + y;

                     if(newX >= 0 && newY >= 0 && newX < n && newY < m && grid[newX][newY] == 1){
                        return distance;
                     }
                    if(newX >= 0 && newY >= 0 && newX < n && newY < m && grid[newX][newY] == 0){
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                    }
                }
            }
            
            distance++;
        }

        return distance;
    }
};