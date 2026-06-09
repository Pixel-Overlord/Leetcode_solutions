/* 
 * 9. Palindrome Number
 * 
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 * 
 * 
 * Example 1:
 * 
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 * Example 2:
 * 
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 * Example 3:
 * 
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 */

 #include <iostream>
 using namespace std;

 class Solution {
 public:
     bool isPalindrome(int x) {
         if (x < 0)
             return false;
 
         int temp = x;
         long long rem = 0, sum = 0;
         
         while (x > 0) {
             rem = x % 10;
             sum = (sum * 10) + rem;
             x /= 10;
         }
 
         if (sum == temp) {
             return true;
         }
         return false;
     }
 };

 int main() {
     Solution sol;
     int n = 1221;

     bool ans = sol.isPalindrome(n);
     cout << "The number " << n << " is Palindrome : " << ans;
 }