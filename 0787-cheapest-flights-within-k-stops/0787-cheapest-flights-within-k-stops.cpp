class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int,pair<int,int>>> pq;
        // node, {cost, stops}

        pq.push({src,{0,0}});

        while(!pq.empty()){

            auto curr = pq.front();
            pq.pop();

            int node = curr.first;
            int cost = curr.second.first;
            int cnt  = curr.second.second;

            if(cnt > k) continue;

            for(auto i : adj[node]){

                int v = i.first;
                int wt = i.second;

                if(cost + wt < dist[v]){

                    dist[v] = cost + wt;

                    pq.push({v,{dist[v],cnt+1}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};