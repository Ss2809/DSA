class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int rows = matrix.size();
       int col = matrix[0].size()-1; 
       int r = 0;
       while( r < rows && col >= 0){
        if(target > matrix[r][col]){
            r++;
        }else if( target < matrix[r][col]){
            col--;
        }else{
            return true;
        }
       }
       return false;
    }
};