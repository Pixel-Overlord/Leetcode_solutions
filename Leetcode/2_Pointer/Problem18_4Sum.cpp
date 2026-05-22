/* 
 * 18. 4Sum
 * 
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 * 
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * You may return the answer in any order.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;

 class Solution{
 public: 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        for (int i=0; i<n; i++){

            // optimization 1;
            if (i > 0 && nums[i] == nums[i-1])    continue;

            for (int j=i+1; j<n; j++){

                //// optimization 2;
                //while (j < n && nums[j] == nums[j-1])   continue;

                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Apply binary search to find last 2 elements of set.
                int p = j+1;
                int q = n-1; 

                while (p < q){
                    int sum = nums[i] + nums[j] + nums[p] + nums[q];

                    if (sum < target){
                        p++;
                    }
                    else if (sum > target){
                        q--;
                    }
                    // sum equals target
                    else {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;

                        // optimization 3;
                        while (p < q && nums[p] == nums[p-1])   p++;
                    }
                }
            }
        }
        return ans;
    }
 };

 int main(){
    Solution sol;

    //[-2,-1,-1,1,1,2,2]
    vector<int> nums = {-2,-1,-1,1,1,2,2};
    int target = 0;

    vector<vector<int>> ans = sol.fourSum(nums, target);

    
    for(auto a :ans){
        for(auto b : a){
            cout << b << " " ;
        }
        cout << endl;
    }
 }