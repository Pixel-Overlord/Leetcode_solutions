/* 
 * 50. Pow(x, n)
 * 
 * Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
 * 
 * 
 * Example 1:
 * 
 * Input: x = 2.00000, n = 10
 * Output: 1024.00000
 * Example 2:
 * 
 * Input: x = 2.10000, n = 3
 * Output: 9.26100
 * Example 3:
 * 
 * Input: x = 2.00000, n = -2
 * Output: 0.25000
 * Explanation: 2-2 = 1/22 = 1/4 = 0.25
 */

 // we will play on bits of power.
 #include <iostream>
 #include <vector>
 using namespace std;

 class Solution {
 public:
    double myPow(double x, int n) {
        double prod = 1.0;
        while (n > 0) {
            if (n%2 == 1) {
                prod = prod * x;
            }
            x = x*x;
            n = n/2;
        }

        return prod;
    }
 };

 int main() {
    double x = 2.0000;
    int power = 10;

    Solution sol;
    double ans = sol.myPow(x,power);

    cout << "Ans to " << x << " to the power " << power << " is " << ans;
 }