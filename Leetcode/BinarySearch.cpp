/* Concept of Binary Search is basically 2-pointer approch on a SORTED ARRAY.
 *
 * We take a mid. Match the element at mid to target. 
 *  - If equals, return it;
 *  - If less, the target lies somewhere AFTER the mid position.
 *  - If greater, the target lies somewhere BEFORE the mid position. 
 * 
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 int BinarySearch(vector<int>& nums, int& target)
 {
    int start = 0, end = nums.size() - 1;
    int mid = 0;

    while (start <= end)
    {
        mid = start + (end - start)/2;

        if (nums[mid] == target) 
        {
            return mid+1;
        }

        else if(nums[mid] < target)
        {
            start = mid + 1;
        }

        else 
        {
            end = mid - 1;
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
 
     ans = BinarySearch(nums, target);

     cout << "Target at position : " << ans;
 }