/* 
 * Celebrity is that value or index which is 'known' to everyone but it itself does not know anyone.
 * i.e the value of arr[cel][j] == 0, but
 * the 'i' does knows its 'cel', that is arr[i][cel] == 1.  (obviously excluding the case where i==cel)
 * 
 * Example : 
 * input : nums = {{0,1,0},{1,0,0},{0,1,0}}
 *  0   1   0
 *  1   0   0
 *  0   1   0
 * 
 *  output : 1 || bcz any nums[i][1] = 1 but any nums[cel][j] != 1
 */


 /* 
 We will solve this by elimination.
 Concept is if nums[i][j] == 1, than i cannot be the celebrity because here j is the celebrity.
 
 And, then we will verify its value as, if any of nums[cel][i] == 1, we will return false (means no celebrity).
 or if any nums[i][cel] == 0, return false since i doesn't know the celebrity.
  */


 #include <iostream>
 #include <vector>
 using namespace std;

 class Solution {
 public:
    int getCelebrity(vector<vector<int>> nums) {
        int celebrity = 0;

        // elimination
        for (int i=1; i<nums.size(); i++) {
            if (nums[celebrity][i] == 1)
                celebrity = i;
        }

        // verification
        for (int i=0; i<nums.size(); i++) {
            if (i == celebrity)
                continue;

            if (nums[i][celebrity] == 0 || nums[celebrity][i] == 1)
                return -1;
        }

        return celebrity;
    }
 };

 int main() {
    vector<vector<int>> nums = {{0,1,0},{1,0,0},{0,1,0}};

    Solution sol;
    int ans = sol.getCelebrity(nums);

    cout << "The celebrity is : " << ans;
    return 0;
 }