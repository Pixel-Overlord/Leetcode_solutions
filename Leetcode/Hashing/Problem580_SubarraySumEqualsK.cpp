/* 
 * 560. Subarray Sum Equals K
 * 
 * Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
 * 
 * A subarray is a contiguous non-empty sequence of elements within an array.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * Example 2:
 * 
 * Input: nums = [1,2,3], k = 3
 * Output: 2 
 */

 // We can do this in O(n)2 and we can do this in O(n) time complexity as well.

 #include <iostream>
 #include <vector>
 #include <unordered_map>
 using namespace std;

 class Solution{
 public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, sum = 0;

        /* // O(n)2 solution.
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                sum = sum + nums[j];

                if (sum == k){
                    count++;
                }  
            }
            sum = 0;
        } */

        // O(n) approach using unordered_map. We will store prefix-sum (sum of previous elements).
        vector<int> prefixSum(n,0);

        // we got prefixSum arrays in this below for loop.
        prefixSum[0] = nums[0];
        for (int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        unordered_map<int,int> ans; // prefixSum, freq

        // now we check the main logic.
        for (int j=0; j<n; j++){
            if (prefixSum[j] == k){
                count ++;
            }

            // now we search a value {sum till nums[i-1]} = {sum till nums [j]} - k; So if we find this value in map(or occurance of sum till nums[i-1])
            int val = prefixSum[j] - k;
            if (ans.find(val) != ans.end()){
                count += ans[val];
            }

            // initialize the map with the prefixSum and set its frequency initially to 0;
            if (ans.find(val) == ans.end()){
                ans[prefixSum[j]] = 0;
            }

            // if already exist and not matches the k, increase frequency by 1.
            ans[prefixSum[j]]++;
        }
        return count;
    }
 };

 int main(){
    Solution sol;

    vector<int> nums = {1, 1, 1};
    int target = 2;
    int ans = sol.subarraySum(nums, target);

    cout << "The number of subarrays equals target are : " << ans;
 }