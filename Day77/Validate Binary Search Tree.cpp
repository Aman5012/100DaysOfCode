98. Validate Binary Search Tree
//QUESTION LINK: https://leetcode.com/problems/validate-binary-search-tree/description/

// TOPIC: Tree
// Depth-First Search
// Binary Search Tree
// Binary Tree


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
 /////////////////////  recursive solution  //////////////////////
class Solution {
public:
    bool solve(TreeNode* root, long low, long high){
        if(root==NULL) return true;

        if(root->val<= low || root->val >= high) return false;


        return solve(root->left, low, root->val) && solve(root->right, root->val, high);

    }
    bool isValidBST(TreeNode* root) {
        

        return solve(root, LONG_MIN, LONG_MAX);
    }
};

/////////////////////////  iterative solution  ///////////////////////
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        while(root!=NULL){
        if(root->val > root->left ->val) {
            root= root-> left;
        }
        else if(root->val < root->right-> val ){
            root= root-> right;
        }else {
            return false;
        }

        }
        return true;
    }
};
