/* 852. Peak Index in a Mountain Array
 *
 * You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
 * 
 * Return the index of the peak element.
 * Your task is to solve it in O(log(n)) time complexity.
 * 
 * Example 1:
 * 
 * Input: arr = [3,5,3,2,0]
 * Output: 3
 * 
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 int peakIndexInMountainArray(vector<int>& arr) {
     int start = 1, end = arr.size() - 2;
     int mid = 0;
     while (start <= end)
     {
         mid = start + (end-start)/2;
         if (arr[mid] >= arr[mid+1] && arr[mid] >= arr[mid-1])
         {
             return mid + 1;
         }
         else if (arr[mid] < arr[mid-1])
         {
             end = mid - 1;
         }
         else
         {
             start = start + 1;
         }
     }
     return -1;
 }

 int main()
 {
     int size, ans;
     cout << "Enter the size of array :" << endl;
     cin >> size;
 
     vector<int> nums(size);
     cout << "Enter the elements :" << endl;
     for (int i=0; i<nums.size(); i++)
     {
         cin >> nums[i];
     }
 
     ans = peakIndexInMountainArray(nums);

     cout << "Peak at position : " << ans;
 }


 

