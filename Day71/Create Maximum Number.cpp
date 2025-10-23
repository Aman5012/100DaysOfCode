321. Create Maximum Number
//QUESTION LINK: https://leetcode.com/problems/create-maximum-number/

// TOPIC: Array
// Two Pointers
// Stack
// Greedy
// Monotonic Stack


CODE:
// TC: O(k³ + k(n1 + n2))
// SC: O(n1 + n2 + k)

class Solution {
public:

    vector<int> subSeq(vector<int> &nums, int t){
        vector<int> stk;
        int drop = nums.size()-t;

        for(int num: nums){
            while(!stk.empty() && drop>0 && stk.back()< num){
                stk.pop_back();
                drop--;
            }
            stk.push_back(num);

        }
        stk.resize(t); // kepp only t element 
        return stk;
    }
    vector<int> merge(vector<int>a, vector<int> b){
        vector<int> res;

        while(!a.empty() || !b.empty()){
            if(a>b) res.push_back(a[0]), a.erase(a.begin());  // merge legicographic order
            else res.push_back(b[0]), b.erase(b.begin());
        }
        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best;

        for(int i = max(0, k- (int)nums2.size()); i<=min(k, (int)nums1.size()); i++){
            vector<int> part2 = subSeq(nums2, k-i);
            vector<int> part1 = subSeq(nums1, i);
            vector<int> candidate = merge(part1, part2);

            best = max(best, candidate);  // lexicographic comparison
        }
        return best;
    }
};
