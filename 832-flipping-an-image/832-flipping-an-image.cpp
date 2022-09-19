class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        for(int i=0; i<row; i++)
            
        {
            reverse(mat[i].begin(),mat[i].end());
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j]==1){
                    mat[i][j] = 0;
                } else {
                    mat[i][j] = 1;
                }
            }
        }
        
        return mat;
    }
};