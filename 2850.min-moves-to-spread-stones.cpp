#include <vector>
using namespace std;

/*
Notice for this problem the greedy solution. (BFS and take min dist won't work)

As once you take a stone from nearest neighbor, you could end up having to  move a stone from really far away in a later step.

*/
class Solution {
   public:
    int minimumMoves(vector<vector<int>>& grid) {
        num_rows = grid.size();
        num_cols = grid[0].size();
        return back_track(grid);
    }

   private:
    int num_rows, num_cols;

    int back_track(vector<vector<int>>& grid){
        bool has_zero = false;
        int moves = INT_MAX;
        for(int i = 0; i < num_rows; ++i){
            for(int j = 0; j < num_cols; ++j){
                if(grid[i][j] != 0){
                    continue;
                }
                has_zero = true;
                for(int m = 0; m < num_rows; ++m){
                    for( int n = 0; n < num_cols; ++n){
                        if(grid[m][n] > 1){
                            int dist = abs(m-i) + abs(n - j);
                            grid[i][j]++;
                            grid[m][n]--;
                            moves = min(dist + back_track(grid), moves);
                            grid[i][j]--;
                            grid[m][n]++;
                        }
                    }
                }
            }
        }
        if(!has_zero){
            return 0;
        }else{
            return moves;
        }
    }
};