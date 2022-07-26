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
    int getSize(ListNode* head){
        auto temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head);
        ListNode* curr = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        dummy->next = head;
        int count = 1;
        while(curr){
            count++;
            if(count == size - n + 2){
                ListNode* fwd = curr->next;
                prev->next = fwd;
                curr->next = NULL;
                delete curr;
                break;
            }
            prev = curr;
            curr = curr->next;
            
        }
        return dummy->next;
    }
};