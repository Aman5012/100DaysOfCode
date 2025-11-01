230. Kth Smallest Element in a BST
//QUESTION LINK: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> maxHeap; // keep the maximum element at the top and smallest element at lowest;
        fillHeap(root, maxHeap);

        while(maxHeap.size()>k) maxHeap.pop();
        return maxHeap.top();
    }
    void fillHeap(TreeNode* root,priority_queue<int> &maxHeap){
        if(!root) return;
        maxHeap.push(root->val);
        fillHeap(root->left, maxHeap);
        fillHeap(root->right, maxHeap);
    }
};
