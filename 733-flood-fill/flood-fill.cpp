class Solution {
public:
    bool isSafe( int r, int c, vector<vector<int>>& image, int inicol){
        int n = image.size();
        int m = image[0].size();
        if(r >= 0 && r < n && c >= 0 && c < m && image[r][c] == inicol) return true;
        return false;
    }
    void bfs(int r, int c, int newcol, int inicol, vector<vector<int>>& image, vector<vector<int>>& ans){
          queue<pair<int, int>>q;
          ans[r][c] = newcol;
          q.push({r, c});
          
          while(!q.empty()){
              auto it = q.front();
              q.pop();
              int row = it.first;
              int col = it.second;
              vector<int>delr = {-1, 0 , 1, 0};
              vector<int>delc = { 0, 1, 0 ,- 1};
              for(int i = 0 ; i < 4 ; i++){
                  int newr = row + delr[i];
                  int newc = col + delc[i];
                  if(isSafe(newr, newc, image, inicol) && ans[newr][newc] != newcol){
                      bfs(newr, newc, newcol, inicol, image, ans);
                  }
              }
          }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
        vector<vector<int>>ans = image;
        int inicol = image[sr][sc];
        bfs(sr, sc, color, inicol, image, ans);
        return ans;
    }
    
/*
    bool isSafe(int r, int c, vector<vector<int>>image){
        int n = image.size();
        int m = image[0].size();
        if(r >= 0 && r < n && c >= 0 && c < m) return true;
        return false;
    }

    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, int newcolor, int initialCol){
         
        ans[row][col] = newcolor;
        vector<int> delr = {-1, 0, 1, 0};
        vector<int> delc = {0, 1, 0 , -1};

        for(int i = 0 ; i < 4 ; i++){
            int newr = row+delr[i];
            int newc = col+delc[i];
            if(isSafe(newr, newc, image) && image[newr][newc] == initialCol && ans[newr][newc] != newcolor){
                dfs(newr, newc, image, ans, newcolor, initialCol);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>ans = image;
        int initialCol = image[sr][sc];

       dfs(sr, sc, image, ans, color, initialCol);
       return ans;  
    }
    */
};