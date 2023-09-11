#include <algorithm>
using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // Since cells can be visited multiple times, we only need to consider lower bound.
        int xdiff = abs(sx - fx);
        int ydiff = abs(sy - fy);
        int lower = max(xdiff, ydiff);
        // Edge case to consider.
        if(xdiff == ydiff && xdiff == 0){
            return t!= 1;
        }
        return t >= lower;    
    }
};