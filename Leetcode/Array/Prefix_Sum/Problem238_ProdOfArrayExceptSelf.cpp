// 238. Product of Array Except Self

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

/* 
 * Solution : Concept would be first get the products of all left except self. Than get the product of all right except right.
 * Now result the product of each left to its subsequent right.
 * 
 * Take the above example:
 * 
 * nums : [1,2,3,4]
 * leftProd = [1,1,2,6]
 * RightProd = [24,12,4,1]
 * resultProd = [ (24*1), (12*1), (4*2), (1*6)]
 * 
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 void productOfArray(vector<int> nums, int n)
 {
    int leftProd = 1, rightProd = 1;
    vector<int> ans(n);

    for (int i=0; i<n; i++)
    {
        ans[i] = leftProd;
        leftProd *= nums[i];
    }

    for (int i = n-1; i>=0 ; i--)
    {
        ans[i] *= rightProd;
        rightProd *= nums[i];
    }

    for (int c : ans)
    {
        cout << c << " ";
    }
 }

 int main()
 {
     int size;
     cout << "Enter the size of array :" << endl;
     cin >> size;
 
     vector<int> nums(size);
     cout << "Enter the elements :" << endl;
     for (int i=0; i<nums.size(); i++)
     {
         cin >> nums[i];
     }
 
     productOfArray(nums, size);
 }
