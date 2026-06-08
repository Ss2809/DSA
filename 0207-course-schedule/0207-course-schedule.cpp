class Solution {
    private:
    bool CheckCycle(int node , vector<vector<int>> &adj,vector<bool> &vis, vector<bool> &recpath  ){
        vis[node] = true;
        recpath[node] = true;
        for(auto i : adj[node]){
            if(!vis[i]){
                if(CheckCycle(i, adj,vis, recpath)){
                    return true;
                }
            }else if(recpath[i]){
                return true;
            }
        }
        recpath[node] = false;
        return false;
    }
public:
    bool canFinish(int numCourses , vector<vector<int>>& prerequisites) {
       vector<vector<int>> adj(numCourses);
      
        for(auto e : prerequisites) {
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>vis(numCourses,false);
        vector<bool>recpath(numCourses,false);
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
               if(CheckCycle(i, adj, vis, recpath)){
                return false;
               }
            }
        }
        return true;
    }
};