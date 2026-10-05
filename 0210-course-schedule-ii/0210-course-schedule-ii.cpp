class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& pathVis,
             stack<int>& st) {

        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]) {

            // If node is not visited
            if(!vis[it]) {
                if(dfs(it, adj, vis, pathVis, st)) {
                    return true;
                }
            }

            // Cycle detected
            else if(pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        st.push(node);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        // Build graph
        for(auto it : prerequisites) {
            int course = it[0];
            int prerequisite = it[1];

            adj[prerequisite].push_back(course);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        stack<int> st;

        // DFS for every component
        for(int i = 0; i < numCourses; i++) {

            if(!vis[i]) {
                if(dfs(i, adj, vis, pathVis, st)) {
                    return {};
                }
            }
        }

        vector<int> ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};