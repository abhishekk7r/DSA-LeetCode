class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isFirstRowZero = false;
        bool isFirstColZero = false;
        int n = matrix.size();
        int m = matrix[0].size();

        //First Row Check
        for(int i=0; i<m; i++){
            if(matrix[0][i] == 0) isFirstRowZero = true;  
        }

        //First Col Check
        for(int i=0; i<n; i++){
            if(matrix[i][0] == 0) isFirstColZero = true;  
        }

        //remaing element check
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0; //Cols
                    matrix[i][0] = 0; //Rows
                }
            }
        }

        for(int i=1; i<n; i++){
    for(int j=1; j<m; j++){
        if(matrix[i][0] == 0 || matrix[0][j] == 0){
            matrix[i][j] = 0;
        }
    }
}
        
        if(isFirstRowZero){
            for(int i=0; i<m; i++){
                matrix[0][i] = 0;
            }
        }

        if(isFirstColZero){
            for(int i=0; i<n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};