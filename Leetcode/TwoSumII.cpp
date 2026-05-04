// 167. Two Sum II - Input Array Is Sorted
//
// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
// find two numbers such that they add up to a specific target number.
// 
// Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
// Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.
// The tests are generated such that there is exactly one solution. You may not use the same element twice.
// Your solution must use only constant extra space.
//
// Example 1:
//
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

// Solutions : We can solve it using map as well as 2-pointer approach.

#include <iostream>
#include <vector>
using namespace std;

vector<int> TwoSum(vector<int>& nums, int& target)
{
    int start = 0, end = nums.size() - 1;
    int sum = 0;

    while (start < end)
    {
        sum = nums[start] + nums[end];

        if (sum < target)
        {
            start++;
        }
        else if (sum > target)
        {
            end--;
        }
        else
        {
            return {start+1,end+1};
        }
    }
    return {};
}

int main()
{
    int size, target;
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

    vector<int> ans = TwoSum(nums, target);
    cout << "Numbers are at positions :" << ans[0] << " and " << ans[1];
}