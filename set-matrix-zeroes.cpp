/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRow = false, firstCol = false;
        
        // Check if the first row contains zero
        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) {
                firstRow = true;
                break;
            }
        }
        
        // Check if the first column contains zero
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }
        
        // Use first row and column as markers
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Set zeros based on markers
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Set first row to zero if needed
        if(firstRow) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // Set first column to zero if needed
        if(firstCol) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};