/* 
 * 219. Contains Duplicate II
 * 
 * Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * Example 2:
 * 
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * Example 3:
 * 
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 */

 #include <iostream>
 #include <unordered_map>
 #include <vector>
 using namespace std;

 class Solution {
 public:
     bool containsNearbyDuplicate(vector<int>& nums, int k) {
         unordered_map<int, int> numCount;

         for (int i=0; i<nums.size(); i++) {

            if (numCount.find(nums[i]) != numCount.end()) {

                if (i - numCount[nums[i]] <= k)
                    return true;
            }

            numCount[nums[i]] = i;
         }

         return false;
     }
 };

 int main() {
     Solution sol;
     vector<int> nums = {1,2,3,1};
     int k = 3;

     bool ans = sol.containsNearbyDuplicate(nums, k);

     cout << ans;
     return 1;
 }