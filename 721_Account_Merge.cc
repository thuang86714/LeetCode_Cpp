/*
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.*/
class Solution {
    vector<int> par;
    
    int find(int nodeid) { 
        // par[nodeid] == nodeid is the leader, representative of the group
        if (par[nodeid] != nodeid)
            par[nodeid] = find(par[nodeid]);  // set the ancestor
        
        return par[nodeid];
    }
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Union-find every user other than every email, this is the key, it is much faster than union-find emails
        // The complexity should be O(A n), O(A log n) (union by rank), or O(A \alpha(n)) (path compression), where n is size of accounts
        par = vector<int>(accounts.size()); 
        unordered_map<string, int> em2id;  // email to union-find id, so we can easily group it
        
        for (int i = 0; i < accounts.size(); ++i) {
            par[i] = i;  // init union-find
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (em2id.find(accounts[i][j]) != em2id.end())  // this email already seen, so union this i with previous seen
                    par[find(em2id[accounts[i][j]])] = find(i);
                else  // this email not seen, we set it point to parent of i
                    em2id[accounts[i][j]] = par[i];
            }
        }
        
        unordered_map<int, vector<string>> newaccs;
        for (auto &e: em2id)  // group by union-find set
            newaccs[find(e.second)].emplace_back(e.first);
        
        vector<vector<string>> res;  // construct result
        for (auto &a: newaccs) {
            auto &emails = a.second;
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[a.first][0]);
            res.emplace_back(emails);
        }
        return res;
    }
};