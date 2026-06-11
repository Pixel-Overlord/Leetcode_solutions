/* 
 * 392. Is Subsequence
 * 
 * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
 * 
 * A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 * Example 2:
 * 
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 */

 #include <iostream>
 #include <algorithm>
 #include <vector>
 #include <unordered_map>
 using namespace std;

 class Solution {
 public:
    bool isSubsequence(string s, string t) {
        if (t.length() == 0 && s.length() == 0)    return true;

        unordered_map<char, vector<int>> charCount;

        for (int i=0; i<t.length(); i++) {
            charCount[t[i]].push_back(i);
        }
       
        int index = -1;
        
        for (auto ele : s) {
            if (charCount.find(ele) == charCount.end())
                return false;

            const vector<int> positions = charCount[ele];
            auto nextPos = upper_bound(positions.begin(), positions.end(), index);

            if (nextPos == positions.end())
                return false; 

            index = *nextPos;
        }
        return true;
    }
 };

 int main() {
    Solution sol;

    string s = "aza";
    string t = "abzba";

    bool ans = sol.isSubsequence(s, t);

    cout << "Is subsequence : " << ans; 

    return 0;
 }