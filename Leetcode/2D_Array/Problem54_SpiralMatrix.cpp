/* 
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 class Solution {
 public:
     vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix[0].size(), n = matrix.size();
        int srow = 0, scol = 0, erow = n-1, ecol = m-1; //since mxn matrix
        vector<int> ans;

        while (srow <= erow && scol <= ecol) {

            // top
            for (int i = scol; i <= ecol; i++) {
                ans.push_back(matrix[srow][i]);
            }

            // right
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }

            // bottom
            if (srow < erow) {
                for (int i = ecol - 1; i >= scol; i--) {
                    ans.push_back(matrix[erow][i]);
                }
            }

            // left
            if (scol < ecol) {
                for (int i = erow - 1; i > srow; i--) {
                    ans.push_back(matrix[i][scol]);
                }
            }

            srow++;
            erow--;
            scol++;
            ecol--;
        }
        
        return ans;
     }
 };

 int main(){
    Solution sol;

    vector<vector<int>> matrix = {{1,2,3,4}, {12,13,14,5}, {11,16,15,6},{10,9,8,7}};
    vector<int> ans;
    ans = sol.spiralOrder(matrix);

    for (auto a: ans) {
        cout << a << " ";
    }
 }