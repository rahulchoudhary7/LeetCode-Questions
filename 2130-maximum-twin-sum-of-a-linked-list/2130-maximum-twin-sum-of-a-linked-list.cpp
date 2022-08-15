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
    int pairSum(ListNode* head) {
        ListNode* curr = head;
        vector<int> LL;
        while(curr){
            LL.push_back(curr->val);
            curr = curr->next;
        }
        
        int maxi = INT_MIN;
        
        int i = 0; 
        int j = LL.size() -1;
        
        while(i<j){
            int twinSum = LL[i++]+LL[j--];
            maxi = max(maxi, twinSum);
        }
        return maxi;
    }
};