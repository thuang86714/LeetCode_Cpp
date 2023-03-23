/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.*/
//https://leetcode.com/problems/network-delay-time/solutions/109982/c-bellman-ford/
//credit to alexander
//Bellman-Ford
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        for(int i = 0; i < n; i++){
            for(vector<int> t:times){
                int u = t[0], v = t[1], w = t[2];
                if(dist[u] != INT_MAX && dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                }
            }
        }

        int maxwait = 0;
        for(int i = 1; i < n+1; i++){
            maxwait = max(maxwait, dist[i]);
        }
        return maxwait == INT_MAX? -1: maxwait;
    }
};