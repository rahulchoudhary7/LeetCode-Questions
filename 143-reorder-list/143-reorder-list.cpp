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
    void reorderList(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        stack<ListNode*> s;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* curr= slow->next;
        slow->next = NULL;
        
        while(curr){
            s.push(curr);
            curr = curr->next;
        }
        
        curr = head;
        
        while(!s.empty()){
            ListNode* temp = curr->next;
            ListNode* last = s.top();
            s.pop();
            curr->next = last;
            last->next = temp;
            curr = temp;
        }
    }
};