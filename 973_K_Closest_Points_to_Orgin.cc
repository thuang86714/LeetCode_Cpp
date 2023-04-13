/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        for(auto point:points){
            pq.push({pow(point[0], 2)+pow(point[1], 2),{point[0], point[1]}});
        }
        while(pq.size() > k)pq.pop();
        vector<vector<int>> result;
        while(pq.size() > 0){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            vector<int> temp{x, y};
            result.emplace_back(temp);
        } 
        return result;
    }
};