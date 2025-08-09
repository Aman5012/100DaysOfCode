142. Linked List Cycle II
//QUESTION LNK: https://leetcode.com/problems/linked-list-cycle-ii/

TOPIC: Hash Table
Linked List
Two Pointers


CODE:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  TC: O(n)
//  SC: o(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next== NULL ) return NULL;
        ListNode* slow =head;
        ListNode* fast =head;
        ListNode* entry =head;

        while(fast->next &&  fast->next->next){
            slow= slow->next;
            fast = fast->next->next;
            
                if(slow == fast){            // there is cycle
                    while(slow!= entry){    // found entry point
                        slow=slow->next;
                        entry = entry->next;
                    }
                    return entry;
                }
            }
        return NULL;
    }
};
