class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int endingRow = row-1;
        
        for(int j=0; j<col; j++)
        {
            for(int i=endingRow; i>=0; i-- ){
                ans.push_back(matrix[i][j]);
            }
        }
        int k=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                matrix[i][j] = ans[k];
                k++;
            }
        }
    }
};