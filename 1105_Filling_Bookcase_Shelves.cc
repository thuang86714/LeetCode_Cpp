/*
You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.

We want to place these books in order onto bookcase shelves that have a total width shelfWidth.

We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are no more books to place.

Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.

For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.
Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.*/
//https://leetcode.com/problems/filling-bookcase-shelves/solutions/323305/dfs-memo/
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size()+1, INT_MAX);
        dp[0]= 0;
        for(int p = 1; p <= books.size();p++){
            int h = 0, w = 0;
            for(int i = 1; i <= p&& w + books[p-i][0] <= shelfWidth;i++){
                w += books[p - i][0];
                h = max(h, books[p - i][1]);
                dp[p] = min(dp[p], dp[p - i]+h);
            }
        }
        return dp.back();
    }
};