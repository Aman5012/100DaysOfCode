2300. Successful Pairs of Spells and Potions
//QUESTION LINK: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

TOPIC: Array
Two Pointers
Binary Search
Sorting


CODE:
/////////////////////////  brute force   ///////////////////
// TC: O(n.n)
// SC: O(n)

class Solution {
public:

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n =spells.size();
        int m =potions.size();
        vector<int> ans;

        for(auto x: spells){
            int count=0;
            for(auto y: potions){
                if((1ll * x * y)>= success) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};

/////////////////////////////   optimal appraoch (using lower lound) / //////////
// TC: O(n log m)
// SC: O(n)

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int m =potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(auto x: spells){
            // value from where we get success after that in sorted arr of potions
            long long need = (success + x-1)/ x;
            // getting the starting index from where we getting success 
            int idx = lower_bound(potions.begin(), potions.end(), need) - potions.begin();
            ans.push_back(m-idx);
        }
        return ans;
    }
};
