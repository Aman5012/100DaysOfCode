898. Bitwise ORs of Subarrays
//QUESTION LNK: https://leetcode.com/problems/bitwise-ors-of-subarrays/description/?envType=daily-question&envId=2025-07-31

TOPIC: Array
Dynamic Programming
Bit Manipulation



CODE:

Time Complexity: O(n)
Space Complexity: O(n)
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> pre;
        unordered_set<int> curr;
        unordered_set<int> res;
        int n= arr.size();

        for(int i=0; i<n; i++){
            for(const int &x: pre){
                curr.insert(arr[i]|x);
                res.insert(arr[i]|x);

            }
            // insert arr[i];
            curr.insert(arr[i]);
            res.insert(arr[i]);

            pre= curr;
            curr.clear();
        }
        return res.size();
    }
};
