class Solution {
public:
     
  string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    int lenLPsubstr = 0;
    int startIdx = 0;  // Store the starting index of the longest palindromic substring.

    for (int gap = 0; gap < n; gap++) {
        for (int start = 0; start + gap < n; start++) {
            int end = start + gap;
            if (gap == 0) {  // Length = 1 --> 1 char
                dp[start][end] = true;
            } else if (gap == 1) {  // Length = 2 --> 2 char
                if (s[start] == s[end]) {
                    dp[start][end] = true;
                    startIdx = start;  // Update the starting index for length 2 palindrome.
                }
            } else {
                if (s[start] == s[end] && dp[start + 1][end - 1]) {
                    dp[start][end] = true;
                    startIdx = start;  // Update the starting index for longer palindromes.
                }
            }
            if (dp[start][end] && gap + 1 > lenLPsubstr) {
                lenLPsubstr = gap + 1;
            }
        }
    }
    return s.substr(startIdx, lenLPsubstr);
}


  /*  
  string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int lenLPsubstr = 0;
    int startIdx = 0;

    for (int gap = 0; gap < n; gap++) {
        for (int start = 0; start + gap < n; start++) {
            int end = start + gap;
            if (gap == 0) {
                dp[start][end] = true;
            } else if (gap == 1) {
                if (s[start] == s[end]) dp[start][end] = true;
            } else {
                if (s[start] == s[end] && dp[start + 1][end - 1]) dp[start][end] = true;
            }
            if (dp[start][end] && gap + 1 > lenLPsubstr) {
                lenLPsubstr = gap + 1;
                startIdx = start;
            }
        }
    }
    return s.substr(startIdx, lenLPsubstr);
}
*/


    // string longestPalindrome(string s) {
    //     int n = s.size();
    //     vector<vector<bool>>dp(n, vector<bool>(n));
    //     int lenLPsubstr = 0;
    //     for(int gap = 0; gap<n; gap++){
    //         for(int start =0; end =gap; end<n; start++; end++){
    //             if(gap==0){  //len =1 -->1 char
    //                 dp[start][end] = true;
    //             }else if(gap==1){  // len = 2 -->2 char
    //                 if(s[start]==s[end]) dp[start][end] = true;
    //                 else dp[start][end] = false;
    //             }else{
    //                 if(s[start]==s[end] && dp[start+1][end-1]==true) dp[start][end] = true;
    //                 else dp[start][end] = false;
    //             }
    //             if(dp[start][end]) lenLPsubstr = gap+1;
    //         }
    //     }
    //     return lenLPsubstr;
    // }
};