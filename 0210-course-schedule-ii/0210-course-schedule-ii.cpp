class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& pathVis,
             vector<int>& ans) {

        vis[node] = 1;
        pathVis[node] = 1;

        for(int next : adj[node]) {

            if(pathVis[next])
                return true;

            if(!vis[next]) {
                if(dfs(next, adj, vis, pathVis, ans))
                    return true;
            }
        }

        pathVis[node] = 0;
        ans.push_back(node);

        return false;
    }

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<int> ans;

        for(int i = 0; i < numCourses; i++) {

            if(!vis[i]) {
                if(dfs(i, adj, vis, pathVis, ans))
                    return {};
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};