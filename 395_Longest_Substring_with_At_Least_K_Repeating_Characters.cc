/*
of s such that the frequency of each character in this substring is greater than or equal to k.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.*/
//https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/solutions/87736/c-recursive-solution/
//credit to james348021012 && garygao1993

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();

        unordered_map<char, int> count;

        for(char c: s){
            count[c]++;
        }

        int mid = 0;
        while(mid < n && count[s[mid]] >= k){
            mid++;
        }

        if(mid == n)return n;
        int left = longestSubstring(s.substr(0, mid), k);

        if(mid == n)return left;
        while(mid < n && count[s[mid]] < k){
            mid++;
        }
        int right = longestSubstring(s.substr(mid), k);
        return max(left, right);
    }
};

class Solution {
public:
    int longestSubstring(string s, int k) {
        int start, end, uniqueChar, nolessthanK, maximum = 0, idx;
        vector<int> count(26);
        for(int i = 1; i < 26; i++){
            fill(count.begin(), count.end(), 0);
            start = 0;
            end = 0; 
            uniqueChar = 0;
            nolessthanK = 0;
            while(end < s.length()){
                if(uniqueChar <= i){
                    idx = s[end] - 'a';
                    if(count[idx]==0)uniqueChar++;
                    count[idx]++;
                    if(count[idx]==k)nolessthanK++;
                    end++;
                }else{
                    idx = s[start] - 'a';
                    if(count[idx] == k)nolessthanK--;
                    count[idx]--;
                    if(count[idx] == 0)uniqueChar--;
                    start++;
                }
                if(uniqueChar == i && uniqueChar == nolessthanK){
                    maximum = max(maximum, end - start);
                }
            }
        }
        return maximum;

    }
};