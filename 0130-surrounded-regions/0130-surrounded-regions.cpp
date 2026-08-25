class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    void dfs(int r, int c, vector<vector<char>>& board, int n, int m){
        board[r][c] = 'Y'; //marking visited

        for(int i=0; i<4; i++){
            int x = r + dir[i];
            int y = c + dir[i+1];

            if(x >=0 && y >=0 && x < n && y < m && board[x][y] == 'O'){
                dfs(x, y, board, n, m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++) if(board[i][0] == 'O') dfs(i, 0, board, n, m);
        for(int i=0; i<m; i++) if(board[0][i] == 'O') dfs(0, i, board, n, m);

        for(int i=0; i<m; i++) if(board[n-1][i] == 'O') dfs(n-1, i, board, n, m);
        for(int i=0; i<n; i++) if(board[i][m-1] == 'O') dfs(i, m-1, board, n, m);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'Y') board[i][j] = 'O';
            }
        }

    }
};