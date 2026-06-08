/* 
 * 84. Largest Rectangle in Histogram
 * 
 * Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
 * 
 *  
 * 
 * Example 1:
 * 
 * 
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 * Explanation: The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10 units.
 */

 #include <iostream>
 #include <vector>
 #include <stack>
 using namespace std;

 class Solution {
 public:
     int largestRectangleArea(vector<int>& heights) {
         stack<int> s;
         int n = heights.size();

         vector<int> right(n,0);
         vector<int> left(n,0);
 
 
         // right smaller
         for (int i = n-1; i >= 0; i--) {
             while (s.size() > 0 && heights[s.top()] >= heights[i]) {
                 s.pop();
             }
 
             right[i] = s.empty() ? n : s.top();          
             s.push(i);
         }
 
         while (!s.empty()) {
             s.pop();
         }
 
         // left smaller
         for (int i = 0; i < n ; i++) {
             while (s.size() > 0 && heights[s.top()] >= heights[i]) {
                 s.pop();
             }
 
             left[i] = s.empty() ? -1 : s.top();          
             s.push(i);
         }
 
         int ans = 0;
 
         for (int i=0; i<n; i++) {
             int width = right[i] - left[i] - 1;
             int area = heights[i] * width;
 
             ans = max(ans, area);
         }
 
         return ans;
     }
 };

 int main() {
    vector<int> heights = {2,1,5,6,2,3}; 

    Solution sol;
    int ans = sol.largestRectangleArea(heights);

    cout << ans;
    return 1; 
 }