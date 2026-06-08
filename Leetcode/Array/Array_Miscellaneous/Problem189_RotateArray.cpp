/* 189. Rotate Array
 *
 * Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3,4,5,6,7], k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 */

 // we will use STL vector's reverse function
 // approach: note the array is nothing but reversing of kth elements AFTER ONE WHOLE REVERSE.
 // Reverse entire array
 // Reverse first k elements
 // Reverse remaining elements

 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;

 class Solution {
 public:
     void rotate(vector<int>& nums, int k) {
         if(nums.empty())
            return;

         k = k % nums.size();

         reverse(nums.begin(),nums.end());
         reverse(nums.begin(),nums.begin()+k);
         reverse(nums.begin()+k,nums.end());
     }
 };

 int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7}; int k = 3;

    sol.rotate(nums, k);
    cout << "Reversed arrray : ";
    for (auto ele:nums){
        cout << ele << " ";
    }
 }