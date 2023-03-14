/*
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

Example 1:

Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1*/
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st{bank.begin(), bank.end()};//easier to check whether endGene is in bank
        if(st.count(endGene)==0)return -1;
        queue<string> Q;
        Q.push(startGene);
        int steps = 0, qsize;
        string cur, temp;
        while(!Q.empty()){
            qsize = Q.size();
            while(qsize--){
                cur = Q.front();
                Q.pop();
                if(cur == endGene)return steps;
                //We erase the cur mutation in order to avoid redundant checking
                st.erase(cur);
                //as the length of mutation is 8 and it can take A,C,G,T
			    //at each index we check the possibility of mutation by replcaing it with A,C,G,T
                for(int i = 0; i < startGene.length(); i++){
                    temp = cur;
                    temp[i] = 'A';
                    if(st.count(temp))Q.push(temp);
                    temp[i] = 'C';
                    if(st.count(temp))Q.push(temp);
                    temp[i] = 'G';
                    if(st.count(temp))Q.push(temp);
                    temp[i] = 'T';
                    if(st.count(temp))Q.push(temp);
                }
            }
            steps++;
        }
        return -1;
    }
};