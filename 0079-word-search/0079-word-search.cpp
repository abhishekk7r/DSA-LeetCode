class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    bool dfs(int i, int j, int r, int c, int index, vector<vector<char>>& board, string word){
        if(index == word.size() - 1) return true;
        char temp = board[i][j];
        board[i][j] = '#';

        for(int k=0; k<4; k++){
            int newX = i + dir[k];
            int newY = j + dir[k + 1];

            if(newX >= 0 && newY >=0 && newX < r && newY < c && board[newX][newY] == word[index+1]){
                if(dfs(newX, newY, r, c, index+1, board, word)) return true;
            }
        }
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        //Pick words[0] and find in boards, if it start with word[0]
        //start algo from there
        int r = board.size();
        int c = board[0].size();
        bool ans = false;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i, j, r, c, 0, board, word) == true) return true;
                }
            }
        }

        return false;
    }
};