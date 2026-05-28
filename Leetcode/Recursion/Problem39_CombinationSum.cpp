/* 
 * 39. Combination Sum
 *
 * Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of 
 * candidates where the chosen numbers sum to target. You may return the combinations in any order.
 * 
 * The same number may be chosen from candidates an unlimited number of times. 
 * Two combinations are unique if the frequency of at least one of the chosen numbers is different.
 * 
 * The test cases are generated such that the number of unique combinations that sum up to target
 * is less than 150 combinations for the given input.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 * Example 2:
 * 
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 * Example 3:
 * 
 * Input: candidates = [2], target = 1
 * Output: []
 */

 #include <iostream>
 #include <vector>
 #include <set>
 using namespace std;

 class Solution {
 public:
     set<vector<int>> ansSet;
     void combinationSumHelper(vector<int>& nums, int target, int i, vector<vector<int>>& ans, vector<int>& sol) {
         // base condition
         if (i == nums.size() || target < 0){
            return;
         }
         if (target == 0){

            if (ansSet.find(sol) == ansSet.end()){
                ans.push_back({sol});
                ansSet.insert(sol);
            }

            return;
         } 

         sol.push_back(nums[i]);

         // recursive calls
         combinationSumHelper(nums, target - nums[i], i+1, ans, sol);  // inclusion single (i will update)
         combinationSumHelper(nums, target - nums[i], i, ans, sol);   // inclusion multiple (i won't update)
         sol.pop_back();
         combinationSumHelper(nums, target, i+1, ans, sol);  // exclusion (i will update)
     }

     vector<vector<int>> combinationSum(vector<int>& nums, int target) {
         vector<vector<int>> ans;
         vector<int> sol;

         combinationSumHelper(nums, target, 0, ans, sol);

         return ans;
     }
 };

 int main() {
    vector<int> nums = {2,3,6,7};
    int target = 7;

    Solution sol;
    vector<vector<int>> ans = sol.combinationSum(nums, target);

    for (auto a : ans){
        for (auto b : a){
            cout << b << " ";
        }
        cout << endl;
    }
 }