class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    void dfs(int r, int c, vector<vector<int>> &visited, vector<vector<int>>& heights, int n, int m){
        visited[r][c] = 1;

        for(int i=0; i<4; i++){
            int x = r + dir[i];
            int y = c + dir[i+1];

            if(x >= 0 && y >= 0 && x < n && y < m && visited[x][y] != 1 &&  heights[x][y] >= heights[r][c]){
                dfs(x, y, visited, heights, n, m);
            }
        }
    } 

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //Need two visited array for pacific & atlantic
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        vector<vector<int>> pacific(n, vector<int>(m, 0));

        // Seed Pacific: row 0 and column 0
        for (int j = 0; j < m; j++) dfs(0, j, pacific, heights, n, m);
        for (int i = 0; i < n; i++) dfs(i, 0, pacific, heights, n, m);

        for (int j = 0; j < m; j++) dfs(n-1, j, atlantic, heights, n, m);
        for (int i = 0; i < n; i++) dfs(i, m-1, atlantic, heights, n, m);

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacific[i][j] == 1 && atlantic[i][j] == 1){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};