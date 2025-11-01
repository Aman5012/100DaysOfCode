653. Two Sum IV - Input is a BST
//QUESTION LINK: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

TOPIC: Hash Table
Two Pointers
Tree
Depth-First Search
Breadth-First Search
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
class Solution {
public:
    void solve(TreeNode* root, vector<int>& v){
        if(!root) return;
        solve(root->left, v);
        v.push_back(root->val);
        solve(root->right, v);
    }
    bool inorder(TreeNode* root, int k){
        vector<int> v;
        bool find = false;
        solve(root, v);
        int s=0;
        int e= v.size()-1;

        while(e>s){
            int sum= v[s] + v[e];
            if(sum==k){
                find= true;
                break;
            } 
            else if(sum>k) e--;
            else s++;
        }
        return find;
    }
    bool findTarget(TreeNode* root, int k) {
        return inorder(root, k);
    }
};
