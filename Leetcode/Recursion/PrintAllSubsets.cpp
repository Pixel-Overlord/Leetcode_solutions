/*
 * Print all subsets of a vector using recursion and backtracking.
 *
 * Example : 
 * 
 * Input : nums = {1,2,3}
 * Output : 123 , 12 , 13 , 1, 23, 2, 3, <empty space>
 * 
 */ 


#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        void allSubsets(vector<int> nums, vector<int>& ans, int i){
            // break or edge conditions
            // break when the i == n.
            // Note that the max number of subsets of any vector is 2^n .
            if (i==nums.size()){
                for(auto ele:ans){
                    cout << ele;
                }
                cout << endl; 
                return;
            }

            //inclusion condition.
            ans.push_back(nums[i]);
            allSubsets(nums, ans, i+1);

            //exclusion condition.
            ans.pop_back(); //backtracking starts from here.
            allSubsets(nums, ans, i+1);
        }
};

int main()
{
    vector<int> nums = {1,2,3};
    vector<int> ans;
    Solution sol;
    sol.allSubsets(nums, ans, 0);
}