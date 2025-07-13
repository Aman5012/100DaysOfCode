79. K-th Symbol in Grammar
//QUESTION LNK: https://leetcode.com/problems/k-th-symbol-in-grammar/description/

TOPIC: recurtion


CODE:

// Time Complexity: O(n)
// Space Complexity: O(n)


class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1 && k == 1) return 0;

        int mid = 1 << (n - 2); // mid = 2^(n-1) / 2

        if (k <= mid)
            return kthGrammar(n - 1, k);
        else
            return 1 - kthGrammar(n - 1, k - mid);
    }
};

