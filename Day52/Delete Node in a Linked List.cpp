237. Delete Node in a Linked List
//QUESTION LNK: https://leetcode.com/problems/delete-node-in-a-linked-list/

TOPIC: Linked List


CODE:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 
//  TC:O(1)
//  sC:O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* nodeToDelete = node->next;
        node->next = node->next->next;
        delete nodeToDelete;
    }
};
