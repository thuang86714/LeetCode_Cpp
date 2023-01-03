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
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.length();
        string res ="";
        int len= 0;
        for (int i= 0; i < size; i++){
            int l =i;
            int r =i;
            while (l >=0 && r< size && s[l]==s[r]){//for odd length
                if ((r-l +1) > len){
                    res = s.substr(l, r-l+1);
                    len = r-l +1;
                }
                l -=1;
                r +=1;
            }
            l = i, r = i+1;
            while(l >=0 && r< size && s[l]==s[r]){//for even length
                if (r-l +1 > len){
                    res = s.substr(l, r-l+1);
                    len = r-l +1;
                }
                l -=1;
                r +=1;
            }
        }
        
        return res;
    }
};
    