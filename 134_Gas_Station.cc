/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

 

Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //the brute force solution, time complexity would be O(N^2)
        //here we will use Greedy Algo, whose time complexity would be O(N), space complexity would be O(1)
        //there's one key fact we will leverage here: if there's solution, there would be exact one sol
        //first of all, we need to know the sum
        int gasSum = 0, costSum = 0;
        for (int i = 0; i < gas.size(); i++){
            gasSum += gas[i];
            costSum += cost[i];
        }
        if (gasSum < costSum)return -1;//if not, there must be one solution
        int diff = 0;
        int index = 0;
        for (int i = 0; i < gas.size(); i++){
            diff += (gas[i] - cost[i]);
            if (diff < 0){
                diff = 0;
                index = i+1;
            }
        }
        return index;
    }
};