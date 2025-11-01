1008. Construct Binary Search Tree from Preorder Traversal
//QUESTION LINK: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

TOPIC: Array
Stack
Tree
Binary Search Tree
Monotonic Stack
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
 
 //////////////////   recursive appraoch  /////////////////////////
//  TC: O(n)
//  SC: O(h)

class Solution {
public:
    int idx=0; 
    TreeNode* build(vector<int>& preorder, int low, int high){
        if(idx >= preorder.size()) return nullptr;

        int val = preorder[idx];
        if(val <low || val>high) return nullptr;

        TreeNode* node =new TreeNode(val);
        idx++;

        node->left = build(preorder, low, val-1);
        node->right = build(preorder, val+1, high);

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MIN, INT_MAX);
    }
};

////////////////////////// using  satck ////////////////////////////
//  TC: O(n)
//  SC: O(h)

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);

        for(int i=1; i<preorder.size(); i++){
            TreeNode* node = new TreeNode(preorder[i]);

            if(preorder[i]< st.top()->val){
                st.top()->left = node;
            }else{
                TreeNode* parent = st.top();

                while(!st.empty() && preorder[i]> st.top()->val){
                    parent = st.top();
                    st.pop();
                }
                parent ->right = node;
            }
            st.push(node);
        }
        return root;
    }
};
