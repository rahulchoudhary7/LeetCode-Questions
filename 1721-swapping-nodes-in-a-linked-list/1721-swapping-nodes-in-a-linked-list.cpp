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
        
        ListNode* kBeg = NULL;
        
        ListNode* kEnd = NULL;
        
        int count = 0;
        ListNode* curr = head;
        
        while(curr){
            count++;
            if(count==k){
                // s = curr->val;
                kBeg = curr;
            }
            if(count == n-k+1){
                // e = curr->val;
                kEnd = curr;
            }
            
            curr = curr->next;
        }
        swap(kBeg->val, kEnd->val);
        
        
        return head;
    }
};