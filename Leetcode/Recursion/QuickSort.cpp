/*
 * Quick sort is used to sort an array as well. It is also of O(nlog n) same as merge sort.
 * 
 * But Merge sort used o(n) extra space while Quick used O(log n). So, comparatively efficient.
 * 
 * Note: Prefer Merge sort when worse-case scenerio is to be considered.
 * 
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 class Solution {
 public:   
    int findPivot(vector<int>& nums, int start, int pivot) {
      int idx = start - 1;

      for (int j = start; j < nums.size(); j++) {

         if (nums[j] < nums[pivot]){
            idx++;
            swap(nums[j], nums[idx]);
         }
      }

      // adjusting pivot number at its location;  
      idx++;
      swap(nums[pivot], nums[idx]);

      return idx;
    }

    void quickSort(vector<int>& nums, int start, int end) {

       // breaking condition;
       if (start < end) {

          int pivotIdx = findPivot(nums, start, end);
   
          quickSort(nums, start, pivotIdx - 1);
          quickSort(nums, pivotIdx + 1, end);
       }
    }
 };

 int main() {
    vector<int> nums = {5,2,6,4,1,3};

    Solution sol;
    sol.quickSort(nums, 0, nums.size()-1);

    for (auto a : nums) {
      cout << a << " ";
    }
    return 0;
 }