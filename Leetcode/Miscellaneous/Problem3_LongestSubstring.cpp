/* 
 * 3. Longest Substring Without Repeating Characters
 * 
 * Given a string s, find the length of the longest substring without duplicate characters.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
 * Example 2:
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 */

 #include <iostream>
 #include <vector>
 #include <unordered_map> 
 #include <climits>
 using namespace std;

 class Solution {
 public:
     int lengthOfLongestSubstring(string s) {
 
         unordered_map<char, int> lastSeen;
 
         int left = 0;
         int maxLength = 0;
 
         for (int right = 0; right < s.length(); right++) {
 
             if (lastSeen.find(s[right]) != lastSeen.end()) {
                 left = max(left, lastSeen[s[right]] + 1);
             }
 
             lastSeen[s[right]] = right;
 
             maxLength = max(maxLength, right - left + 1);
         }
 
         return maxLength;
     }
 };

 int main() {
    string s = " ";
    Solution sol;

    cout << "Length of longest substring: " ;
    cout << sol.lengthOfLongestSubstring(s);
 }