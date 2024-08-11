class Solution {
public:
    int m , n ;
    
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c){
        if( r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0 || visited[r][c] == 1){
            return;
        }
        visited[r][c] = true; // mark visited
        
        for(const auto& dir : directions){
            int newR = r + dir[0];
            int newC = c + dir[1];
            dfs(grid, visited, newR, newC);
        }
    }

    int numberOfIslandsDFS (vector<vector<int>>& grid){
        int islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1 && !visited[i][j]){ //land hona chahiye
                    dfs(grid, visited, i , j);
                    islands++;
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int numIslands = numberOfIslandsDFS(grid);

        if(numIslands > 1 || numIslands == 0) return 0;
        //else num of islands == 1, check if we can disconnect grid in 1 day
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0; // conver to water & now calculate num of islands
                    
                    numIslands = numberOfIslandsDFS(grid);

                    if(numIslands > 1 || numIslands == 0) return 1;

                    //make the grid back to normal that is land
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};