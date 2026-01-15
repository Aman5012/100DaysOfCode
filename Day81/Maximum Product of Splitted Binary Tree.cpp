339. Maximum Product of Splitted Binary Tree
//QUESTION LINK: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/?envType=daily-question&envId=2026-01-07

TOPIC: Tree
Depth-First Search
Binary Tree


CODE:
// TC: O(n)
// SC: O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int MOD = 1e9+7;

    vector<long long> subtreeSums;
    long long calculateSubtreeSums(TreeNode* root) {
        if (!root) return 0;

        long long leftSum = calculateSubtreeSums(root->left);
        long long rightSum = calculateSubtreeSums(root->right);
        
        long long currentSum = root->val + leftSum + rightSum;
        subtreeSums.push_back(currentSum);
        
        return currentSum; // final return will be the totalSum of the tree
    }

    int maxProduct(TreeNode* root) {
        subtreeSums.clear();
        
        long long totalSum = calculateSubtreeSums(root);
        // maxProduct  = s*(S-s)
        long long maxProd = 0;
        
        
        for (long long s : subtreeSums) {
            long long currentProduct = s * (totalSum - s);
            if (currentProduct > maxProd) {
                maxProd = currentProduct;
            }
        }
        return (int)(maxProd % MOD);
    }
};
