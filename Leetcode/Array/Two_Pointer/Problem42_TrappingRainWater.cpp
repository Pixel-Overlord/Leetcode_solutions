/* 
 * 42. Trapping Rain Water
 * 
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 *  
 * 
 * Example 1:
 * 
 * 
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
 * Example 2:
 * 
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 class Solution {
 public:
     int trap(vector<int>& height) {
         // calculate max left and max right boundry and their respective areas.

         int left = 0, right = height.size() - 1;
         int lmax = 0, rmax = 0;

         int area = 0;

         while (left < right) {
            lmax = max(lmax, height[left]);
            rmax = max(rmax, height[right]);

            if (lmax < rmax) {
                area += lmax - height[left];
                left++;
            }
            else {
                area += rmax - height[right];
                right--;
            }
         }

         return area;
     }
 };

 int main() {
    Solution sol;

    vector<int>  heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = sol.trap(heights);

    cout << "Max water tapped is : " << ans;
    return 0;
 }