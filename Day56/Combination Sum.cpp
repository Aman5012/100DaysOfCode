39. Combination Sum
//QUESTION LNK: https://leetcode.com/problems/combination-sum/

TOPIC: Array
Backtracking


CODE:
////////////////////////////  backtracking   //////////////////////////////////////
// TC: O(N^T⋅klogk)
// SC: O(n)
class Solution {
public:
    void solve(vector<int>& candidates, int target, int index, vector<vector<int>>& res, vector<int> temp){

            if(target == 0){
                sort(temp.begin(), temp.end());
                res.push_back(temp);
            }
            if(target<0) return ;

            for(int i= index; i<candidates.size(); i++){
                temp.push_back(candidates[i]);
                solve(candidates, target - candidates[i], i, res, temp); // repeat the same candidates
                temp.pop_back(); // undo the i-th candidates 
            }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int> temp;
        
        solve(candidates, target, 0, res, temp);
        return res;
        
    }
};


///////////////////////////////////////   recursion   ////////////////////////////
Time Complexity: O(2^N + M * K log K)
Space Complexity: O(T + M * K)
class Solution {
public:
    void solve(vector<int>& candidates, int target, int index, set<vector<int>>& subset, vector<int>& temp){
        
        if(target==0){

            vector<int> temp1= temp;
            sort(temp1.begin(), temp1.end());
            subset.insert(temp1);
            return;
        }
        if(target<0 || index >= candidates.size()) return;

        temp.push_back(candidates[index]);
        solve(candidates, target - candidates[index], index, subset, temp);  // recursive call for same candidate
        temp.pop_back();
        solve(candidates, target, index+1, subset, temp);  //  recursive call for next condidate 
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> subset;
        vector<int> temp;
        
        solve(candidates, target,0, subset, temp);
        return vector<vector<int>>(subset.begin(), subset.end());
        
    }
};
