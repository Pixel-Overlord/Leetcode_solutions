/* 
 * Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
 * return the next greater number for every element in nums.
 * 
 * The next greater number of a number x is the first greater number to its traversing-order next in the array,
 * which means you could search circularly to find its next greater number.
 * If it doesn't exist, return -1 for this number.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; 
 * The number 2 can't find next greater number. 
 * The second 1's next greater number needs to search circularly, which is also 2.
 * Example 2:
 * 
 * Input: nums = [1,2,3,4,3]
 * Output: [2,3,4,-1,4]
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <stack>
 using namespace std;

 class Solution {
 public:
     vector<int> nextGreaterElements(vector<int>& nums) {
         stack<int> s;
         int n = nums.size();
         vector<int> v(n, -1);

         for (int i = (2 * n) - 1; i >= 0; i--) {
            while (s.size() > 0 && nums[s.top()] <= nums[i % n]) {
                s.pop();
            }

            if (s.empty()) {
                v[i % n] = -1; // need to check for last element.
            }
            else {
                v[i % n] = nums[s.top()];
            }
            s.push(i % n);
         }

         return v;
     }
 };

 int main() {
    vector<int> nums = {5,4,3,2,1};

    Solution sol;
    vector<int> ans = sol.nextGreaterElements(nums);

    for (auto a: ans) {
        cout << a << " ";
    }
    return 0;
 }