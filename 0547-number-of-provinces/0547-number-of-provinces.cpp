class Solution {
public:
    void slove(int start, vector<int> &vis, vector<vector<int>>& isConnected) {
       vis[start] = 1;

        for (int j = 0; j < isConnected.size(); j++) {

            if (isConnected[start][j] == 1 && !vis[j]) {
                slove(j, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>vis(n,0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                slove(i, vis, isConnected);
            }
        }
        return ans;
    }
};