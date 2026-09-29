class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (!vis[i][j]){
                    if (dfs(i,j,-1,-1,vis,grid)){
                        return true;
                    }
                }
            }
            
        }
        return false;
    }
    bool dfs(int row,int col,int prow,int pcol,vector<vector<int>>& vis,vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m) {
                if(grid[nrow][ncol] != grid[row][col])  
                    continue;  //Checking the element and the neighbouring elements are same or not

                if (!vis[nrow][ncol]){
                    if(dfs(nrow, ncol, row, col, vis, grid)) return true;
                }

                else if(nrow != prow || ncol != pcol) {
                    return true; //Checking that if its already visited then its parent or not..if not parent then it forms a cycle because that node is already visited by other.
                }
            }
        }
        return false;
    }
};