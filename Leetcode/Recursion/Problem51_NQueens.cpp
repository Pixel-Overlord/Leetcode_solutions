/* 
 * 51. N-Queens
 * 
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle. 
 * You may return the answer in any order.
 * 
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' 
 * both indicate a queen and an empty space, respectively.
 * 
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
 * 
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 class Solution {
 public:
    bool isSafe(int n, vector<vector<char>>& matrix, int i, int j){

        // row-check
        for (int p=i; p>=0; p--){
            if (matrix[p][j] == 'Q')    return false;
        }

        // diagonal-check
        for (int p=i,q=j; p>=0 && q>=0; p--, q--){
            if (matrix[p][q] =='Q')
                return false;
        }

        for (int p=i, q=j; p>=0 && q<n; p--, q++){
            if (matrix[p][q] =='Q')
                return false;
        }

        return true;
    };

    void solutionForNQueens(int i, int j, vector<vector<char>>& matrix, vector<vector<string>>& ans){
        int n = matrix.size();

        // break condition
        if (i == n) {
            vector<string> board;

            for (auto& row : matrix) {
                board.push_back(string(row.begin(), row.end()));
            }
        
            ans.push_back(board);
            return;
        }

        // main recursive logic
        for (int j=0; j<n; j++){

            // if its safe to add Queen at i,j. Add it.
            if (isSafe(n, matrix, i, j)){
                matrix [i][j] = 'Q'; 
            
                solutionForNQueens(i+1, j, matrix, ans);
                matrix[i][j] = '.';     // backtracking
            }
        }   
    };

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> matrix (n,vector<char>(n,'.'));    // chessboard of size n x n
        vector<vector<string>> ans;

        solutionForNQueens (0, 0, matrix, ans);

        return ans;
    }
 };

 int main(){
    Solution sol;

    vector<vector<string>> ans = sol.solveNQueens(4);

    for (auto a: ans){
        for (auto b: a){
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
 }