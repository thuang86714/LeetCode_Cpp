/*Given a string s, return the longest 
palindromic substring in s.
Example:
 Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
*/
//brute time complexity O(N^3), starting from center O(N^2), Manacher Algo O(N);
//The following lines are for starting from center, space constant
//credit to lchen77
class Solution{
public:
    string longestPalindrome(string s) {
        const int size_s = s.size();
        int max_s = 0, max_l = 0;
        for (int i = 0; i < size_s;) {
            int start = i, end = i;
            while (end + 1 < size_s && s[end] == s[end+1]){
                end++;
            }
            i = end + 1;
            while (start - 1 >= 0 && end + 1 < size_s && s[start-1] == s[end+1]) {
                start--;
                end++;
            }
            if (end - start + 1 > max_l) {
                max_l = end - start + 1;
                max_s = start;
            }
        }
        return s.substr(max_s, max_l);
    }
}
    