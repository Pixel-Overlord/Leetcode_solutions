/* 
 * 73. Set Matrix Zeroes
 * 
 * Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
 * 
 * You must do it in place.
 * 
 *  
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * Output: [[1,0,1],[0,0,0],[1,0,1]]
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 */

 #include <iostream>
 #include <vector>
 #include <set>
 using namespace std;
 
 class Solution {
 public:
     void setZeroes(vector<vector<int>>& matrix) {

        set<int> row;
        set<int> col;
        pair<int,int> location;

        for (int i=0; i<matrix.size(); i++) {

            for (int j=0; j<matrix[0].size(); j++) {

                if (matrix[i][j] == 0) {
                    row.insert(i); col.insert(j);
                }
            }
        }

        // we have sets that contains location of all 0s in matrix.
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (row.count(i) || col.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
     }
 };

 int main(){
    Solution sol;

    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};

    sol.setZeroes(matrix);

    for (auto a : matrix) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
 }