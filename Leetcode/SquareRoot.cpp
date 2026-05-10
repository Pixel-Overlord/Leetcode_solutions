#include <iostream>
using namespace std;

int mySqrt(int x)
{
    int start = 0, end = x;
    int ans = 0;
    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
    
int main()
{
    int n , ans = -1;

    cout << "Enter the number : " << endl;
    cin >> n;
    ans = mySqrt(n);
    cout << "Answer is : " << ans; 
}