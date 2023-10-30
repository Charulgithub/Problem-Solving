class Solution {
public:
    int checkPal ( int i , int j , string& s, vector<vector<int>>& dp){
        if( i >= j) return 1;
        if( dp[i][j] != -1) return dp[i][j];

        if( s[i] == s[j] && checkPal(i+1, j-1, s, dp)) return dp[i][j] = 1;
        else return 0;
    }
    int countSubstrings(string s) {
        int cnt = 0 ; 
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        for( int i = 0 ; i < s.size() ; i++){
            for(int j = i ; j < s.size() ; j++){
                cnt += checkPal ( i, j, s, dp);
            }
        }
        return cnt;
    }
};