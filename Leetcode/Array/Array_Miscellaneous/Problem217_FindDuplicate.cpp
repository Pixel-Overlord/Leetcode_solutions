/* 
 * 217. Contains Duplicate
 * 
 * Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3,1]
 * 
 * Output: true
 * 
 * Explanation:
 * 
 * The element 1 occurs at the indices 0 and 3.
 */

 #include <iostream>
 #include <vector>
 #include <unordered_set>
 using namespace std;

 class Solution {
 public:
     bool containsDuplicate(vector<int>& nums) {
         unordered_set<int> count;
 
         for (int i=0; i<nums.size(); i++) {
             if (count.find(nums[i]) != count.end()) {
                 return true;
             }
             count.insert(nums[i]);
         }
         return false;
     }
 };

 int main() {
    vector<int> nums = {1,2,3,1};

    Solution sol;

    bool ans = sol.containsDuplicate(nums);

    cout << "The array has all unique values : " << ans;
 }