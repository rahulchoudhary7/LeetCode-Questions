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
    
    int getLength(ListNode* head){
        int count =0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        int n = getLength(head);
        
//         if(k==1){
//             ListNode* dummy = new ListNode(-1);
//             ListNode* curr = head;
//             ListNode* prev = head;
//             while(curr->next){
//                 prev = curr;
//                 curr = curr->next;
//             }
//             ListNode* temp = head->next;
//             dummy->next = curr;
//             curr->next = temp;
//             prev->next = head;
//             head->next = NULL;
//             return dummy->next;
            
//         }
        
        ListNode* kBeg = NULL;
        
        ListNode* kEnd = NULL;
        int s, e;
        
        int count = 0;
        ListNode* curr = head;
        
        while(curr){
            count++;
            if(count==k){
                s = curr->val;
                kBeg = curr;
            }
            if(count == n-k+1){
                e = curr->val;
                kEnd = curr;
            }
            
            curr = curr->next;
        }
        
        kBeg->val = e;
        kEnd->val = s;
        
        return head;
    }
};