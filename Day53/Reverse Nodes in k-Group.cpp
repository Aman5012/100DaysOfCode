25. Reverse Nodes in k-Group

//QUESTION LNK: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

TOPIC: Linked List
Recursion


CODE:


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


//  TC: O(n)
//  SC: O(n/k)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur =head;
        // base case
        int count =0;
        while(cur!=NULL){
            count++;
            cur= cur->next;
        }
        if(head== NULL || k> count) return head;

        cur =head;
        ListNode* nex = cur->next;
        ListNode* pre =nullptr;
        int z=k;
        while(z>0){
            cur->next =pre;
            pre =cur;
            cur =nex;
            if(nex!=NULL)nex = nex->next;
            z--;
        }
        head ->next=reverseKGroup(cur, k);
        return pre;
    }
};
