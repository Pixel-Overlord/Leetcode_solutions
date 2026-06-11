/* 
 * 792. Number of Matching Subsequences
 * 
 * Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
 * 
 * A subsequence of a string is a new string generated from the original string with
 * some characters (can be none) deleted without changing the relative order of the remaining characters.
 * 
 * For example, "ace" is a subsequence of "abcde".
 *  
 * 
 * Example 1:
 * 
 * Input: s = "abcde", words = ["a","bb","acd","ace"]
 * Output: 3
 * Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
 * Example 2:
 * 
 * Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
 * Output: 2
 */


 /* Approach :
  * 
  * Q. What is the thing that question actually ask?
  * A. That the element in words array should be in same increasing order as in the string s. 
  *    For ex :- in string s = "abace"
  *      ace => a is st 0, 2.
  *             c is at 3.
  *             e is at 4.
  *      means that the elements of ace is in same sequence as in string s.
  * 
  * Q. Now how can we approach ?
  * A. Note that the main key thing is the positions of characters in string s. If we can get that
  * we can shorten out problem.
  * 
  * 1. We will create a unordered_map<char, vector<int>> to store characters with there respective postions.
  * 2. Than we will check for each element in 'words'.
  * 3. for let's suppose "ace". we have to check 
  *               -> if a's position is in map;
  *               -> we will check the character's first occurance in Map;
  *               -> store that in a variable may be;
  *               -> than check for another character's position (last occurance / upper_bound) in map and 
  *                  follow the same pattern.
  *               -> if any of the step fails, we will return false.
  *                      
  */
 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <unordered_map>
 using namespace std;

 class Solution {
 public:
    bool isInSequence(unordered_map<char, vector<int>>& charPos, string& word) {
       int index = -1;

       for (auto ch: word) {
          if (charPos.find(ch) == charPos.end())   return false;
 
          const vector<int>& positions = charPos[ch];
 
          // check for the upper_bound : returns the next greater value than 'index'.
          auto nextPos = upper_bound(positions.begin(), positions.end(), index);   
          
          if (nextPos == positions.end())
             return false; 
 
          index = *nextPos;
       }
       return true;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
       if (s.length() == 0)   return 0;

       unordered_map<char, vector<int>> charPos;
       
       // store character ans positions in a map.
       for (int i=0; i<s.length(); i++) {
          charPos[s[i]].push_back(i);
       }

       int count = 0;
       
       for (auto ele : words) {
          if (isInSequence(charPos, ele)) {
             count++;
          }
       }
       
       return count;
    }
 };

 int main() {
    Solution sol;

   //  string s = "abcde";
   //  vector<string> words = {"a","bb","acd","ace"};
    
    string s = "dsahjpjauf";
    vector<string> words = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};

    int ans = sol.numMatchingSubseq(s, words);

    cout << "Count is : " << ans;

    return 0;
 }