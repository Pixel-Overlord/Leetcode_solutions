/* 
 * 49. Group Anagrams
 * 
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 * 
 *  
 * 
 * Example 1: 
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 * Explanation:
 * 
 * There is no string in strs that can be rearranged to form "bat".
 * The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
 * The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
 * 
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * 
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 */

 #include <iostream>
 #include <vector>
 #include <unordered_map>
 #include <algorithm>
 using namespace std;

 class Solution {
 public:
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
         if (strs.size() == 0) return {};
         
         unordered_map<string,vector<string>> m;
         vector<vector<string>> ans;

         for (int i=0; i<strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());

            m[str].push_back(strs[i]);
         }

         for (auto a: m) {
            ans.push_back(a.second);
         }

         return ans;
     }
 };

 int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    Solution sol;
    vector<vector<string>> ans = sol.groupAnagrams(strs);

    for (auto a: ans) {
        for (auto b: a) {
            cout << b << " ";
        }
        cout << endl;
    }

    return 0;
 }