/* 
 * 347. Top K Frequent Elements
 * 
 * Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * Example 3:
 * Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
 * Output: [1,2]
 */

 #include <iostream>
 #include <vector>
 #include <unordered_map>
 using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& ele : freq) {
            bucket[ele.second].push_back(ele.first);
        }

        vector<int> result;

        for (int i = bucket.size() - 1; i >= 0 && result.size() < k; --i) {
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k)
                    return result;
            }
        }

        return result;
    }
};

 int main() {
     Solution sol;

     vector<int> nums = {1,2,1,2,1,2,3,1,3,2};
     int k = 2;

     vector<int> ans = sol.topKFrequent(nums, k);

     for (auto a: ans) {
        cout << a << " ";
     }

     return 0;
 }