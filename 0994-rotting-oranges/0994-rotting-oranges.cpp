class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int freshOrange = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) freshOrange++;
            }
        }


        if(freshOrange == 0) return 0;
        
        int minutes = 0;
        while(!q.empty()){
            int size = q.size();
            for(int k = 0; k<size; k++){
                auto [x, y] = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                int newX = x + dir[i];
                int newY = y + dir[i+1];
                    if(newX >= 0 && newY >= 0 && newX < n && newY < m && grid[newX][newY] == 1 ){
                        freshOrange--;
                        grid[newX][newY] = 2;  
                        q.push({newX, newY});
                    }
                }
            }

            if(!q.empty()) minutes++;
        }
        
        return 0 == freshOrange ? minutes : -1;
    }
};