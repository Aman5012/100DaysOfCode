1578. Minimum Time to Make Rope Colorful

//QUESTION LINK: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/?envType=daily-question&envId=2025-11-03

// TOPIC: Array
// String
// Dynamic Programming
// Greedy


CODE:
// TC: O(n)
// SC: O(1)

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
 
        int ans=0;
        int i=0;
        while(i<n){
            int s=i;
            int end=i;
            int maxi=0;

            while(end <n && colors[s]== colors[end]){
                ans += neededTime[end];
                maxi=max(maxi, neededTime[end]);
                end++;
            }
            i=end;
            ans -=maxi;
            
        }
        return ans;
    }
};

