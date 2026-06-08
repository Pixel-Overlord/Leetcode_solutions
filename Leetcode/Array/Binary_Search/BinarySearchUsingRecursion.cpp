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

 int BinarySearchUsingRecursion(vector<int>& nums, int& target, int start,int end)
 {    
    int mid = 0;

    if (start <= end)
    {
        mid = start + (end - start)/2;
        if (nums[mid] == target) 
        {
            return mid+1;
        }
        else if(nums[mid] < target)
        {
            return BinarySearchUsingRecursion(nums,target, mid + 1, end);
        }
        else 
        {
            return BinarySearchUsingRecursion(nums,target, start, mid - 1);
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
 
     ans = BinarySearchUsingRecursion(nums, target, 0, size -1);

     cout << "Target at position : " << ans;
 }