/*
 * 78. Subsets
 *
 * Given an integer array nums of unique elements, return all possible subsets (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in any order.
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * Example 2:
 * 
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 */ 


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void allSubsets(vector<int> nums, vector<int>& ans, int i, vector<vector<int>>& subsets){
            // break or edge conditions
            // break when the i == n.
            // Note that the max number of subsets of any vector is 2^n .
            if (i==nums.size()){
                subsets.push_back({ans});
                return ;
            }

            //inclusion condition.
            ans.push_back(nums[i]);
            allSubsets(nums, ans, i+1, subsets);

            //exclusion condition.
            ans.pop_back(); //backtracking starts from here.
            allSubsets(nums, ans, i+1, subsets);
        }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> ans;
        allSubsets(nums, ans, 0, subsets);

        return subsets;
    }
};

int main()
{
    vector<int> nums = {1,2,3};
    vector<int> ans;
    Solution sol;
    sol.subsets(nums);
}