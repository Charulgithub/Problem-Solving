class Solution {
public:
  int n;
int WIDTH;

int solve(int ind, int remainW, int maxH, vector<vector<int>>& books, vector<vector<int>>& dp) {
    if (ind >= n) {
        return maxH;
    }

    if (dp[ind][remainW] != -1) {
        return dp[ind][remainW];
    }

    int bookW = books[ind][0];
    int bookH = books[ind][1];

    int keep = INT_MAX;
    int skip = INT_MAX;

    // Keep the book on the current shelf
    if (bookW <= remainW) {
        keep = solve(ind + 1, remainW - bookW, max(maxH, bookH), books, dp);
    }
    // Skip to the next shelf
    skip = maxH + solve(ind + 1, WIDTH - bookW, bookH, books, dp);

    return dp[ind][remainW] = min(keep, skip);
}

int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    n = books.size();
    WIDTH = shelfWidth;

    vector<vector<int>> dp(n, vector<int>(WIDTH + 1, -1));

    int remainW = shelfWidth;
    return solve(0, remainW, 0, books, dp);
}
};