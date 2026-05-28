/* 
 * 131. Palindrome Partitioning
 * Medium
 * Topics
 * premium lock icon
 * Companies
 * Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * 
 * Example 2:
 * 
 * Input: s = "a"
 * Output: [["a"]]
 */

 #include <iostream>
 #include <vector>
 #include <string>
 using namespace std;

 class Solution {
 public:
     bool isPalindrome(string s) {
        int start = 0, end = s.length() - 1;
        while (start <= end){
            if (s[start] != s[end]){
                return false;
            }
            start ++;
            end--;
        }
        return true;
     }

     void partitionHelper(string s, vector<vector<string>>& ans, vector<string>& ele) {
        // recursive condition
        if (s.size() == 0) {
            ans.push_back(ele);
            return;
        }

        // we have to increase the substring for each iteration
        for (int i=0; i<s.length(); i++) {
            string subString = s.substr(0,i+1);

            if (isPalindrome(subString)) {
                ele.push_back(subString);

                partitionHelper(s.substr(i+1), ans, ele);

                ele.pop_back();
            }
        }
     }

     vector<vector<string>> partition(string s) {
         vector<vector<string>> ans;
         vector<string> ele;

         partitionHelper (s, ans, ele);

         return ans;
     }
 };

 int main(){
    string s = "aab";

    Solution sol;
    vector<vector<string>> ans = sol.partition(s);

    for (auto a: ans){
        for (auto b: a){
            cout << b << " ";
        }
        cout << endl;
    }
 }