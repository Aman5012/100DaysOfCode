700. Search in a Binary Search Tree

//QUESTION LINK: https://leetcode.com/problems/search-in-a-binary-search-tree/

TOPIC: Tree
Binary Search Tree
Binary Tree


CODE:
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

 /////////////////   recursive solution  ////////////////
// TC: O(n)
// SC: O(H)

class Solution {
public:
    TreeNode* solve(TreeNode* root, int val){
        if(!root) return NULL;
        if(root->val== val) return root;

        TreeNode* left = solve(root->left, val);
            if (left) return left;

        TreeNode* right = solve(root->right, val);
            return right; 

    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        return solve(root, val);
    }
};

///////////////////////   iterative solution //////////////////////
// TC: O(H)
// SC: O(1)

class Solution {
public:
    
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;

        while(root!=nullptr && root->val !=val){
            if(root->val > val){
                root = root->left;
            }else if( root->val < val) root = root->right;
        }
        return root;
    }
};
