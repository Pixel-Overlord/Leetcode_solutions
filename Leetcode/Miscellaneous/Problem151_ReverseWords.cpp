/* 
 * 151. Reverse Words in a String
 * 
 * Given an input string s, reverse the order of the words.
 * A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
 * 
 * Return a string of the words in reverse order concatenated by a single space.
 * 
 * Note that s may contain leading or trailing spaces or multiple spaces between two words. 
 * The returned string should only have a single space separating the words. Do not include any extra spaces.
 * 
 * Example 1:
 * 
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 * 
 * Example 2:
 * 
 * Input: s = "  hello world  "
 * Output: "world hello"
 * Explanation: Your reversed string should not contain leading or trailing spaces.
 */

 #include <iostream>
 #include <string>
 #include <vector>
 using namespace std;

 class Solution {
 public:
     string reverseWords(string s) {
         vector<string> ans;
         int n = s.length(), i=0;

         string word = " ";
         while (i <= n)
         {
             if (s[i] == ' ' || i == n)
             {
                if (word != " ")
                    ans.push_back(word);
                word = " ";
                i++;
                continue;
             }
             word += s[i];
             i++;
         }
         string revStr = "";
         for (int i=ans.size()-1; i>=0; i--)
         {
            revStr += ans[i];
         }
         return revStr.substr(1);
     }
 };   
 
 int main()
 {
    Solution sol;
    string s, ans;
    cout << "Enter line : " << endl ;
    getline(cin,s);

    cout << "Output is : " << endl;
    ans = sol.reverseWords(s);
    cout << ans;
 }