1266. Minimum Time Visiting All Points
//QUESTION LINK: https://leetcode.com/problems/minimum-time-visiting-all-points/?envType=daily-question&envId=2026-01-12

TOPIC: Array
Math
Geometry


CODE:

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int time = 0;
        if (n <= 1) return 0;

        for (int i = 0; i < n - 1; i++) {
            int p1x = points[i][0];
            int p1y = points[i][1];

            int p2x = points[i+1][0];
            int p2y = points[i+1][1];

            // 1. Handle Diagonal Movement first
            if (p1x != p2x && p1y != p2y) {
                if (p2x < p1x && p2y < p1y) {
                    while (p1x != p2x && p1y != p2y) {
                        p1x--; p1y--; time++;
                    }
                } else if (p2x < p1x && p2y > p1y) {
                    while (p1x != p2x && p1y != p2y) {
                        p1x--; p1y++; time++;
                    }
                } else if (p2x > p1x && p2y > p1y) {
                    while (p1x != p2x && p1y != p2y) {
                        p1x++; p1y++; time++;
                    }
                } else if (p2x > p1x && p2y < p1y) {
                    while (p1x != p2x && p1y != p2y) {
                        p1x++; p1y--; time++;
                    }
                }
            }

            // 2. Handle remaining Horizontal or Vertical movement
            // After the diagonal steps, either p1x will match p2x OR p1y will match p2y
            if (p1x == p2x && p1y != p2y) {
                time += abs(p2y - p1y);
            } 
            else if (p1y == p2y && p1x != p2x) {
                time += abs(p2x - p1x);
            }
        }
        return time;
    }
};


///////////////////////////   approach 2 //////////////////////////////
class Solution {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        int totalTime = 0;
        
        for (size_t i = 0; i < points.size() - 1; ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[i + 1][0];
            int y2 = points[i + 1][1];
            

            totalTime += max(abs(x2 - x1), abs(y2 - y1));
        }
        
        return totalTime;
    }
};
