105. Construct Binary Tree from Preorder and Inorder Traversal

//QUESTION LINK: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

TOPIC: Array
Hash Table
Divide and Conquer
Tree
Binary Tree


CODE:
// Time Complexity: O(n)
// Space Complexity: O(n)

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;

        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]]=i;
        }

        int preIndex = 0;
        return build(preorder, inorder, mpp, preIndex, 0, preorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& mpp, int& preIndex, int s, int e){
        if(s>e) return nullptr;
            // pick the root value from preorder
        int rootVal = preorder[preIndex++];
            // creating new node
        TreeNode* root = new TreeNode(rootVal);
        

        int index = mpp[rootVal];

        root->left = build(preorder, inorder, mpp, preIndex, s, index-1);
        root->right = build(preorder, inorder, mpp, preIndex, index+1, e);
        return root;
    }
};
