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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        ListNode* dummy = new ListNode(-101);
        dummy->next = head;
        ListNode* prev = dummy;
        
        int count = 0;
        ListNode* curr = head;
        ListNode* lastNode = NULL;
        while(curr){
            count++;
            lastNode = curr;
            curr = curr->next;
        }
        k = k%count;
        if(count == k || count ==1 || k == 0) return head;
        int shift = (abs(count - k));
        int newCount = 0;
        curr = head;
        while(curr){
            newCount++;
            if(newCount==shift)
                break;
            curr = curr->next;
        }
        
        if(curr){
            ListNode* newHead = curr->next;
            prev->next = newHead;
        }
        curr->next = NULL;
        lastNode->next = head;
        
        
        return dummy->next;
    }
};