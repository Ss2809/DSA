class Solution {
private:
    bool dfs(int src, vector<bool>& vis, vector<bool>& recpath,
             vector<vector<int>>& prerequisites) {
        vis[src] = true;
        recpath[src] = true;
        for (auto i : prerequisites[src]) {
            if (!vis[i]) {
                if (dfs(i, vis, recpath, prerequisites)) {
                    return true;
                }
            }

            else if (recpath[i]) {
                return true;
            }
        }
        recpath[src] = false;
        return false;
    }
    void dfsTOPO(int node, vector<vector<int>>& adj, vector<bool>& visited,
             stack<int>& st) {
        visited[node] = true;

        for (auto i : adj[node]) {
            if (!visited[i]) {
                dfsTOPO(i, adj, visited, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        vector<bool> vis(n, false);
        vector<bool> recpath(n, false);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                if (dfs(i, vis, recpath, adj)) {
                    return ans;
                }
        }

        // part 2

        vector<bool> visited(n, false);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfsTOPO(i, adj, visited, st);
            }
        }
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            ans.push_back(top);
        }
        return ans;
    }
};