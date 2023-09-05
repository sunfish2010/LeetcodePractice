#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n);
        int left = 0;
        int right = n -1; 
        int i = n-1;
        while(left <=right){
            if(abs(nums[left])  >= abs(nums[right])){
                results[i] = nums[left] * nums[left];
                left++;
            }else{
                results[i] = nums[right] * nums[right];
                right--;
            }
            i--;
        }
        return results;
        
    }
};