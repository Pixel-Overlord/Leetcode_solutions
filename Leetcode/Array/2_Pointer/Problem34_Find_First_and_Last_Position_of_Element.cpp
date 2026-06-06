/* 
 * Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
 * 
 * If target is not found in the array, return [-1, -1].
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * 
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;

 class Solution {
 public: 
     vector<int> searchRange(vector<int>& nums, int target) {
        auto lower = lower_bound(nums.begin(), nums.end(), target);

        if (lower == nums.end() || *lower != target) {
            return {-1, -1};
        }

        auto upper = upper_bound(nums.begin(), nums.end(), target);

        return {
            int (lower - nums.begin()),
            int (upper - nums.begin() - 1)
        };
     }
 };

 int main() {
     Solution sol;

     vector<int> nums = {5,7,7,8,8,10};
     int target = 8;

     vector<int> ans = sol.searchRange(nums, target);

     for (auto a : ans) {
        cout << a << " ";
     }
 }