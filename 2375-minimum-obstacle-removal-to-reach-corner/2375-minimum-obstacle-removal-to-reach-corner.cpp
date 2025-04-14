class Solution {
    //cost, coordinates
    #define pip pair<int, pair<int, int>>  
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dir = {-1, 0, 1, 0, -1};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<pip, vector<pip>, greater<pip>> minHeap;
        minHeap.push({0, {0, 0}});
        visited[0][0] = true;

        while(!minHeap.empty()){
            pip current = minHeap.top();
            minHeap.pop();

            int x = current.second.first;
            int y = current.second.second;
            int cost = current.first;

            if(x == n-1  && y == m-1) return cost;

            for(int i=0; i<4; i++){
                int newX = x + dir[i];
                int newY = y + dir[i+1];

                if(newX >= 0 && newY >=0 && newX < n && newY < m  && !visited[newX][newY]){
                    visited[newX][newY] = true;
                    if(grid[newX][newY] == 1) // obstacle
                        minHeap.push({cost+1, {newX, newY}});
                    else 
                        minHeap.push({cost, {newX, newY}});  
                }
            }
        }

        return 0;
    }
};