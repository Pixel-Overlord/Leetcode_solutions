// 344. Reverse String
// Write a function that reverses a string. The input string is given as an array of characters s.
// You must do this by modifying the input array in-place with O(1) extra memory.
//
// Example 1:
//
// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) 
{
    int start = 0, end = s.size() - 1;
    char temp;
    while (end > start)
    {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        start++;
        end--;
    }

    for (char c : s)
    {
        cout << c << " ";
    }
}

int main ()
{
    int size, target;
    cout << "Enter the size of string :" << endl;
    cin >> size;

    vector<char> s(size);
    cout << "Enter the elements :" << endl;
    
    for (char &c : s)
    {
        cin >> c;
    }

    reverseString (s);
}