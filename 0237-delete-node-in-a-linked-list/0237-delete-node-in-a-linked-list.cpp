/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* next = node->next;
        ListNode* next2next = node->next->next;
        
        swap(curr->val, next->val);
        
        next->next = NULL;
        curr->next = next2next;
        delete next;
    }
};