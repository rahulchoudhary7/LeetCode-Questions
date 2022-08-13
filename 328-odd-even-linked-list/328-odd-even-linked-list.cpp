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


// ListNode* dummy = new ListNode(-1);
//         ListNode* odd = dummy;
//         odd->next = head;
//         ListNode* curr = head;
//         ListNode* even = new ListNode(-1);
        
//         if(head->val & 1){
//             odd = curr;
//             curr = curr->next;
//         }
        
//         while(curr){
//             if(curr->val & 1){
//                 ListNode* next = curr->next;
//                 curr->next = odd->next;
//                 odd->next = curr;
//                 odd = curr;
//                 even->next = next;
//                 curr = next;
//             }
//             else{
//                 even = curr;
//                 curr = curr->next;
//             }
//         }
//         return dummy->next;
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        int count = 2;
        ListNode* curr = head->next;
        
        while(curr){
            if(count & 1){
                ListNode* nextNode = curr->next;
                curr->next = odd->next;
                odd->next = curr;
                odd = curr;
                even->next = nextNode;
                even = nextNode;
                curr = nextNode;
            }
            
            else {
               curr = curr->next;
            }
            count++;
        }
        
        return head;
    }
};