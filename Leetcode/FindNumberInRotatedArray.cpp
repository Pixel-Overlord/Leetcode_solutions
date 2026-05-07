/* 33. Search in Rotated Sorted Array 
 *
 * Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) 
 * such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 * For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
 * 
 * Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * Example 1:
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 int SearchInRotatedArray(vector<int>& nums, int& target)
 {
    int start = 0, end = nums.size()-1;
    int mid = 0;
    while (start <= end)
    {
        mid = start + (end - start)/2;
        if (nums[mid] == target) return mid + 1;
        if (nums[start] <= nums[mid])    //Left side is sorted
        {
            if (nums[start] <= target && target <= nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else    //Right side is sorted.
        {
            if (nums[mid] <= target && target <= nums[end])
            {
                start = mid + 1;
            }
            else
            {
                end = end - 1;
            }
        }
    }
    return -1;
 }

 int main()
 {
     int size, target, ans;
     cout << "Enter the size of array :" << endl;
     cin >> size;
 
     vector<int> nums(size);
     cout << "Enter the elements :" << endl;
     for (int i=0; i<nums.size(); i++)
     {
         cin >> nums[i];
     }

     cout << "Enter the target :" << endl;
     cin >> target;
 
     ans = SearchInRotatedArray(nums, target);

     cout << "Target at position : " << ans;
 }
