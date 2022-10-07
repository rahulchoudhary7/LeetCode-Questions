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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* kBeg = head, *kEnd = head, *kth = NULL;
        
        while(--k) kBeg = kBeg->next;
        
        kth = kBeg;
        
        kBeg = kBeg->next;
        while(kBeg){
            kEnd = kEnd->next;
            kBeg = kBeg->next;
        }
        
        swap(kth->val, kEnd->val);
        
        return head;
    }
};