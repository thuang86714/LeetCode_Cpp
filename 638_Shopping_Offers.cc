/*
In LeetCode Store, there are n items to sell. Each item has a price. However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.

You are given an integer array price where price[i] is the price of the ith item, and an integer array needs where needs[i] is the number of pieces of the ith item you want to buy.

You are also given an array special where special[i] is of size n + 1 where special[i][j] is the number of pieces of the jth item in the ith offer and special[i][n] (i.e., the last integer in the array) is the price of the ith offer.

Return the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers. You are not allowed to buy more items than you want, even if that would lower the overall price. You could use any of the special offers as many times as you want.

 

Example 1:

Input: price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
Output: 14
Explanation: There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B. 
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.*/

//a very inefficeint solution
//https://leetcode.com/problems/shopping-offers/solutions/105252/concise-c-dfs-solution-6ms/
bool operator> (const vector<int>& a, const vector<int>& b) {
    for(int i = 0; i < a.size(); ++i)
        if(a[i] < b[i]) return false;
    return true;
}

int operator* (const vector<int>& a, const vector<int>& b) {
    int res = 0;
    for(int i = 0; i < a.size(); ++i)
        res += a[i] * b[i];
    return res;
}

void operator+= (vector<int>& a, const vector<int>& b) {
    for(int i = 0; i < a.size(); ++i)
        a[i] += b[i];
    return;
}
void operator-= (vector<int>& a, const vector<int>& b) {
    for(int i = 0; i < a.size(); ++i)
        a[i] -= b[i];
    return;
}
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int cost = needs * price;
        for(auto& spe: special) {
            if(spe.back() > cost) continue;
            if(needs > spe) {
                needs -= spe;
                cost = min(cost, spe.back() + shoppingOffers(price, special, needs));
                needs += spe;
            }
        }
        return cost;
    }
};