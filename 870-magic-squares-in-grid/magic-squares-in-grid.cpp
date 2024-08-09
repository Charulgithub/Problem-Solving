class Solution {
public:
    
    bool isMagicGrid(vector<vector<int>>& grid, int r, int c){
        //1st step->check uniqueness of elements in grid
        unordered_set<int>s;
        for( int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(grid[r+i][c+j] < 1 || grid[r+i][c+j] > 9 || s.count(grid[r+i][c+j])){
                    return false;
                } else {
                    s.insert(grid[r+i][c+j]);
                }
            }
        }
        //2nd step col & row sum
        int Rsum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        for( int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if( grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != Rsum) return false;
                if( grid[r][c+j] + grid[r+1][c+j] + grid[r+2][c+j] != Rsum) return false;
            }
        }
        if((grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2]) != Rsum) return false;
        if((grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c]) != Rsum) return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        
        for( int i = 0 ; i <= rows-3 ; i++){
            for( int j = 0 ; j <= cols-3 ; j++){
                if(isMagicGrid( grid, i , j)){
                    count++;
                }
            }
        }
        return count;
    }
};