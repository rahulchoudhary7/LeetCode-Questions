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
    ListNode* newLL(ListNode* &head, ListNode* &dummy){
        ListNode* prev = NULL;
        ListNode* fwd = NULL;
        
        ListNode* curr = head;
        ListNode* newCurr = dummy;
        while(curr){
            
            ListNode* temp = new ListNode(curr->val);
            newCurr->next = temp;
            newCurr = temp;
            
            curr = curr->next;
        }
        return reverse(dummy->next);
    }
    
    ListNode* reverse(ListNode* & head){
        ListNode* prev = NULL;
        ListNode* fwd = NULL;
        
        ListNode* curr = head;
        while(curr){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
       
        
//         vector<int> LL;
//         while(curr){
//             LL.push_back(curr->val);
//             curr = curr->next;
//         }
        
//         int maxi = INT_MIN;
        
//         int i = 0; 
//         int j = LL.size() -1;
        
//         while(i<j){
//             int twinSum = LL[i++]+LL[j--];
//             maxi = max(maxi, twinSum);
//         }
//         return maxi;
        
        int maxTwinSum = INT_MIN;
        
        
        ListNode* curr = head;
        
//         ListNode* fast = head->next;
//         ListNode* slow = head;
        
//         while(fast && fast->next){
//             fast = fast->next->next;
//             slow = slow->next;
//         }
        ListNode* dummy = new ListNode(-1);
        
        ListNode* rCurr = newLL(head, dummy);
        
        
        while(curr && rCurr){
            int sum = curr->val + rCurr->val;
            maxTwinSum = max(sum, maxTwinSum);
            
            curr = curr->next;
            rCurr = rCurr->next;
        }
        
        
        
        
        return maxTwinSum;
        
        
    }
};