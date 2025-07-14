1122. Relative Sort Array
//QUESTION LNK: https://leetcode.com/problems/relative-sort-array/description/

TOPIC: array , sorting

CODE:

// Time Complexity: O(n log n)
// Space Complexity: O(n)

  class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freq;
        for(int num: arr1){
            freq[num]++;
        }
        vector<int> ans;
        // 1. add those element which are presetn in the arr2
        for(int f: arr2){
            while(freq[f]>0){
                ans.push_back(f);
                freq[f]--;
            }
        }
        // 2. Add the remaining elements which not in arr2, sorted
        vector<int> rest;
        for (auto [key, fr] : freq) {
            while (fr--) {
                rest.push_back(key);
            }
        }
        sort(rest.begin(), rest.end());
        
        // 3. Append remaining to result
        ans.insert(ans.end(), rest.begin(), rest.end());
        return ans;
    }
};
