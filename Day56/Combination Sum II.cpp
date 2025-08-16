40. Combination Sum II
//QUESTION LNK: https://leetcode.com/problems/combination-sum-ii/

TOPIC: Array
Backtracking


CODE:
///////////////////////////////   backtracking  ////////////////////////////////////////
// TC: O(NlogN+2^n . n)
// Space Complexity: O(N+K⋅N)
class Solution {
public:

    void solve(vector<int>& candidates,int target, int index,   vector<vector<int>>& res, vector<int> temp){
        if(target==0){
            res.push_back(temp);
            return;
        }
        // if(target<0 || index>= candidates.size()) return;

             for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates at the same recursion level
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break; // prune large numbers
            temp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, res, temp);
            temp.pop_back();
        }
        

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        solve(candidates, target, 0, res, temp);
        return res;

    }
};


/////////////////////////////////////    recursion   ///////////////////////////////////////////
// Time Complexity: O(2^n × n log n)
// Space Complexity: O(2^n × n)

class Solution {
public:

    void solve(vector<int>& candidates,int target, int index, set<vector<int>>& subset, vector<int> temp){
        if(target==0){
            vector<int> temp1= temp;
            sort(temp1.begin(), temp1.end());
            subset.insert(temp1);
            return;
        }
        if(target<0 || index>= candidates.size()) return;

        temp.push_back(candidates[index]);
        solve(candidates, target-candidates[index], index+1, subset, temp);
        temp.pop_back();
        solve(candidates, target, index+1, subset, temp);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> subset;
        vector<int> temp;
        solve(candidates, target, 0, subset, temp);
        return vector<vector<int>>(subset.begin(), subset.end());

    }
};
