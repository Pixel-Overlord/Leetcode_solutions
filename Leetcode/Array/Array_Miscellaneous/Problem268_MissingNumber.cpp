/* 
 * Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range
 * that is missing from the array.
 * 
 * 
 * Example 1: 
 * 
 * Input: nums = [3,0,1]
 * Output: 2
 * Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3].
 *              2 is the missing number in the range since it does not appear in nums.
 * 
 * Example 2:
 * 
 * Input: nums = [0,1]
 * Output: 2
 * Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 
 *              2 is the missing number in the range since it does not appear in nums.
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 class Solution {
 public:
     int missingNumber(vector<int>& nums) {
         int n = nums.size(), sum = 0;

         int actualSum = (n*(n+1))/2;

         for (auto a : nums) {
            sum += a;
         }

         return actualSum - sum;
     }
 };

 int main() {
    Solution sol;
    vector<int> nums = {3,0,1};

    cout << sol.missingNumber(nums);

    return 1;
 }