3025. Find the Number of Ways to Place People I
//QUESTION LINK: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/?envType=daily-question&envId=2025-09-02

TOPIC: Array
Math
Geometry
Sorting
Enumeration


CODE:
// TC: O(n^3)
// SC: O(1)

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        // upper left 
        for(int a=0; a<n; a++){
            int x1 = points[a][0];
            int y1 = points[a][1];
            for(int b=0; b<n; b++){
                if(a==b) continue;

                int x2 = points[b][0];
                int y2 = points[b][1];
                if(x1<= x2 && y1>= y2){
                    bool inside = false;
                    for(int k=0; k<n; k++){
                        if(k==a || k==b) continue;

                        int x3 = points[k][0];
                        int y3 = points[k][1];
                        if(x3<=x2 && y3>=y2 && x3>=x1 && y3<=y1){
                            inside = true;
                            break;
                        }
                    }
                    if(!inside) {
                        ans++;
                    }
                } 
            }
        }
        return ans;
    }
};
