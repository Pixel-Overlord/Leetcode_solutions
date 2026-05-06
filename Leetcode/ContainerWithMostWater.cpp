// 11. Container With Most Water
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
// In this case, the max area of water (blue section) the container can contain is 49.

#include <iostream>
#include <vector>

using namespace std;

int maxArea (vector<int>& height)
{
    int start = 0, end = height.size() - 1;
    int area = 0;
    while (start < end)
    {
        int width = end - start;
        int minHeight = min (height[start],height[end]);
        area = max (area, minHeight * width);

        height[start] < height[end] ? start ++ : end --;
    }
    return area;
}

int main()
{
    int size;
    cout << "Enter the size of height array :" << endl;
    cin >> size;

    vector<int> height(size);
    cout << "Enter the heights :" << endl;
    for (int i=0; i<height.size(); i++)
    {
        cin >> height[i];
    }

    int maxContainerArea = maxArea(height);
    cout << "Max Area is :" << maxContainerArea;
}