/*
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

 

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"*/
//https://leetcode.com/problems/replace-words/solutions/1704741/c-simplest-intuitive-solution-trie/
//credit to LeetCoderMy3
class TrieNode{
public:
    TrieNode *child[26];
    bool isEnd;
    TrieNode(){
        this->isEnd = false;
        for(int i = 0; i < 26; i++)this->child[i] = NULL;
    }
};
class Solution {
    TrieNode *Root;
public:
    string check(string word){
        TrieNode *t = Root;
        string s = "";
        
        for(auto i : word){
            if(!t->child[i-'a']) break;
            s += i;
            t = t->child[i-'a'];
            if(t->isEnd) return s;
        }
        return word;
    }

    void insert(string s){
        TrieNode *temp = Root;
        for(auto c:s){
            if(!temp->child[c - 'a'])temp->child[c - 'a'] = new TrieNode();
            temp = temp->child[c - 'a'];
        }
        temp->isEnd = true;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        Root = new TrieNode();
        for(auto str: dictionary)insert(str);
        istringstream ss(sentence);
        string word = "", ans = "";
        for(;ss >> word;){//The extraction operator will read until whitespace is reached or until the stream fails.
            ans += check(word);
            ans += ' ';
        }
        ans.pop_back();//there would be one extra " " at the end of the ans;
        return ans;
    }
};