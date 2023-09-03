class Solution {
public:
     int uniquePaths(int m, int n){
         vector<vector<int>>dp(m, vector<int>(n, 0));

         for(int row = 0; row<m; row++) dp[row][0] = 1;
         for(int col = 0; col<n; col++) dp[0][col] = 1;
         
         for(int row = 1; row<m; row++){
             for(int col = 1; col<n; col++){
                 dp[row][col] = dp[row-1][col] + dp[row][col-1];
             }
         }
         return dp[m-1][n-1];
     }
     
/*
    int solve(int row, int col, vector<vector<int>>&dp){
         if (row==0 && col==0) return 1;
         if(row<0 || col<0) return 0;
         if(dp[row][col] != -1) return dp[row][col];
         int up = solve (row-1, col, dp);
         int left = solve (row, col-1, dp);

         return up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, dp);
    }
    */
};