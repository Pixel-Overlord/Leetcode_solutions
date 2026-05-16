/* 
 * 796. Rotate String
 *
 * Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
 * A shift on s consists of moving the leftmost character of s to the rightmost position.
 * 
 * For example, if s = "abcde", then it will be "bcdea" after one shift.
 * 
 * Example 1:
 * 
 * Input: s = "abcde", goal = "cdeab"
 * Output: true
 * 
 * Example 2:
 * 
 * Input: s = "abcde", goal = "abced"
 * Output: false
 * 
 */

 #include <iostream>
 #include <string>
 using namespace std;

 class Solution {
 public:
     bool rotateString(string s, string goal) {
         if (s.length() != goal.length())
             return false;
 
         string temp = s + s;
 
         return temp.find(goal) != string::npos;
     }
 };

 int main()
 {
    Solution sol;
    string s, goal;

    cout << "Enter string: ";
    getline(cin, s);

    cout << "Enter goal string: ";
    getline(cin, goal);

    bool ans = sol.rotateString(s,goal);
    cout << ans ;
 }