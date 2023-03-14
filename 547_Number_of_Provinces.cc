/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //the key is the indirectly connected part
        int n = isConnected.size();
        vector<int> bossOf(n, 0);
        for(int i = 0; i < n; i++){
            bossOf[i] = i;
        }
        int numOfProv = n;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(isConnected[i][j] > 0){
                    int master1 = findProvinceMaster(i, bossOf);
                    int master2 = findProvinceMaster(j, bossOf);
                    if(master1 != master2){
                        bossOf[master2] = master1;
                        numOfProv--;
                    }
                }
            }
        }
        return numOfProv;
    }
private:
    int findProvinceMaster(int x, vector<int> bossOf){
        return bossOf[x] == x? x:findProvinceMaster(bossOf[x], bossOf);
    }
};