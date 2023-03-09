/*
You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

Implement the NestedIterator class:

NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the nested list nestedList.
int next() Returns the next integer in the nested list.
boolean hasNext() Returns true if there are still some integers in the nested list and false otherwise.
Your code will be tested with the following pseudocode:
initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res
If res matches the expected flattened list, then your code will be judged as correct.

Example 1:

Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].*/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begin.push(nestedList.begin());
        end.push(nestedList.end());
    }
    
    int next() {
        return (begin.top()++)->getInteger();
    }
    
    bool hasNext() {
        while(!begin.empty()){
            if(begin.top() == end.top()){
                begin.pop();
                end.pop();
            }else{
                auto it = begin.top();
                if(it->isInteger())return true;
                begin.top()++;
                begin.push(it->getList().begin());
                end.push(it->getList().end());
            }
        }
        return false;
    }
private:
    stack<vector<NestedInteger>::iterator> begin, end;
};//credit to StefanPochmann

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

//alternative:
//credit to Yash2arma
class NestedIterator {
public:
    void flatten(vector<NestedInteger> &nestedList){
        for(auto it:nestedList){
            if(it.isInteger()){
                res.push_back(it.getInteger());
            }else{
                flatten(it.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }
    
    int next() {
        return res[cur++];
    }
    
    bool hasNext() {
        return cur < res.size();
    }

private:
    int cur = 0;
    vector<int> res;
};