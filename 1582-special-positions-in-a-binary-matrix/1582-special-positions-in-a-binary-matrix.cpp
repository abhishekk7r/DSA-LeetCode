class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int count = 0;
        
        int rSum[row];
        int cSum[col];
        
        //Row Sum
        for(int i=0; i<row; i++){
            rSum[i]=0;
            for(int j=0; j<col; j++){
                 rSum[i]+= mat[i][j];
                 
            }
        }
        
        //Col Sum
        for(int i=0; i<col; i++){
            cSum[i]=0;
            for(int j=0; j<row; j++){
                  cSum[i]+= mat[j][i];
            }
        }
        
        //
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                 if(mat[i][j]==1 && rSum[i]==1 && cSum[j]==1){
                     count++;
                 } 
            }
        }
        return count;
        
    }
};