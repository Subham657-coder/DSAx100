class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        int cnt_max = 0;
        int row = 0;

        for (int i = 0; i < m; i++) {
            sort(mat[i].begin(),mat[i].end());
            int pos = lower_bound(mat[i].begin(), mat[i].end(), 1)- mat[i].begin();

            int cnt_ones = n - pos;

            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                row = i;
            }
        }

        return {row, cnt_max};
    }
};