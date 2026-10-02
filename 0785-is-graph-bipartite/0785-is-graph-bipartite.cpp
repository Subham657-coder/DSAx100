//0 means no colour...1 means first colour...-1 means the second color
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        for(int i = 0; i < n; i++) {
            if(color[i] == 0) {
                queue<int> q;
                q.push(i);
                color[i] = 1;

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for(auto it : graph[node]) {
                        if(color[it] == 0) {
                            color[it] = -color[node]; 
                            q.push(it);
                        }
                        else if(color[it] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};