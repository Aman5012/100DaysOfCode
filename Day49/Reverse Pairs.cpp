493. Reverse Pairs
//QUESTION LNK: https://leetcode.com/problems/reverse-pairs/description/

// TOPIC: Array
// Binary Search
// Divide and Conquer
// Binary Indexed Tree
// Segment Tree
// Merge Sort
// Ordered Set


CODE:


//////////////////    brute force  ////////
// TC: O(n.n)
// SC: O(1)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        for(int i=0; i<n; i++){
            for(int j= i+1; j<n; j++){
                if(nums[i] > 2ll * nums[j]) count++;
            }
        }
        return count;
    }
};


/////////////////////  using merge sort  /////////////
// TC:O(n log n)
// SC:O(n)

class Solution {
public:
    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int mid = (low + high) / 2;
        int count = mergeSort(nums, low, mid) + mergeSort(nums, mid + 1, high);

        // Count reverse pairs
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge step
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
