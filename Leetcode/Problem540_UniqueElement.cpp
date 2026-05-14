/* 
 * 540. Single Element in a Sorted Array
 * You are given a sorted array consisting of only integers where every element appears exactly twice,
 * except for one element which appears exactly once.
 * 
 * Return the single element that appears only once.
 * 
 * Your solution must run in O(log n) time and O(1) space.
 * 
 * Example 1:
 * 
 * Input: nums = [1,1,2,3,3,4,4,8,8]
 * Output: 2
 * 
 * Example 2:
 * 
 * Input: nums = [3,3,7,7,10,11,11]
 * Output: 10
 * 
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 int singleNonDuplicate(vector<int>& nums)
 {
    int start = 0, end = nums.size() - 1;
    int mid;

    //handling edge case for single element.
    if (start == end)   return nums[start];

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (mid == 0 && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        if (mid == end && nums[mid] != nums[mid - 1])
        {
            return nums[mid];
        }
        
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid+1]) //element at mid is neither equals to its previous not later.
        {
            return nums[mid];
        }

        if (mid % 2 == 0)   // means no. of elements on left of mid and right are even.
        {
            (nums[mid] == nums[mid - 1]) ? (end = mid - 1) : (start = mid + 1);
        }
        else
        {
            (nums[mid] == nums[mid - 1]) ? (start = mid + 1) : (end = mid - 1);
        }
    }
    return -1;
 }

 int main()
 {
    int size ;
    cout << "Enter the size of vector : " << endl;
    cin >> size;

    vector<int> nums(size);
    cout << "Enter the elements : " << endl;

    for (int& ele : nums)
    {
        cin >> ele;
    }

    int uniqueEle = singleNonDuplicate (nums);
    cout << "Your unique element is : " << uniqueEle;
 }