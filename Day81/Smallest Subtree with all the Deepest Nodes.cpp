865. Smallest Subtree with all the Deepest Nodes
//QUESTION LINK: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/?envType=daily-question&envId=2026-01-09

TOPIC: Hash Table
Tree
Depth-First Search
Breadth-First Search
Binary Tree


CODE:
// TC: O(n)
// SC: O(1)
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
    pair<TreeNode*, int> solve(TreeNode* root){
        if(!root) return {nullptr, 1};

        auto leftSide = solve(root->left);
        auto rightSide = solve(root->right);

        if(leftSide.second == rightSide.second) return {root, leftSide.second + 1};
        
        if(leftSide.second > rightSide.second) return {leftSide.first, leftSide.second + 1};  
        return {rightSide.first, rightSide.second + 1};  
    }
    
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).first;
    }
};
