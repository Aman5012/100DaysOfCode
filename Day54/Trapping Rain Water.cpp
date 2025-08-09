42. Trapping Rain Water
//QUESTION LNK: https://leetcode.com/problems/trapping-rain-water/

TOPIC: Array
Two Pointers
Dynamic Programming
Stack
Monotonic Stack


CODE:
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
        int total=0;
        vector<int> rMax(n);
        rMax[n-1]= height[n-1];
        // creating arr which store the maxi height of the building towards right of that i-th building 
        for(int i=n-2; i>=0; i--){
            rMax[i] = max(rMax[i+1], height[i]);
        }
        vector<int> lMax(n);
        lMax[0]=height[0];
        // creating arr which store the maxi height of the building towards left of that i-th building
        for(int i=1;i<n; i++){
            lMax[i] = max(lMax[i-1], height[i]);
        }

        for(int i=0; i<n; i++){
            // water will trap above the building if -
            if(height[i]<lMax[i] && height[i]<rMax[i]){
                total +=min(lMax[i], rMax[i]) - height[i];
            }
        }
        return total;
    }
};
