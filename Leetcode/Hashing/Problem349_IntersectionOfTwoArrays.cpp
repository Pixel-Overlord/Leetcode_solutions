/* 
 * Given two integer arrays nums1 and nums2, return an array of their intersection. 
 * Each element in the result must be unique and you may return the result in any order.
 * 
 * 
 * Example 1:
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 * Example 2:
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * Explanation: [4,9] is also accepted.
 */

 #include <iostream>
 #include <vector>
 #include <unordered_set>
 using namespace std;

 class Solution {
 public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_set<int> s;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            s.insert(nums1[i]);
        }

        for (int j = 0; j < m; j++) {
            if (s.find(nums2[j]) != s.end()) {

                ans.push_back(nums2[j]);
                s.erase(nums2[j]);
            }
        }

        return ans;
    }
 };

 int main() {
    Solution sol;
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};

    vector<int> ans = sol.intersection(nums1, nums2);

    for (auto a : ans) {
        cout << a << " ";
    }

    return 1;
 }