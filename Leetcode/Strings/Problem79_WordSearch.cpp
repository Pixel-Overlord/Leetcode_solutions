/* 
 * 79. Word Search
 * 
 * Given an m x n grid of characters board and a string word, return true if word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
 * The same letter cell may not be used more than once.
 * 
 * Example 1:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
 * Output: true
 * Example 2:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
 * Output: true
 * Example 3:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
 * Output: false
 */

 // Pattern is similar to Rat-In a Maze. 
 // Just the difference is 1s are the string characters and the 0s are non-matching characters.

 #include <iostream>
 #include <vector>
 using namespace std;

 class Solution {
 public:
     bool recursiveHelper(vector<vector<char>>& board, string& word, int row, int column, int idx) {
         // break condition 1:
         if (row < 0 || column < 0 || row >= board.size() || column >= board[0].size()) {
            return false;
         }

         // break condition 2:
         if (board[row][column] != word[idx]) {
            return false;
         }

         // break condition 3:
         if (idx == word.size() - 1) {
            return true;
         }

         char temp = board[row][column];
         board[row][column] = '.';

         // recursive condition
         bool found = 
            (recursiveHelper(board, word, row+1, column, idx+1)||
            recursiveHelper(board, word, row-1, column, idx+1)||
            recursiveHelper(board, word, row, column+1, idx+1)||
            recursiveHelper(board, word, row, column-1, idx+1));
        
        // backtracking
        board[row][column] = temp;

        return found;
     }

     bool exist(vector<vector<char>>& board, string word) {
         int rows = board.size();
         int cols = board[0].size();

         for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (recursiveHelper(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }        
 };
 
 int main() {
    Solution sol;

    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";

    bool ans = sol.exist(board, word);

    cout << "Path found " << ans;
 }