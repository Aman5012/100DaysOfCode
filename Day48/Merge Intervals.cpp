56. Merge Intervals

//QUESTION LNK: https://leetcode.com/problems/merge-intervals/description/

TOPIC: Sorting

CODE:
// TC: O(n)
// SC: O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            // when intervals are not overlapping or ans is impty
            if(ans.empty() || ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
