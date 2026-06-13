class Solution {
public:
    int minDist(vector<vector<int>>& points, int p1, int p2) {
        return abs(points[p1][0] - points[p2][0]) +
               abs(points[p1][1] - points[p2][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<bool> inMST(points.size(), false);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0}); // wt, node
        int minCost = 0;
        while (!pq.empty()) {
            auto [wt, temp] = pq.top();
            pq.pop();
            if (inMST[temp]) {
                continue;
            }
            inMST[temp] = true;
            minCost += wt;
            for (int i = 0; i < points.size(); i++) {
                if (!inMST[i]) {
                    int wt = minDist(points, temp, i);
                    pq.push({wt, i});
                }
            }
        }
        return minCost;
    }
};