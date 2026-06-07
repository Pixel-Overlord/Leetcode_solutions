/* 
 * 187. Repeated DNA Sequences
 * 
 * The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
 * 
 * For example, "ACGAATTCCG" is a DNA sequence.
 * When studying DNA, it is useful to identify repeated sequences within the DNA.
 * 
 * Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * Output: ["AAAAACCCCC","CCCCCAAAAA"]
 * Example 2:
 * 
 * Input: s = "AAAAAAAAAAAAA"
 * Output: ["AAAAAAAAAA"]
 */

 #include <iostream>
 #include <vector>
 #include <unordered_map>
 using namespace std;

 class Solution {
 public:
     vector<string> findRepeatedDnaSequences(string s) {
         unordered_map<string, int> ansMap; 
         vector<string> ans;
         string subString;

         if (s.length() < 10)   return {};

         for (int right = 0; right <= s.length() - 10; right++) {

            subString = s.substr(right, 10);
            ansMap[subString] ++;
         }

         for (auto a : ansMap) {
            if (a.second > 1) 
                ans.push_back(a.first);
         }

         return ans;
     }
 };

 int main() {
     Solution sol;
 
     string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
     vector<string> ans = sol.findRepeatedDnaSequences(s);
 
     for (auto a : ans) {
         cout << a << " ";
     }
     return 0;
 }