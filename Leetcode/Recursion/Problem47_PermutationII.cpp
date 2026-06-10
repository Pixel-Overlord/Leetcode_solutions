/* 
 * 47. Permutations II
 * 
 * Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 *  [1,2,1],
 *  [2,1,1]]
 * Example 2:
 * 
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 */

 #include <iostream>
 #include <algorithm>
 #include <vector>
 using namespace std;

class Solution {
public:

    void solve(vector<int>& nums,
               vector<vector<int>>& ans,
               vector<int>& curr,
               vector<bool>& used) {

        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            // Skip duplicates
            if (i > 0 &&
                nums[i] == nums[i - 1] &&
                !used[i - 1])
                continue;

            used[i] = true;
            curr.push_back(nums[i]);

            solve(nums, ans, curr, used);

            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(nums.size(), false);

        solve(nums, ans, curr, used);

        return ans;
    }
};

 int main() {   
    Solution sol;

    vector<int> nums = {1,1,2};

    vector<vector<int>> ans;
    ans = sol.permuteUnique(nums);;

    cout << "permutations are" << endl; 
    for (auto a: ans){
        for (auto b: a){
            cout << b << " ";
        }
        cout << endl;
    }
    

    return 0;
 }