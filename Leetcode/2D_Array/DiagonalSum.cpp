/* Calculate diagonal sum of a 2-D array. The diagonal sum of the array must have summation of both primary and secondary diagonals.
 * 
 * A PRIMARY diagonal is a diagonal formed with elements at positions such as (0,0), (1,1), (2,2), (3,3)....(n-1,n-1).
 * 
 * A SECONDARY diagonal is a diagonal formed with elements at positions such as (0,n-1), (1,n-2), (2,n-3), (3,n-4)....(n-1,n-1)).
 * 
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 class Solution {
    public:
        // O(n)2 time complexity.
        void sumDiagOn2(vector<vector<int>>& matrix, int n, int& sum) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (i == j) {
                        sum += matrix[i][j];
                    }
                    else if (j==n-1-i){
                        sum += matrix[i][j];
                    }
                }
            }
            return ;
        }

        // O(n) time complexity.
        void sumDiagOn(vector<vector<int>>& matrix, int n, int& sum) {
            for (int i=0; i<n; i++) {
                sum += matrix[i][i];

                if (i != n-1-i)
                {
                    sum += matrix[i][n-1-i];
                }
            }
            return ;
        }
 };

 int main(){
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};    
    int n = matrix.size(), sum = 0; // note: here matrix.size will return no. of rows.

    Solution sol;
    //sol.sumDiagOn2(matrix, n, sum);
    sol.sumDiagOn(matrix, n, sum);
    cout << "The diagonal sum is : " << sum;
 }