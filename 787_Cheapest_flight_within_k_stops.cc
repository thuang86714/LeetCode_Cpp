/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/
class Solution {//Bellman-Ford
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, 1e8);
        cost[src] = 0;
        for(int i = 0; i <= k; i++){
            vector<int> temp(cost);
            for(auto flight: flights){
                temp[flight[1]] = min(temp[flight[1]], cost[flight[0]] + flight[2]);
            }
            cost = temp;
        }
        return cost[dst] == 1e8? -1:cost[dst];
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> pn;
        pn.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src] = 0;
        while(!pn.empty()){
            auto front = pn.front();
            pn.pop();
            int stops = front.first;
            int node = front.second.first;
            int distance = front.second.second;
            if(stops>k)continue;
            for(auto it:adj[node]){
                int adjnode = it.first;
                int d = it.second;
                if(distance + d<dist[adjnode]&&stops<=k){
                    dist[adjnode] = distance + d;
                    pn.push({stops+1,{adjnode,distance+d}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //Dijkstra
        vector<pair<int, int>> adj[n];//equal to vecotr<vector<pair<int, int>>> adj(n)
        for(auto flight: flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        queue<pair<int, pair<int, int>>> pending;//{stop, {src_stop, cost}}
        pending.push({0, {src, 0}});
        vector<int> cost(n, 1e8);
        cost[src] = 0;
        while(!pending.empty()){
            auto front = pending.front();
            pending.pop();
            int stops = front.first;
            int node = front.second.first;
            int dist = front.second.second;
            if(stops > k)continue;
            for(auto it: adj[node]){
                int adjnode = it.first;
                int d = it.second;
                if(dist + d < cost[adjnode] && stops <= k){
                    cost[adjnode] = dist + d;
                    pending.push({stops+1, {adjnode, dist + d}});
                }
            }
        }
        return cost[dst] == 1e8? -1:cost[dst];
    }
};