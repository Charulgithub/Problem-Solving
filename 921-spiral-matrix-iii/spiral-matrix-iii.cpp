class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions = {
                                     {0,1},//east
                                     {1,0},//south
                                     {0,-1},//west
                                     {-1,0}//north
                                  };
        vector<vector<int>>result;

        int steps = 0;//steps to take in dir dirn
        int dir = 0; //in east dirn initially

        result.push_back({rStart,cStart});

        while( result.size() < rows*cols){
            if( dir == 0 || dir == 2) { //east || west
                steps++;
            }
            for( int countOfSteps = 0; countOfSteps < steps; countOfSteps++){
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart <cols){ //valid cell
                    result.push_back({rStart,cStart}); 
                }
            }
            dir = (dir+1)%4;
        }
      return result;
    }
};