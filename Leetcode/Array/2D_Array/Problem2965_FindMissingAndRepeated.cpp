/* 2965. Find Missing and Repeated Values
 * 
 * You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2].
 * Each integer appears exactly once except a which appears twice and b which is missing. 
 * The task is to find the repeating and missing numbers a and b.
 * 
 * Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.
 * 
 * Example 1:
 * 
 * Input: grid = [[1,3],[2,2]]
 * Output: [2,4]
 * Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
 * 
 * Example 2:
 * 
 * Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
 * Output: [9,5]
 * Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].
 */

 #include <iostream>
 #include <unordered_set>
 #include <vector>
 using namespace std;

 class Solution{
 public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int rows = grid.size();
        int column = grid[0].size();
        int sumOfMatrix = 0;

        unordered_set<int> ele;
        vector<int> ans;

        for (int i=0; i<rows; i++){
            for(int j=0; j<column; j++){
                sumOfMatrix += grid[i][j];

                if (ele.count(grid[i][j])) {
                    ans.push_back(grid[i][j]);
                }
                
                ele.insert(grid[i][j]);                
            }
        }
        int sumOfElement = ((rows*rows) * ((rows*rows) + 1))/2;
        ans.push_back(sumOfElement - (sumOfMatrix - ans[0]));

        return ans;
    }
 };

 int main(){
    vector<vector<int>> matrix = {{9,1,7},{8,9,2},{3,4,6}};
    
    Solution sol;
    vector<int> ans = sol.findMissingAndRepeatedValues(matrix);
    cout << "Ans is : " << ans[0] << " and " << ans[1];
    return 0;
 }