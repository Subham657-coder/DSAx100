class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {

        int n = properties.size();

        // Convert every property array into a set
        vector<unordered_set<int>> st(n);

        for(int i = 0; i < n; i++) {
            for(int x : properties[i]) {
                st[i].insert(x);
            }
        }

        // Build graph
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                int common = 0;

                for(auto x : st[i]) {
                    if(st[j].count(x)) {
                        common++;
                    }
                }

                if(common >= k) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Count connected components
        vector<int> vis(n, 0);

        int components = 0;

        for(int i = 0; i < n; i++) {

            if(!vis[i]) {
                dfs(i, adj, vis);
                components++;
            }
        }

        return components;
    }
};