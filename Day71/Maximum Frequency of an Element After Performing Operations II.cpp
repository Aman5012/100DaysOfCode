3347. Maximum Frequency of an Element After Performing Operations II
//QUESTION LINK: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/?envType=daily-question&envId=2025-10-22

// TOPIC: Array
// Binary Search
// Sliding Window
// Sorting
// Prefix Sum


CODE:
// TC: O(n log n)
// sc: O(n)

using ll=long long;
class Solution {
private:
    ll bs(vector<int>& nums, ll l) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= l) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

public:
    int maxFrequency(vector<int>& nums, int K, int numOperations) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        sort(nums.begin(), nums.end());

        ll k=K;
        unordered_set<ll> st;
        for(int val:nums){
            st.insert(val);
            st.insert(val-k);
            st.insert(val+k);
        }

        ll maxFreq = 0;
        for (ll target:st) {

            ll l= max(0LL, target - k);
            ll r = min(1LL*maxi, target + k);

            ll upperCnt = upper_bound(begin(nums), end(nums), r) - begin(nums);
            ll lowerCnt = bs(nums, l);

            ll count = upperCnt - lowerCnt;

            ll upperCntTarget =upper_bound(begin(nums), end(nums), target) - begin(nums);
            ll lowerCntTarget = bs(nums, target);
            ll targetFreq = upperCntTarget - lowerCntTarget;

            ll needToConvert = min(count - targetFreq, 1LL*numOperations);
            ll freqInc = targetFreq + needToConvert;

            maxFreq = max(maxFreq, freqInc);
        }

        return maxFreq;
    }
};
