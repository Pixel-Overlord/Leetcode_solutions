/* 74. Search a 2D Matrix
 * 
 * You are given an m x n integer matrix matrix with the following two properties:
 * 
 * Each row is sorted in non-decreasing order.
 * The first integer of each row is greater than the last integer of the previous row.
 * Given an integer target, return true if target is in matrix or false otherwise.
 * 
 * You must write a solution in O(log(m * n)) time complexity.
 * 
 * Example 1:
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * 
 * Output: true
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 class Solution {
    public:
        // O(m log n) time complexity.
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int rows = matrix.size();
            int column = matrix[0].size();

            for (int i=0; i<rows; i++){
                int left = 0;
                int right = column - 1;
                while (left<=right){
                    int mid = left + (right - left) / 2;
    
                    if (matrix[i][mid] == target)
                        return true;
                    else if (matrix[i][mid] < target)
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
            }
            return false;
        }
 };

 int main(){
    vector<vector<int>> matrix = {{1,3}};
    int target;

    cout << "Enter target to search : " ;
    cin >> target;
    Solution sol;
    bool result = sol.searchMatrix(matrix, target);
    cout << "The target is in matrix : " << result;
 }