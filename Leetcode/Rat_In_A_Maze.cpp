/* Rat in a Maze
 * 
 * Difficulty: Medium
 * Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1).
 * The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).
 * 
 * The matrix contains only two possible values:
 * 
 * 0: A blocked cell through which the rat cannot travel.
 * 1: A free cell that the rat can pass through.
 * 
 * Your task is to find all possible paths the rat can take to reach the destination, 
 * starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path.
 * Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
 * If no path exists, return an empty list.
 * 
 * Examples:
 * 
 * Input: maze[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
 * Output: ["DDRDRR", "DRDDRR"]
 * Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, 
 * when printed in sorted order we get DDRDRR DRDDRR.
 * 
 * Approach : recursion + backtracking
 * 
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 void findPath (vector<vector<int>>& maze, vector<vector<bool>>& visited,int& n, int row, int column, vector<string>& ans, string path)
 {    
    // breaking conditions : 
    // - If the row or column goes behind or accross the boundry walls.
    // - If the row or column equals 0, return.

    if (row < 0 || column < 0 || row >= n || column >= n || maze[row][column] == 0 ||  visited[row][column] == true)
        return ;

    if (row == n-1 && column == n-1){
        ans.push_back(path);
        return;
    }

    visited[row][column] = true; //visit

    findPath (maze, visited, n, row+1, column, ans, path+"D");
    findPath (maze, visited, n, row, column+1, ans, path+"R");
    findPath (maze, visited, n, row, column-1, ans, path+"L");
    findPath (maze, visited, n, row-1, column, ans, path+"U");

    // to make the perticualar portion false so that the next path can follow this as well.
    visited[row][column] = false;
 };

 int main()
 {
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = maze.size();
    vector<vector<bool>> visited(n, vector<bool>(n,false));

    vector <string> ans;
    string path;
    int row = 0, column = 0;
    findPath(maze,visited,n,row,column,ans,path);

    for (auto ele:ans)
    {
        cout << ele << " ";
    }
 }