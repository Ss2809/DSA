class Solution {
    private:
    void dfs(int i, vector<bool> &vis,vector<vector<int>>& isConnected){
        vis[i] = true;
      for(int j = 0; j < isConnected.size(); j++){
        if(isConnected[i][j] == 1 && !vis[j]){
            dfs(j, vis, isConnected);
        }
      }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        vector<bool>vis(isConnected.size(), false);
        for(int i = 0; i< isConnected.size(); i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, isConnected);
            }
        }
        return cnt;
    }
};