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
private:
    
    int maxi = INT_MIN;
    ListNode* front = NULL;
    
    void maX(ListNode* head){
        if(head){
            maX(head->next);
            maxi = max(maxi, head->val + front->val);
            front = front->next;
        }
    }
public:
    int pairSum(ListNode* head) {
        front = head;
        maX(head);
        return maxi;
    }
};