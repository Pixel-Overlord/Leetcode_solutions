/*
 * 46. Permutations

 * Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * 
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 */

//  We will solve it using recursion.
//  Concept is: We have to fill 3 spaces with 3 numbers. 
//  Number of permutations for an 'n' digit number are 2^n.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void calculatePermute (vector<int>& nums, vector<vector<int>>& ans,int idx){

        // boundary condition
        if (idx == nums.size()){
            ans.push_back(nums);
            return ;
        }

        for (int i = idx; i<nums.size(); i++){
            // inclusion of a number
            swap (nums[i], nums[idx]);

            calculatePermute (nums, ans, idx + 1);

            // backtracking
            swap (nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> ans;

        calculatePermute (nums, ans, 0);

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    ans = sol.permute(nums);

    cout << "permutations are" << endl; 
    for (auto a: ans){
        for (auto b: a){
            cout << b << " ";
        }
        cout << endl;
    }
}