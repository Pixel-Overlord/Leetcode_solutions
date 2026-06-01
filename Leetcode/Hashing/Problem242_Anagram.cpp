/* 
 * 242. Valid Anagram
 * 
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 *  
 * 
 * Example 1: * 
 * Input: s = "anagram", t = "nagaram" * 
 * Output: true
 * 
 * Example 2: * 
 * Input: s = "rat", t = "car" * 
 * Output: false
 */

//  using unordered_map and using array, both will provide a solution of O(nlogn). The only difference is using array will give O(1) spcace complexity
//  while unordered_map will give O(k) spaceComplexity. K being no. of unique elements stored.

 #include <iostream>
 #include <vector>
 #include <string>
 using namespace std;

 class Solution {
 public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }
        
        /* 
        SOLUTION 1: 
        unordered_map<char, int> charCount;

        for (char a: s) {
            charCount[a]++;
        }

        for (char b: t) {
            charCount[b]--;
        }

        // check if any of the key in map have value > 0. 
        // Since anangram have all the characters of first string with exact count, the entries in the map shoud canceled out. 
        for (auto ele: charCount) {
            if (ele.second != 0) {
                return false;   // not an anagram.
            }
        }
        */

        // Solution 2:
        vector<int> alphabet(26,0);

        for (int i = 0; i < s.length(); i++) {
            alphabet[s[i] - 'a']++;
            alphabet[t[i] - 'a']--;
        }

        for (auto ele: alphabet) {
            if (ele != 0) {
                return false;   // not an anagram.
            }
        }

        return true;
    }
 };

 int main() {
    string s = "a";
    string t = "ab";

    Solution sol;

    bool ans = sol.isAnagram(s, t);

    cout << "Is " << s << " an Anagram : " << ans;
 }