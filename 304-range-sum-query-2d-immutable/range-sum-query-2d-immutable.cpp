class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(); // row
        int m = matrix[0].size(); // col
        if(n == 0 || m == 0) return;

        dp.assign(n+1, vector<int>(m+1, 0));

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                dp[r+1][c+1] = dp[r+1][c] + dp[r][c+1] - dp[r][c] + matrix [r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2+1]-dp[row2+1][col1]+dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */