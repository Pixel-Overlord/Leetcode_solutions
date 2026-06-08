/* 
 * Merge sort is basically a sorting algo with O(nlogn) time complexity.
 * 
 * Logic is simple : 
 * break and rule. Break to individual level than merge.
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 class Solution {
 public: 
    // merge two sorted arrays;
    void merge(vector<int>& nums, int start, int end, int mid){
        int i = start;
        int j = mid + 1;

        vector<int> temp;

        while(i <= mid && j <= end){
            if (nums[i] < nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid){
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= end){
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            nums[start + k] = temp[k];
        }
    }

    void mergeSort(vector<int>& nums, int start, int end) {
        if (start >= end)
            return;

        int mid = start + (end - start) / 2;

        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);

        merge(nums, start, end, mid);
    }
 };

 int main() {
    vector<int> nums = {12,31,35,8,32,17};

    Solution sol;
    sol.mergeSort(nums, 0, nums.size()-1);

    cout << "Sorted array is : " << endl;

    for (auto a: nums){
        cout << a << " ";
    }

    return 0;
 }
