3439. Reschedule Meetings for Maximum Free Time I

//QUESTION LNK: 

// TOPIC:Array: Sliding Window Greedy

// CODE:

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        freeTime.push_back(startTime[0]);
        for(int i=1; i< endTime.size(); i++){
            freeTime.push_back(startTime[i] - endTime[i-1]);
        }
        freeTime.push_back(eventTime - endTime.back());

        // Sliding window for max sum of k+1 free slots
        int windowSum = 0;
        for (int i = 0; i <= k; i++) {
            windowSum += freeTime[i];
        }

        int maxSum = windowSum;

        for (int i = k + 1; i < freeTime.size(); i++) {
            windowSum += freeTime[i] - freeTime[i - k - 1];
            maxSum = max(maxSum, windowSum);
        }
        return maxSum;
    }
};
