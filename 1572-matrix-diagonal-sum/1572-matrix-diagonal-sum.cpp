class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int x =0; int y=0; int row=mat.size();
        
        for(int i=0; i<row; i++){
            x += mat[i][i]; //First diagonal sum
            y += mat[i][row-1-i]; //seconday diagonal sum
        }
        
        if(row%2==0)
            return x+y;
        else
            return x+y-mat[row/2][row/2];
    }
};