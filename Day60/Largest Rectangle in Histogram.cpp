84. Largest Rectangle in Histogram
//QUESTION LINK: https://leetcode.com/problems/largest-rectangle-in-histogram/

TOPIC: Array
Stack
Monotonic Stack


CODE:
////////////////////////////////  brute force   ///////////////////
// TC: O(n²)
// SC: O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Left smaller
        vector<int> preLeftmin(n, -1);
        for (int i = 0; i < n; i++) {
            int mini = i - 1;
            while (mini >= 0) {
                if (heights[mini] < heights[i]) {
                    preLeftmin[i] = mini;
                    break;
                }
                mini--;
            }
        }

        // Right smaller
        vector<int> prerightmin(n, n);
        for (int i = 0; i < n; i++) {
            int mini = i + 1;
            while (mini < n) {
                if (heights[mini] < heights[i]) {
                    prerightmin[i] = mini;
                    break;
                }
                mini++;
            }
        }

        // Debug print
        for (int i = 0; i < n; i++) cout << preLeftmin[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++) cout << prerightmin[i] << " ";
        cout << endl;

        // Calculate area
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (prerightmin[i] - preLeftmin[i] - 1));
        }

        return ans;
    }
};

///////////////////////  optimal approach using stack ////////////////////
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]); // sentinel at end
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int left = (st.empty() ? -1 : st.top());
                int width = i - left - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};
