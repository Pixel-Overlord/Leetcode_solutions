/* 
 * 443. String Compression

 * Given an array of characters chars, compress it using the following algorithm:
 * 
 * Begin with an empty string s. For each group of consecutive repeating characters in chars:
 * 
 * If the group's length is 1, append the character to s.
 * Otherwise, append the character followed by the group's length.
 * The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
 * 
 * After you are done modifying the input array, return the new length of the array.
 * 
 * You must write an algorithm that uses only constant extra space.
 * 
 * Note: The characters in the array beyond the returned length do not matter and should be ignored.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: chars = ["a","a","b","b","c","c","c"]
 * Output: 6
 * Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
 */

 #include <iostream>
 #include <vector>
 #include <string>
 using namespace std;

 class Solution{
 public:
    int compress(vector<char>& chars) {
        int pos = 0;
        int n = chars.size();

        for (int i=0; i<chars.size();){
            int count = 0;
            char ch = chars[i];

            // check for occurances
            while (i < n && chars[i] == ch){
                count++;
                i++;
            }

            chars[pos++] = ch; 

            if (count > 1){
                string countInString = to_string(count);

                for (char c:countInString){
                    chars[pos++] = c;
                }
            }
        }
        // remove remaining elements
        chars.erase(chars.begin() + pos, chars.end());

        return chars.size();
    }
 };

 int main(){
    Solution sol;
    vector<char> chars = {'a','a','b','b','c','c','c'};
    int newSize = sol.compress(chars);

    cout << "Updated size is : " << newSize;
 }