//169. Majority Element
//
//Given an array nums of size n, return the majority element.
//The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
//
//Example :
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2

#include <iostream>
#include <vector>
using namespace std;

int MajorityElement(vector<int>& nums)
{
    int majElement = nums [0];
    int freq = 0;

    for (int i=1; i<nums.size(); i++)
    {
        if (nums[i] == majElement)
        {
            freq ++;
        }
        else
        {
            majElement = nums [i+1];
            freq --;
        }
    }
    return majElement;
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

    int majElement = MajorityElement(nums);
    cout << "Majority Element is :" << majElement;
}
