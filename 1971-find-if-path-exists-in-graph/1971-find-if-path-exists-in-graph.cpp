class Solution {
public:

    bool solve(int node, int dest, vector<int> adj[], vector<int> &vist){

        if(node == dest)
            return true;

        vist[node] = 1;

        for(auto i : adj[node]){

            if(!vist[i]){
                if(solve(i, dest, adj, vist))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<int> adj[n];

        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vist(n,0);

        return solve(source, destination, adj, vist);
    }
};