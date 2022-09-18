class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> ans(r,vector<int>(c));
        vector<int> temp;
        
        /*Phele ek vector me sara element pushback kar lo fir dusra loop 
        chala k temporary vector ka sara element new matrix me of given 
        size mee daaldo*/
        
        if(row*col==r*c){
        
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    temp.push_back(mat[i][j]);
                }
            }
            int k=0;
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    ans[i][j]=temp[k];
                    k++;
                }
            }
            return ans;
        }
        return mat;
    }
};