1792. Maximum Average Pass Ratio
//QUESTION LINK: https://leetcode.com/problems/maximum-average-pass-ratio/?envType=daily-question&envId=2025-09-01

TOPIC: Array
Greedy
Heap (Priority Queue)


CODE:
// TC: O(n)
// SC: O(n)
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        // Max-heap stores {gain, index}
        priority_queue<pair<double, int>> maxheap;

        // Step 1: Push initial gain for each class
        for(int i = 0; i < n; i++) {
            double pass = classes[i][0], total = classes[i][1];
            double newGain = (double(pass+1) / (total+1)) - (double(pass) / total);
            maxheap.push({newGain, i});
        }

        // Step 2: Distribute students
        while(extraStudents > 0) {
            int key = maxheap.top().second;
            maxheap.pop();

            // Add 1 student
            classes[key][0] += 1;
            classes[key][1] += 1;

            double pass = classes[key][0], total = classes[key][1];
            double newGain = (double(pass+1) / (total+1)) - (double(pass) / total);

            maxheap.push({newGain, key});
            extraStudents--;
        }

        // Step 3: Calculate final average
        double totalRatio = 0.0;
        for(int i=0; i<n; i++) {
            totalRatio += (double)classes[i][0] / classes[i][1];
        }

        return totalRatio / n;
    }
};

