class Solution {
public:
    vector<vector<int>> directions {{0,1}, {1,0}, {0, -1}, {-1, 0}};

    void dfs( vector<vector<int>>& matrix, int i ,int j){
        if( i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == 1){
            return;
        }
        matrix[i][j] = 1; //else marked visited now

        for(const auto& dir : directions) {
            int newR = i + dir[0];
            int newC = j + dir[1];
            dfs ( matrix , newR, newC);
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int regions = 0;
        vector<vector<int>>matrix( rows*3, vector<int>(cols*3, 0));
//populating the matrix with the defined notations from the grid '/ and '\\'       
         for( int i = 0 ; i < rows; i++){
            for(int j = 0 ; j < cols; j++){
                if(grid[i][j] == '/'){
                    matrix[i*3][j*3 + 2] = 1;
                    matrix[i*3 + 1][j*3 + 1] = 1;
                    matrix[i*3 + 2][j*3] = 1;

                } else  if(grid[i][j] == '\\'){
                        matrix[i*3][j*3] = 1;
                        matrix[i*3 + 1][j*3 + 1] = 1;
                        matrix[i*3 + 2][j*3 + 2] = 1;
                    }
                }
            }
            //apply dfs now as the matrix is populated with the similar logic of number of islands
            for( int i = 0 ; i < matrix.size() ; i++){
                for(int j = 0 ; j < matrix[0].size() ; j++){
                    if( matrix[i][j] == 0){ //call dfs
                        dfs(matrix, i , j);
                        regions++;
                    }
                }
            }
        return regions;
    }
};