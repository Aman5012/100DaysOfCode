11. Container With Most Wate
//QUESTION LINK: https://leetcode.com/problems/container-with-most-water/?envType=daily-question&envId=2025-10-04

TOPIC: Array
Two Pointers
Greedy


CODE:
///////////////////////  brute force (TLE)  /////////////////////

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int n = height.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int len = (j-i);
                int width = min(height[i], height[j]);
                maxArea = max(maxArea, len* width); 
            }
        }
        return maxArea;
    }
};

///////////////// Tow pointer apprach (Optimal solution)  ///////////////
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int n = height.size();
        int left = 0;
        int right=n-1;

        while(left<right){
            int len = right - left;
            int width = min(height[right], height[left]);
            maxArea = max(maxArea, len* width);
            if(height[left] < height[right]) left++;
            else right--;
        }
        
        return maxArea;
    }
};
