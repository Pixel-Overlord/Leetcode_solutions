/* 
 * input : arr = {6,8,0,1,3};
 * output : 8,-1,1,3,-1 respectively.
 * 
 * next greater element is basically nothing but the next immediate greater number on the right.
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <stack>
 using namespace std;

 class Solution {
 public:
    vector<int> nextGreater(vector<int>& nums) {
        stack<int> s;
        vector<int> ans;
        for (int i = nums.size() - 1; i>=0; i--) {

            while (s.size() > 0 && s.top() <= nums[i]) {
                s.pop();
            }

            if (s.empty())
                ans.push_back(-1);
            else   
                ans.push_back(s.top());

            s.push(nums[i]);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
 };

 int main() {
    Solution sol;

    vector<int> nums = {6,8,0,1,3};
    vector<int> ans = sol.nextGreater(nums);

    for (auto a: ans) {
        cout << a << " ";
    }
    return 1;
 }