/* 
 * 239. Sliding Window Maximum
 *
 * You are given an array of integers nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k numbers in the window.
 * Each time the sliding window moves right by one position.
 * 
 * Return the max sliding window.
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * 
 * Explanation: 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 */

 #include <iostream>
 #include <vector>
 #include <deque>
 using namespace std;

 class Solution {
 public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        // first we will store the first k elements in deque;
        for (int i = 0; i < k; i++) {
            // removing from last if the the element at back is smaller than current element
            // for example: dq = {-1} and current element is {3}
            // {-1} is smaller than {3}. so {-1} can never be the greater number in the subset of size k.
            while (dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // Analyze next windows.
        for (int i = k; i < nums.size(); i++) {
            // store greater element (at the starting of dq) in ans vector.
            ans.push_back(nums[dq.front()]);

            // we need to add extra step, i.e. to check if the current queue contains only the elements of 
            // current subset.
            // For ex: dq = {3,-1,-3} and next subsets will be {-1,-3,5}.
            // Now if we want to include for 5, the dq has elements of before the subsets as well.
            // we have to remove that element from front.
            while (dq.size() > 0 && dq.front() <= i-k) {
                dq.pop_front();
            }

            while (dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        
        return ans;
    }
 };

 int main() {
    Solution sol;

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    // vector<int> nums = {1};
    // int k = 1;

    vector<int> ans = sol.maxSlidingWindow(nums, k);

    for (auto a: ans) {
        cout << a << " ";
    }
    return 0;
 }