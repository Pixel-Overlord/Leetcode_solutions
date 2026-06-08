/* 
 * 240. Search a 2D Matrix II
 * Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
 * This matrix has the following properties:
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * Example 1:
 * 
 * Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
 * Output: true
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 class Solution{
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int totalRow = matrix.size();
        int totalColumn = matrix[0].size();

        int r=0,c = totalColumn - 1;

        // we will use stair-case method searching.
        while (r < totalRow &&  c >= 0){
            if (matrix[r][c] == target){
                return true;
            }
            else if(target < matrix[r][c]){
                c--;
            }
            else{
                r++;
            }
        }
        return false;
    }
 };

 int main(){
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    
    Solution sol;
    bool ans = sol.searchMatrix(matrix,target);
    cout << "Element is present : " << ans;
    return 0;
 }